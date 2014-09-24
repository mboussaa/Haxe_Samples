package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FFTElementEssentials extends haxe.lang.HxObject
{
	public    FFTElementEssentials(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    FFTElementEssentials()
	{
		haxe.root.FFTElementEssentials.__hx_ctor__FFTElementEssentials(this);
	}
	
	
	public static   void __hx_ctor__FFTElementEssentials(haxe.root.FFTElementEssentials __temp_me7)
	{
		__temp_me7.re = ((double) (0) );
		__temp_me7.im = ((double) (0) );
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.FFTElementEssentials(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.FFTElementEssentials();
	}
	
	
	public  double re;
	
	public  double im;
	
	public  int revTgt;
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef41 = true;
			switch (field.hashCode())
			{
				case -934369090:
				{
					if (field.equals("revTgt")) 
					{
						__temp_executeDef41 = false;
						this.revTgt = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3635:
				{
					if (field.equals("re")) 
					{
						__temp_executeDef41 = false;
						this.re = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 3364:
				{
					if (field.equals("im")) 
					{
						__temp_executeDef41 = false;
						this.im = ((double) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef41) 
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
			boolean __temp_executeDef42 = true;
			switch (field.hashCode())
			{
				case -934369090:
				{
					if (field.equals("revTgt")) 
					{
						__temp_executeDef42 = false;
						this.revTgt = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3635:
				{
					if (field.equals("re")) 
					{
						__temp_executeDef42 = false;
						this.re = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3364:
				{
					if (field.equals("im")) 
					{
						__temp_executeDef42 = false;
						this.im = ((double) (haxe.lang.Runtime.toDouble(value)) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef42) 
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
			boolean __temp_executeDef43 = true;
			switch (field.hashCode())
			{
				case -934369090:
				{
					if (field.equals("revTgt")) 
					{
						__temp_executeDef43 = false;
						return this.revTgt;
					}
					
					break;
				}
				
				
				case 3635:
				{
					if (field.equals("re")) 
					{
						__temp_executeDef43 = false;
						return this.re;
					}
					
					break;
				}
				
				
				case 3364:
				{
					if (field.equals("im")) 
					{
						__temp_executeDef43 = false;
						return this.im;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef43) 
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
			boolean __temp_executeDef44 = true;
			switch (field.hashCode())
			{
				case -934369090:
				{
					if (field.equals("revTgt")) 
					{
						__temp_executeDef44 = false;
						return ((double) (this.revTgt) );
					}
					
					break;
				}
				
				
				case 3635:
				{
					if (field.equals("re")) 
					{
						__temp_executeDef44 = false;
						return this.re;
					}
					
					break;
				}
				
				
				case 3364:
				{
					if (field.equals("im")) 
					{
						__temp_executeDef44 = false;
						return this.im;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef44) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("revTgt");
		baseArr.push("im");
		baseArr.push("re");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


