package haxe.root;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FFTTimingTest extends haxe.lang.HxObject
{
	public static void main(String[] args)
	{
		main();
	}
	static 
	{
		haxe.root.FFTTimingTest.LOG_N = 10;
		haxe.root.FFTTimingTest.N = 1024;
		haxe.root.FFTTimingTest.NUM_LOOPS = 1000;
		haxe.root.FFTTimingTest.PRECISION = .0001;
	}
	public    FFTTimingTest(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    FFTTimingTest()
	{
		haxe.root.FFTTimingTest.__hx_ctor__FFTTimingTest(this);
	}
	
	
	public static   void __hx_ctor__FFTTimingTest(haxe.root.FFTTimingTest __temp_me9)
	{
		__temp_me9.initTest();
		__temp_me9.print("Performing FFTs...");
		haxe.root.Array<java.lang.Object> xRe = null;
		{
			boolean fixed = false;
			xRe = new haxe.root.Array<java.lang.Object>();
		}
		
		haxe.root.Array<java.lang.Object> xIm = null;
		{
			boolean fixed1 = false;
			xIm = new haxe.root.Array<java.lang.Object>();
		}
		
		{
			int _g = 0;
			while (( _g < 1024 ))
			{
				int i = _g++;
				xRe.__set(i, java.lang.Math.cos(( ( ( ( 2 * java.lang.Math.PI ) * 2 ) * i ) / 1024 )));
				xIm.__set(i, 0.0);
			}
			
		}
		
		haxe.root.FFT fft = new haxe.root.FFT();
		{
			fft.m_logN = 10;
			fft.m_N = ( 1 << fft.m_logN );
			fft.m_invN = ( 1.0 / fft.m_N );
			{
				boolean fixed2 = false;
				fft.m_X = new haxe.root.Array<haxe.root.FFTElement>();
			}
			
			{
				int _g1 = 0;
				int _g2 = fft.m_N;
				while (( _g1 < _g2 ))
				{
					int k = _g1++;
					fft.m_X.__set(k, new haxe.root.FFTElement());
				}
				
			}
			
			{
				int _g11 = 0;
				int _g3 = ( fft.m_N - 1 );
				while (( _g11 < _g3 ))
				{
					int k1 = _g11++;
					fft.m_X.__get(k1).next = fft.m_X.__get(( k1 + 1 ));
				}
				
			}
			
			{
				int _g12 = 0;
				int _g4 = fft.m_N;
				while (( _g12 < _g4 ))
				{
					int k2 = _g12++;
					{
						int x = k2;
						int y = 0;
						{
							int _g5 = 0;
							while (( _g5 < ((int) (10) ) ))
							{
								int i1 = _g5++;
								y <<= 1;
								y |= ( x & 1 );
								x >>= 1;
							}
							
						}
						
						fft.m_X.__get(k2).revTgt = y;
					}
					
				}
				
			}
			
		}
		
		int startTime = 0;
		{
			double x1 = ( haxe.Timer.stamp() * 1000 );
			startTime = ((int) (x1) );
		}
		
		{
			int _g6 = 0;
			while (( _g6 < 1000 ))
			{
				int i2 = _g6++;
				{
					int numFlies = ( fft.m_N >> 1 );
					int span = ( fft.m_N >> 1 );
					int spacing = fft.m_N;
					int wIndexStep = 1;
					haxe.root.FFTElement x2 = fft.m_X.__get(0);
					int k3 = 0;
					double scale = 1.0;
					while (( x2 != null ))
					{
						x2.re = ( scale * ((double) (haxe.lang.Runtime.toDouble(xRe.__get(k3))) ) );
						x2.im = ( scale * ((double) (haxe.lang.Runtime.toDouble(xIm.__get(k3))) ) );
						x2 = x2.next;
						k3++;
					}
					
					java.lang.Class math = java.lang.Math.class;
					{
						int _g13 = 0;
						int _g7 = fft.m_logN;
						while (( _g13 < _g7 ))
						{
							int stage = _g13++;
							double wAngleInc = ( ( ( wIndexStep * 2.0 ) * java.lang.Math.PI ) / fft.m_N );
							wAngleInc *= ((double) (-1) );
							double wMulRe = java.lang.Math.cos(wAngleInc);
							double wMulIm = java.lang.Math.sin(wAngleInc);
							int start = 0;
							while (( start < fft.m_N ))
							{
								haxe.root.FFTElement xTop = fft.m_X.__get(start);
								haxe.root.FFTElement xBot = fft.m_X.__get(( start + span ));
								double wRe = 1.0;
								double wIm = 0.0;
								{
									int _g21 = 0;
									while (( _g21 < numFlies ))
									{
										int flyCount = _g21++;
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
					
					x2 = fft.m_X.__get(0);
					while (( x2 != null ))
					{
						int target = x2.revTgt;
						xRe.__set(target, x2.re);
						xIm.__set(target, x2.im);
						x2 = x2.next;
					}
					
				}
				
				{
					int numFlies1 = ( fft.m_N >> 1 );
					int span1 = ( fft.m_N >> 1 );
					int spacing1 = fft.m_N;
					int wIndexStep1 = 1;
					haxe.root.FFTElement x3 = fft.m_X.__get(0);
					int k4 = 0;
					double scale1 = fft.m_invN;
					while (( x3 != null ))
					{
						x3.re = ( scale1 * ((double) (haxe.lang.Runtime.toDouble(xRe.__get(k4))) ) );
						x3.im = ( scale1 * ((double) (haxe.lang.Runtime.toDouble(xIm.__get(k4))) ) );
						x3 = x3.next;
						k4++;
					}
					
					java.lang.Class math1 = java.lang.Math.class;
					{
						int _g14 = 0;
						int _g8 = fft.m_logN;
						while (( _g14 < _g8 ))
						{
							int stage1 = _g14++;
							double wAngleInc1 = ( ( ( wIndexStep1 * 2.0 ) * java.lang.Math.PI ) / fft.m_N );
							double wMulRe1 = java.lang.Math.cos(wAngleInc1);
							double wMulIm1 = java.lang.Math.sin(wAngleInc1);
							int start1 = 0;
							while (( start1 < fft.m_N ))
							{
								haxe.root.FFTElement xTop1 = fft.m_X.__get(start1);
								haxe.root.FFTElement xBot1 = fft.m_X.__get(( start1 + span1 ));
								double wRe1 = 1.0;
								double wIm1 = 0.0;
								{
									int _g22 = 0;
									while (( _g22 < numFlies1 ))
									{
										int flyCount1 = _g22++;
										double xTopRe1 = xTop1.re;
										double xTopIm1 = xTop1.im;
										double xBotRe1 = xBot1.re;
										double xBotIm1 = xBot1.im;
										xTop1.re = ( xTopRe1 + xBotRe1 );
										xTop1.im = ( xTopIm1 + xBotIm1 );
										xBotRe1 = ( xTopRe1 - xBotRe1 );
										xBotIm1 = ( xTopIm1 - xBotIm1 );
										xBot1.re = ( ( xBotRe1 * wRe1 ) - ( xBotIm1 * wIm1 ) );
										xBot1.im = ( ( xBotRe1 * wIm1 ) + ( xBotIm1 * wRe1 ) );
										xTop1 = xTop1.next;
										xBot1 = xBot1.next;
										double tRe1 = wRe1;
										wRe1 = ( ( wRe1 * wMulRe1 ) - ( wIm1 * wMulIm1 ) );
										wIm1 = ( ( tRe1 * wMulIm1 ) + ( wIm1 * wMulRe1 ) );
									}
									
								}
								
								start1 += spacing1;
							}
							
							numFlies1 >>= 1;
							span1 >>= 1;
							spacing1 >>= 1;
							wIndexStep1 <<= 1;
						}
						
					}
					
					x3 = fft.m_X.__get(0);
					while (( x3 != null ))
					{
						int target1 = x3.revTgt;
						xRe.__set(target1, x3.re);
						xIm.__set(target1, x3.im);
						x3 = x3.next;
					}
					
				}
				
			}
			
		}
		
		int endTime = 0;
		{
			double x4 = ( haxe.Timer.stamp() * 1000 );
			endTime = ((int) (x4) );
		}
		
		int elapsed = ( endTime - startTime );
		double timePerFFT = ( elapsed / 2000. );
		__temp_me9.print(( ( ( ( ( ( ( 1000 + " fwd-inv pairs of " ) + 1024 ) + " pt FFTs took " ) + elapsed ) + " ms, or " ) + haxe.lang.Runtime.toString(( ((double) (((int) (( timePerFFT * 1000 )) )) ) / 1000 )) ) + " ms per FFT." ));
		{
			haxe.root.Array<java.lang.Object> xRe1 = null;
			{
				boolean fixed3 = false;
				xRe1 = new haxe.root.Array<java.lang.Object>();
			}
			
			haxe.root.Array<java.lang.Object> xIm1 = null;
			{
				boolean fixed4 = false;
				xIm1 = new haxe.root.Array<java.lang.Object>();
			}
			
			haxe.root.Array<java.lang.Object> xRe2 = null;
			{
				boolean fixed5 = false;
				xRe2 = new haxe.root.Array<java.lang.Object>();
			}
			
			haxe.root.Array<java.lang.Object> xIm2 = null;
			{
				boolean fixed6 = false;
				xIm2 = new haxe.root.Array<java.lang.Object>();
			}
			
			{
				int _g9 = 0;
				while (( _g9 < 1024 ))
				{
					int i3 = _g9++;
					xRe1.__set(i3, ((double) (haxe.lang.Runtime.toDouble(xRe2.__set(i3, java.lang.Math.cos(( ( ( ( 2 * java.lang.Math.PI ) * 2 ) * i3 ) / 1024 ))))) ));
					xIm1.__set(i3, ((double) (haxe.lang.Runtime.toDouble(xIm2.__set(i3, 0.0))) ));
				}
				
			}
			
			haxe.root.FFT fft1 = new haxe.root.FFT();
			{
				fft1.m_logN = 10;
				fft1.m_N = ( 1 << fft1.m_logN );
				fft1.m_invN = ( 1.0 / fft1.m_N );
				{
					boolean fixed7 = false;
					fft1.m_X = new haxe.root.Array<haxe.root.FFTElement>();
				}
				
				{
					int _g15 = 0;
					int _g10 = fft1.m_N;
					while (( _g15 < _g10 ))
					{
						int k5 = _g15++;
						fft1.m_X.__set(k5, new haxe.root.FFTElement());
					}
					
				}
				
				{
					int _g16 = 0;
					int _g17 = ( fft1.m_N - 1 );
					while (( _g16 < _g17 ))
					{
						int k6 = _g16++;
						fft1.m_X.__get(k6).next = fft1.m_X.__get(( k6 + 1 ));
					}
					
				}
				
				{
					int _g18 = 0;
					int _g19 = fft1.m_N;
					while (( _g18 < _g19 ))
					{
						int k7 = _g18++;
						{
							int x5 = k7;
							int y1 = 0;
							{
								int _g20 = 0;
								while (( _g20 < ((int) (10) ) ))
								{
									int i4 = _g20++;
									y1 <<= 1;
									y1 |= ( x5 & 1 );
									x5 >>= 1;
								}
								
							}
							
							fft1.m_X.__get(k7).revTgt = y1;
						}
						
					}
					
				}
				
			}
			
			{
				int numFlies2 = ( fft1.m_N >> 1 );
				int span2 = ( fft1.m_N >> 1 );
				int spacing2 = fft1.m_N;
				int wIndexStep2 = 1;
				haxe.root.FFTElement x6 = fft1.m_X.__get(0);
				int k8 = 0;
				double scale2 = 1.0;
				while (( x6 != null ))
				{
					x6.re = ( scale2 * ((double) (haxe.lang.Runtime.toDouble(xRe1.__get(k8))) ) );
					x6.im = ( scale2 * ((double) (haxe.lang.Runtime.toDouble(xIm1.__get(k8))) ) );
					x6 = x6.next;
					k8++;
				}
				
				java.lang.Class math2 = java.lang.Math.class;
				{
					int _g110 = 0;
					int _g23 = fft1.m_logN;
					while (( _g110 < _g23 ))
					{
						int stage2 = _g110++;
						double wAngleInc2 = ( ( ( wIndexStep2 * 2.0 ) * java.lang.Math.PI ) / fft1.m_N );
						wAngleInc2 *= ((double) (-1) );
						double wMulRe2 = java.lang.Math.cos(wAngleInc2);
						double wMulIm2 = java.lang.Math.sin(wAngleInc2);
						int start2 = 0;
						while (( start2 < fft1.m_N ))
						{
							haxe.root.FFTElement xTop2 = fft1.m_X.__get(start2);
							haxe.root.FFTElement xBot2 = fft1.m_X.__get(( start2 + span2 ));
							double wRe2 = 1.0;
							double wIm2 = 0.0;
							{
								int _g24 = 0;
								while (( _g24 < numFlies2 ))
								{
									int flyCount2 = _g24++;
									double xTopRe2 = xTop2.re;
									double xTopIm2 = xTop2.im;
									double xBotRe2 = xBot2.re;
									double xBotIm2 = xBot2.im;
									xTop2.re = ( xTopRe2 + xBotRe2 );
									xTop2.im = ( xTopIm2 + xBotIm2 );
									xBotRe2 = ( xTopRe2 - xBotRe2 );
									xBotIm2 = ( xTopIm2 - xBotIm2 );
									xBot2.re = ( ( xBotRe2 * wRe2 ) - ( xBotIm2 * wIm2 ) );
									xBot2.im = ( ( xBotRe2 * wIm2 ) + ( xBotIm2 * wRe2 ) );
									xTop2 = xTop2.next;
									xBot2 = xBot2.next;
									double tRe2 = wRe2;
									wRe2 = ( ( wRe2 * wMulRe2 ) - ( wIm2 * wMulIm2 ) );
									wIm2 = ( ( tRe2 * wMulIm2 ) + ( wIm2 * wMulRe2 ) );
								}
								
							}
							
							start2 += spacing2;
						}
						
						numFlies2 >>= 1;
						span2 >>= 1;
						spacing2 >>= 1;
						wIndexStep2 <<= 1;
					}
					
				}
				
				x6 = fft1.m_X.__get(0);
				while (( x6 != null ))
				{
					int target2 = x6.revTgt;
					xRe1.__set(target2, x6.re);
					xIm1.__set(target2, x6.im);
					x6 = x6.next;
				}
				
			}
			
			{
				int numFlies3 = ( fft1.m_N >> 1 );
				int span3 = ( fft1.m_N >> 1 );
				int spacing3 = fft1.m_N;
				int wIndexStep3 = 1;
				haxe.root.FFTElement x7 = fft1.m_X.__get(0);
				int k9 = 0;
				double scale3 = fft1.m_invN;
				while (( x7 != null ))
				{
					x7.re = ( scale3 * ((double) (haxe.lang.Runtime.toDouble(xRe1.__get(k9))) ) );
					x7.im = ( scale3 * ((double) (haxe.lang.Runtime.toDouble(xIm1.__get(k9))) ) );
					x7 = x7.next;
					k9++;
				}
				
				java.lang.Class math3 = java.lang.Math.class;
				{
					int _g111 = 0;
					int _g25 = fft1.m_logN;
					while (( _g111 < _g25 ))
					{
						int stage3 = _g111++;
						double wAngleInc3 = ( ( ( wIndexStep3 * 2.0 ) * java.lang.Math.PI ) / fft1.m_N );
						double wMulRe3 = java.lang.Math.cos(wAngleInc3);
						double wMulIm3 = java.lang.Math.sin(wAngleInc3);
						int start3 = 0;
						while (( start3 < fft1.m_N ))
						{
							haxe.root.FFTElement xTop3 = fft1.m_X.__get(start3);
							haxe.root.FFTElement xBot3 = fft1.m_X.__get(( start3 + span3 ));
							double wRe3 = 1.0;
							double wIm3 = 0.0;
							{
								int _g26 = 0;
								while (( _g26 < numFlies3 ))
								{
									int flyCount3 = _g26++;
									double xTopRe3 = xTop3.re;
									double xTopIm3 = xTop3.im;
									double xBotRe3 = xBot3.re;
									double xBotIm3 = xBot3.im;
									xTop3.re = ( xTopRe3 + xBotRe3 );
									xTop3.im = ( xTopIm3 + xBotIm3 );
									xBotRe3 = ( xTopRe3 - xBotRe3 );
									xBotIm3 = ( xTopIm3 - xBotIm3 );
									xBot3.re = ( ( xBotRe3 * wRe3 ) - ( xBotIm3 * wIm3 ) );
									xBot3.im = ( ( xBotRe3 * wIm3 ) + ( xBotIm3 * wRe3 ) );
									xTop3 = xTop3.next;
									xBot3 = xBot3.next;
									double tRe3 = wRe3;
									wRe3 = ( ( wRe3 * wMulRe3 ) - ( wIm3 * wMulIm3 ) );
									wIm3 = ( ( tRe3 * wMulIm3 ) + ( wIm3 * wMulRe3 ) );
								}
								
							}
							
							start3 += spacing3;
						}
						
						numFlies3 >>= 1;
						span3 >>= 1;
						spacing3 >>= 1;
						wIndexStep3 <<= 1;
					}
					
				}
				
				x7 = fft1.m_X.__get(0);
				while (( x7 != null ))
				{
					int target3 = x7.revTgt;
					xRe1.__set(target3, x7.re);
					xIm1.__set(target3, x7.im);
					x7 = x7.next;
				}
				
			}
			
			boolean ok = true;
			{
				int _g27 = 0;
				while (( _g27 < 1024 ))
				{
					int i5 = _g27++;
					boolean __temp_stmt50 = false;
					{
						double a = ((double) (haxe.lang.Runtime.toDouble(xRe1.__get(i5))) );
						double b = ((double) (haxe.lang.Runtime.toDouble(xRe2.__get(i5))) );
						__temp_stmt50 = ( ( a < ( b + .0001 ) ) && ( a > ( b - .0001 ) ) );
					}
					
					if ( ! (__temp_stmt50) ) 
					{
						ok = false;
						break;
					}
					
				}
				
			}
			
			__temp_me9.print(( ( "Haxe translation is " + (( (ok) ? ("") : ("in") )) ) + "correct." ));
		}
		
	}
	
	
	public static  int LOG_N;
	
	public static  int N;
	
	public static  int NUM_LOOPS;
	
	public static   void main()
	{
		new haxe.root.FFTTimingTest();
	}
	
	
	public static  double PRECISION;
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new haxe.root.FFTTimingTest(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new haxe.root.FFTTimingTest();
	}
	
	
	public final   int getTimer()
	{
		{
			double x = ( haxe.Timer.stamp() * 1000 );
			return ((int) (x) );
		}
		
	}
	
	
	public final   void checkIfHaxeTranslationIsCorrect()
	{
		haxe.root.Array<java.lang.Object> xRe = null;
		{
			boolean fixed = false;
			xRe = new haxe.root.Array<java.lang.Object>();
		}
		
		haxe.root.Array<java.lang.Object> xIm = null;
		{
			boolean fixed1 = false;
			xIm = new haxe.root.Array<java.lang.Object>();
		}
		
		haxe.root.Array<java.lang.Object> xRe2 = null;
		{
			boolean fixed2 = false;
			xRe2 = new haxe.root.Array<java.lang.Object>();
		}
		
		haxe.root.Array<java.lang.Object> xIm2 = null;
		{
			boolean fixed3 = false;
			xIm2 = new haxe.root.Array<java.lang.Object>();
		}
		
		{
			int _g = 0;
			while (( _g < 1024 ))
			{
				int i = _g++;
				xRe.__set(i, ((double) (haxe.lang.Runtime.toDouble(xRe2.__set(i, java.lang.Math.cos(( ( ( ( 2 * java.lang.Math.PI ) * 2 ) * i ) / 1024 ))))) ));
				xIm.__set(i, ((double) (haxe.lang.Runtime.toDouble(xIm2.__set(i, 0.0))) ));
			}
			
		}
		
		haxe.root.FFT fft = new haxe.root.FFT();
		{
			fft.m_logN = 10;
			fft.m_N = ( 1 << fft.m_logN );
			fft.m_invN = ( 1.0 / fft.m_N );
			{
				boolean fixed4 = false;
				fft.m_X = new haxe.root.Array<haxe.root.FFTElement>();
			}
			
			{
				int _g1 = 0;
				int _g2 = fft.m_N;
				while (( _g1 < _g2 ))
				{
					int k = _g1++;
					fft.m_X.__set(k, new haxe.root.FFTElement());
				}
				
			}
			
			{
				int _g11 = 0;
				int _g3 = ( fft.m_N - 1 );
				while (( _g11 < _g3 ))
				{
					int k1 = _g11++;
					fft.m_X.__get(k1).next = fft.m_X.__get(( k1 + 1 ));
				}
				
			}
			
			{
				int _g12 = 0;
				int _g4 = fft.m_N;
				while (( _g12 < _g4 ))
				{
					int k2 = _g12++;
					{
						int x = k2;
						int y = 0;
						{
							int _g5 = 0;
							while (( _g5 < ((int) (10) ) ))
							{
								int i1 = _g5++;
								y <<= 1;
								y |= ( x & 1 );
								x >>= 1;
							}
							
						}
						
						fft.m_X.__get(k2).revTgt = y;
					}
					
				}
				
			}
			
		}
		
		{
			int numFlies = ( fft.m_N >> 1 );
			int span = ( fft.m_N >> 1 );
			int spacing = fft.m_N;
			int wIndexStep = 1;
			haxe.root.FFTElement x1 = fft.m_X.__get(0);
			int k3 = 0;
			double scale = 1.0;
			while (( x1 != null ))
			{
				x1.re = ( scale * ((double) (haxe.lang.Runtime.toDouble(xRe.__get(k3))) ) );
				x1.im = ( scale * ((double) (haxe.lang.Runtime.toDouble(xIm.__get(k3))) ) );
				x1 = x1.next;
				k3++;
			}
			
			java.lang.Class math = java.lang.Math.class;
			{
				int _g13 = 0;
				int _g6 = fft.m_logN;
				while (( _g13 < _g6 ))
				{
					int stage = _g13++;
					double wAngleInc = ( ( ( wIndexStep * 2.0 ) * java.lang.Math.PI ) / fft.m_N );
					wAngleInc *= ((double) (-1) );
					double wMulRe = java.lang.Math.cos(wAngleInc);
					double wMulIm = java.lang.Math.sin(wAngleInc);
					int start = 0;
					while (( start < fft.m_N ))
					{
						haxe.root.FFTElement xTop = fft.m_X.__get(start);
						haxe.root.FFTElement xBot = fft.m_X.__get(( start + span ));
						double wRe = 1.0;
						double wIm = 0.0;
						{
							int _g21 = 0;
							while (( _g21 < numFlies ))
							{
								int flyCount = _g21++;
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
			
			x1 = fft.m_X.__get(0);
			while (( x1 != null ))
			{
				int target = x1.revTgt;
				xRe.__set(target, x1.re);
				xIm.__set(target, x1.im);
				x1 = x1.next;
			}
			
		}
		
		{
			int numFlies1 = ( fft.m_N >> 1 );
			int span1 = ( fft.m_N >> 1 );
			int spacing1 = fft.m_N;
			int wIndexStep1 = 1;
			haxe.root.FFTElement x2 = fft.m_X.__get(0);
			int k4 = 0;
			double scale1 = fft.m_invN;
			while (( x2 != null ))
			{
				x2.re = ( scale1 * ((double) (haxe.lang.Runtime.toDouble(xRe.__get(k4))) ) );
				x2.im = ( scale1 * ((double) (haxe.lang.Runtime.toDouble(xIm.__get(k4))) ) );
				x2 = x2.next;
				k4++;
			}
			
			java.lang.Class math1 = java.lang.Math.class;
			{
				int _g14 = 0;
				int _g7 = fft.m_logN;
				while (( _g14 < _g7 ))
				{
					int stage1 = _g14++;
					double wAngleInc1 = ( ( ( wIndexStep1 * 2.0 ) * java.lang.Math.PI ) / fft.m_N );
					double wMulRe1 = java.lang.Math.cos(wAngleInc1);
					double wMulIm1 = java.lang.Math.sin(wAngleInc1);
					int start1 = 0;
					while (( start1 < fft.m_N ))
					{
						haxe.root.FFTElement xTop1 = fft.m_X.__get(start1);
						haxe.root.FFTElement xBot1 = fft.m_X.__get(( start1 + span1 ));
						double wRe1 = 1.0;
						double wIm1 = 0.0;
						{
							int _g22 = 0;
							while (( _g22 < numFlies1 ))
							{
								int flyCount1 = _g22++;
								double xTopRe1 = xTop1.re;
								double xTopIm1 = xTop1.im;
								double xBotRe1 = xBot1.re;
								double xBotIm1 = xBot1.im;
								xTop1.re = ( xTopRe1 + xBotRe1 );
								xTop1.im = ( xTopIm1 + xBotIm1 );
								xBotRe1 = ( xTopRe1 - xBotRe1 );
								xBotIm1 = ( xTopIm1 - xBotIm1 );
								xBot1.re = ( ( xBotRe1 * wRe1 ) - ( xBotIm1 * wIm1 ) );
								xBot1.im = ( ( xBotRe1 * wIm1 ) + ( xBotIm1 * wRe1 ) );
								xTop1 = xTop1.next;
								xBot1 = xBot1.next;
								double tRe1 = wRe1;
								wRe1 = ( ( wRe1 * wMulRe1 ) - ( wIm1 * wMulIm1 ) );
								wIm1 = ( ( tRe1 * wMulIm1 ) + ( wIm1 * wMulRe1 ) );
							}
							
						}
						
						start1 += spacing1;
					}
					
					numFlies1 >>= 1;
					span1 >>= 1;
					spacing1 >>= 1;
					wIndexStep1 <<= 1;
				}
				
			}
			
			x2 = fft.m_X.__get(0);
			while (( x2 != null ))
			{
				int target1 = x2.revTgt;
				xRe.__set(target1, x2.re);
				xIm.__set(target1, x2.im);
				x2 = x2.next;
			}
			
		}
		
		boolean ok = true;
		{
			int _g8 = 0;
			while (( _g8 < 1024 ))
			{
				int i2 = _g8++;
				boolean __temp_stmt47 = false;
				{
					double a = ((double) (haxe.lang.Runtime.toDouble(xRe.__get(i2))) );
					double b = ((double) (haxe.lang.Runtime.toDouble(xRe2.__get(i2))) );
					__temp_stmt47 = ( ( a < ( b + .0001 ) ) && ( a > ( b - .0001 ) ) );
				}
				
				if ( ! (__temp_stmt47) ) 
				{
					ok = false;
					break;
				}
				
			}
			
		}
		
		this.print(( ( "Haxe translation is " + (( (ok) ? ("") : ("in") )) ) + "correct." ));
	}
	
	
	public final   boolean almostEqual(double a, double b)
	{
		return ( ( a < ( b + .0001 ) ) && ( a > ( b - .0001 ) ) );
	}
	
	
	public   void initTest()
	{
		{
		}
		
	}
	
	
	public   void print(java.lang.String s)
	{
		haxe.Log.trace.__hx_invoke2_o(0.0, s, 0.0, new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"FFTTimingTest", "FFTTimingTest.hx", "print"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (119) )) )})));
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef48 = true;
			switch (field.hashCode())
			{
				case 106934957:
				{
					if (field.equals("print")) 
					{
						__temp_executeDef48 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("print"))) );
					}
					
					break;
				}
				
				
				case 1966189967:
				{
					if (field.equals("getTimer")) 
					{
						__temp_executeDef48 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("getTimer"))) );
					}
					
					break;
				}
				
				
				case 268441026:
				{
					if (field.equals("initTest")) 
					{
						__temp_executeDef48 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("initTest"))) );
					}
					
					break;
				}
				
				
				case -771232678:
				{
					if (field.equals("checkIfHaxeTranslationIsCorrect")) 
					{
						__temp_executeDef48 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("checkIfHaxeTranslationIsCorrect"))) );
					}
					
					break;
				}
				
				
				case 852060582:
				{
					if (field.equals("almostEqual")) 
					{
						__temp_executeDef48 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("almostEqual"))) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef48) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef49 = true;
			switch (field.hashCode())
			{
				case 106934957:
				{
					if (field.equals("print")) 
					{
						__temp_executeDef49 = false;
						this.print(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
				case 1966189967:
				{
					if (field.equals("getTimer")) 
					{
						__temp_executeDef49 = false;
						return this.getTimer();
					}
					
					break;
				}
				
				
				case 268441026:
				{
					if (field.equals("initTest")) 
					{
						__temp_executeDef49 = false;
						this.initTest();
					}
					
					break;
				}
				
				
				case -771232678:
				{
					if (field.equals("checkIfHaxeTranslationIsCorrect")) 
					{
						__temp_executeDef49 = false;
						this.checkIfHaxeTranslationIsCorrect();
					}
					
					break;
				}
				
				
				case 852060582:
				{
					if (field.equals("almostEqual")) 
					{
						__temp_executeDef49 = false;
						return this.almostEqual(((double) (haxe.lang.Runtime.toDouble(dynargs.__get(0))) ), ((double) (haxe.lang.Runtime.toDouble(dynargs.__get(1))) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef49) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
}


