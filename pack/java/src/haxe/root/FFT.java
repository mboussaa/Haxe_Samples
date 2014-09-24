package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FFT extends haxe.lang.HxObject
{
	static 
	{
		haxe.root.FFT.FORWARD = false;
		haxe.root.FFT.INVERSE = true;
	}
	public    FFT(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    FFT()
	{
		haxe.root.FFT.__hx_ctor__FFT(this);
	}
	
	
	public static   void __hx_ctor__FFT(haxe.root.FFT __temp_me6)
	{
		{
		}
		
	}
	
	
	public static  boolean FORWARD;
	
	public static  boolean INVERSE;
	
	public static  <T> haxe.root.Array<T> newArray(java.lang.Object len, java.lang.Object fixed)
	{
		boolean __temp_fixed5 = ( (( fixed == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(fixed)) );
		int __temp_len4 = ( (( len == null )) ? (((int) (0) )) : (((int) (haxe.lang.Runtime.toInt(len)) )) );
		return new haxe.root.Array<T>();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.FFT(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.FFT();
	}
	
	
	public  int m_logN;
	
	public  int m_N;
	
	public  double m_invN;
	
	public  haxe.root.Array<haxe.root.FFTElement> m_X;
	
	public final   void init(int logN)
	{
		this.m_logN = logN;
		this.m_N = ( 1 << this.m_logN );
		this.m_invN = ( 1.0 / this.m_N );
		{
			boolean fixed = false;
			this.m_X = new haxe.root.Array<haxe.root.FFTElement>();
		}
		
		{
			int _g1 = 0;
			int _g = this.m_N;
			while (( _g1 < _g ))
			{
				int k = _g1++;
				this.m_X.__set(k, new haxe.root.FFTElement());
			}
			
		}
		
		{
			int _g11 = 0;
			int _g2 = ( this.m_N - 1 );
			while (( _g11 < _g2 ))
			{
				int k1 = _g11++;
				this.m_X.__get(k1).next = this.m_X.__get(( k1 + 1 ));
			}
			
		}
		
		{
			int _g12 = 0;
			int _g3 = this.m_N;
			while (( _g12 < _g3 ))
			{
				int k2 = _g12++;
				{
					int x = k2;
					int y = 0;
					{
						int _g4 = 0;
						while (( _g4 < ((int) (logN) ) ))
						{
							int i = _g4++;
							y <<= 1;
							y |= ( x & 1 );
							x >>= 1;
						}
						
					}
					
					this.m_X.__get(k2).revTgt = y;
				}
				
			}
			
		}
		
	}
	
	
	public final   void run(haxe.root.Array<java.lang.Object> xRe, haxe.root.Array<java.lang.Object> xIm, java.lang.Object inverse)
	{
		boolean __temp_inverse3 = ( (( inverse == null )) ? (haxe.lang.Runtime.toBool(false)) : (haxe.lang.Runtime.toBool(inverse)) );
		int numFlies = ( this.m_N >> 1 );
		int span = ( this.m_N >> 1 );
		int spacing = this.m_N;
		int wIndexStep = 1;
		haxe.root.FFTElement x = this.m_X.__get(0);
		int k = 0;
		double scale = 0.0;
		if (__temp_inverse3) 
		{
			scale = this.m_invN;
		}
		 else 
		{
			scale = 1.0;
		}
		
		while (( x != null ))
		{
			x.re = ( scale * ((double) (haxe.lang.Runtime.toDouble(xRe.__get(k))) ) );
			x.im = ( scale * ((double) (haxe.lang.Runtime.toDouble(xIm.__get(k))) ) );
			x = x.next;
			k++;
		}
		
		java.lang.Class math = java.lang.Math.class;
		{
			int _g1 = 0;
			int _g = this.m_logN;
			while (( _g1 < _g ))
			{
				int stage = _g1++;
				double wAngleInc = ( ( ( wIndexStep * 2.0 ) * java.lang.Math.PI ) / this.m_N );
				if ( ! (__temp_inverse3) ) 
				{
					wAngleInc *= ((double) (-1) );
				}
				
				double wMulRe = java.lang.Math.cos(wAngleInc);
				double wMulIm = java.lang.Math.sin(wAngleInc);
				int start = 0;
				while (( start < this.m_N ))
				{
					haxe.root.FFTElement xTop = this.m_X.__get(start);
					haxe.root.FFTElement xBot = this.m_X.__get(( start + span ));
					double wRe = 1.0;
					double wIm = 0.0;
					{
						int _g2 = 0;
						while (( _g2 < numFlies ))
						{
							int flyCount = _g2++;
							double xTopRe = xTop.re;
							double xTopIm = xTop.im;
							double xBotRe = xBot.re;
							double xBotIm = xBot.im;
							xTop.re = ( xTopRe + xBotRe );
							xTop.im = ( xTopIm + xBotIm );
							xBotRe = ( xTopRe - xBotRe );
							xBotIm = ( xTopIm - xBotIm );
							xBot.re = ( ( xBotRe * wRe ) - ( xBotIm * wIm ) );
							xBot.im = ( ( xBotRe * wIm ) + ( xBotIm * wRe ) );
							xTop = xTop.next;
							xBot = xBot.next;
							double tRe = wRe;
							wRe = ( ( wRe * wMulRe ) - ( wIm * wMulIm ) );
							wIm = ( ( tRe * wMulIm ) + ( wIm * wMulRe ) );
						}
						
					}
					
					start += spacing;
				}
				
				numFlies >>= 1;
				span >>= 1;
				spacing >>= 1;
				wIndexStep <<= 1;
			}
			
		}
		
		x = this.m_X.__get(0);
		while (( x != null ))
		{
			int target = x.revTgt;
			xRe.__set(target, x.re);
			xIm.__set(target, x.im);
			x = x.next;
		}
		
	}
	
	
	public final   int BitReverse(int x, int numBits)
	{
		int y = 0;
		{
			int _g = 0;
			while (( _g < ((int) (numBits) ) ))
			{
				int i = _g++;
				y <<= 1;
				y |= ( x & 1 );
				x >>= 1;
			}
			
		}
		
		return y;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef36 = true;
			switch (field.hashCode())
			{
				case -1083417841:
				{
					if (field.equals("m_invN")) 
					{
						__temp_executeDef36 = false;
						this.m_invN = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083327972:
				{
					if (field.equals("m_logN")) 
					{
						__temp_executeDef36 = false;
						this.m_logN = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 107772:
				{
					if (field.equals("m_N")) 
					{
						__temp_executeDef36 = false;
						this.m_N = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef36) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef37 = true;
			switch (field.hashCode())
			{
				case 107782:
				{
					if (field.equals("m_X")) 
					{
						__temp_executeDef37 = false;
						this.m_X = ((haxe.root.Array<haxe.root.FFTElement>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case -1083327972:
				{
					if (field.equals("m_logN")) 
					{
						__temp_executeDef37 = false;
						this.m_logN = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case -1083417841:
				{
					if (field.equals("m_invN")) 
					{
						__temp_executeDef37 = false;
						this.m_invN = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 107772:
				{
					if (field.equals("m_N")) 
					{
						__temp_executeDef37 = false;
						this.m_N = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef37) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef38 = true;
			switch (field.hashCode())
			{
				case -2117078731:
				{
					if (field.equals("BitReverse")) 
					{
						__temp_executeDef38 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("BitReverse"))) );
					}
					
					break;
				}
				
				
				case -1083327972:
				{
					if (field.equals("m_logN")) 
					{
						__temp_executeDef38 = false;
						return this.m_logN;
					}
					
					break;
				}
				
				
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef38 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("run"))) );
					}
					
					break;
				}
				
				
				case 107772:
				{
					if (field.equals("m_N")) 
					{
						__temp_executeDef38 = false;
						return this.m_N;
					}
					
					break;
				}
				
				
				case 3237136:
				{
					if (field.equals("init")) 
					{
						__temp_executeDef38 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("init"))) );
					}
					
					break;
				}
				
				
				case -1083417841:
				{
					if (field.equals("m_invN")) 
					{
						__temp_executeDef38 = false;
						return this.m_invN;
					}
					
					break;
				}
				
				
				case 107782:
				{
					if (field.equals("m_X")) 
					{
						__temp_executeDef38 = false;
						return this.m_X;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef38) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef39 = true;
			switch (field.hashCode())
			{
				case -1083417841:
				{
					if (field.equals("m_invN")) 
					{
						__temp_executeDef39 = false;
						return this.m_invN;
					}
					
					break;
				}
				
				
				case -1083327972:
				{
					if (field.equals("m_logN")) 
					{
						__temp_executeDef39 = false;
						return ((double) (this.m_logN) );
					}
					
					break;
				}
				
				
				case 107772:
				{
					if (field.equals("m_N")) 
					{
						__temp_executeDef39 = false;
						return ((double) (this.m_N) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef39) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef40 = true;
			switch (field.hashCode())
			{
				case -2117078731:
				{
					if (field.equals("BitReverse")) 
					{
						__temp_executeDef40 = false;
						return this.BitReverse(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
				case 3237136:
				{
					if (field.equals("init")) 
					{
						__temp_executeDef40 = false;
						this.init(((int) (haxe.lang.Runtime.toInt(dynargs.__get(0))) ));
					}
					
					break;
				}
				
				
				case 113291:
				{
					if (field.equals("run")) 
					{
						__temp_executeDef40 = false;
						this.run(((haxe.root.Array<java.lang.Object>) (dynargs.__get(0)) ), ((haxe.root.Array<java.lang.Object>) (dynargs.__get(1)) ), dynargs.__get(2));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef40) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("m_X");
		baseArr.push("m_invN");
		baseArr.push("m_N");
		baseArr.push("m_logN");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


