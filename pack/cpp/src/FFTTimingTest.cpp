#include <hxcpp.h>

#ifndef INCLUDED_FFT
#include <FFT.h>
#endif
#ifndef INCLUDED_FFTElement
#include <FFTElement.h>
#endif
#ifndef INCLUDED_FFTElementEssentials
#include <FFTElementEssentials.h>
#endif
#ifndef INCLUDED_FFTTimingTest
#include <FFTTimingTest.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void FFTTimingTest_obj::__construct()
{
HX_STACK_FRAME("FFTTimingTest","new",0x0edd0d22,"FFTTimingTest.new","FFTTimingTest.hx",18,0xdec66c8e)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(19)
	this->initTest();
	HX_STACK_LINE(21)
	this->print(HX_CSTRING("Performing FFTs..."));
	HX_STACK_LINE(25)
	Array< Float > xRe;		HX_STACK_VAR(xRe,"xRe");
	HX_STACK_LINE(25)
	{
		HX_STACK_LINE(25)
		bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
		HX_STACK_LINE(25)
		xRe = Array_obj< Float >::__new();
	}
	HX_STACK_LINE(26)
	Array< Float > xIm;		HX_STACK_VAR(xIm,"xIm");
	HX_STACK_LINE(26)
	{
		HX_STACK_LINE(26)
		bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
		HX_STACK_LINE(26)
		xIm = Array_obj< Float >::__new();
	}
	HX_STACK_LINE(29)
	{
		HX_STACK_LINE(29)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(29)
		while((true)){
			HX_STACK_LINE(29)
			if ((!(((_g < (int)1024))))){
				HX_STACK_LINE(29)
				break;
			}
			HX_STACK_LINE(29)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(31)
			xRe[i] = ::Math_obj::cos((Float(((((int)2 * ::Math_obj::PI) * (int)2) * i)) / Float((int)1024)));
			HX_STACK_LINE(32)
			xIm[i] = 0.0;
		}
	}
	HX_STACK_LINE(36)
	::FFT fft = ::FFT_obj::__new();		HX_STACK_VAR(fft,"fft");
	HX_STACK_LINE(37)
	{
		HX_STACK_LINE(37)
		fft->m_logN = (int)10;
		HX_STACK_LINE(37)
		fft->m_N = (int((int)1) << int(fft->m_logN));
		HX_STACK_LINE(37)
		fft->m_invN = (Float(1.0) / Float(fft->m_N));
		HX_STACK_LINE(37)
		Array< ::Dynamic > _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(37)
		{
			HX_STACK_LINE(37)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(37)
			_g = Array_obj< ::Dynamic >::__new();
		}
		HX_STACK_LINE(37)
		fft->m_X = _g;
		HX_STACK_LINE(37)
		{
			HX_STACK_LINE(37)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(37)
			int _g2 = fft->m_N;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(37)
			while((true)){
				HX_STACK_LINE(37)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(37)
					break;
				}
				HX_STACK_LINE(37)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(37)
				fft->m_X[k] = ::FFTElement_obj::__new();
			}
		}
		HX_STACK_LINE(37)
		{
			HX_STACK_LINE(37)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(37)
			int _g2 = (fft->m_N - (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(37)
			while((true)){
				HX_STACK_LINE(37)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(37)
					break;
				}
				HX_STACK_LINE(37)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(37)
				fft->m_X->__get(k).StaticCast< ::FFTElement >()->next = fft->m_X->__get((k + (int)1)).StaticCast< ::FFTElement >();
			}
		}
		HX_STACK_LINE(37)
		{
			HX_STACK_LINE(37)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(37)
			int _g2 = fft->m_N;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(37)
			while((true)){
				HX_STACK_LINE(37)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(37)
					break;
				}
				HX_STACK_LINE(37)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(37)
				int _g11;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(37)
				{
					HX_STACK_LINE(37)
					int x = k;		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(37)
					int y = (int)0;		HX_STACK_VAR(y,"y");
					HX_STACK_LINE(37)
					{
						HX_STACK_LINE(37)
						int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(37)
						while((true)){
							HX_STACK_LINE(37)
							if ((!(((_g3 < (int)10))))){
								HX_STACK_LINE(37)
								break;
							}
							HX_STACK_LINE(37)
							int i = (_g3)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(37)
							hx::ShlEq(y,(int)1);
							HX_STACK_LINE(37)
							hx::OrEq(y,(int(x) & int((int)1)));
							HX_STACK_LINE(37)
							hx::ShrEq(x,(int)1);
						}
					}
					HX_STACK_LINE(37)
					_g11 = y;
				}
				HX_STACK_LINE(37)
				fft->m_X->__get(k).StaticCast< ::FFTElement >()->revTgt = _g11;
			}
		}
	}
	HX_STACK_LINE(40)
	Float _g2 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(40)
	Float _g3 = (_g2 * (int)1000);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(40)
	int startTime = ::Std_obj::_int(_g3);		HX_STACK_VAR(startTime,"startTime");
	HX_STACK_LINE(41)
	{
		HX_STACK_LINE(41)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(41)
		while((true)){
			HX_STACK_LINE(41)
			if ((!(((_g < (int)1000))))){
				HX_STACK_LINE(41)
				break;
			}
			HX_STACK_LINE(41)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(43)
			{
				HX_STACK_LINE(43)
				int numFlies = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(numFlies,"numFlies");
				HX_STACK_LINE(43)
				int span = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(span,"span");
				HX_STACK_LINE(43)
				int spacing = fft->m_N;		HX_STACK_VAR(spacing,"spacing");
				HX_STACK_LINE(43)
				int wIndexStep = (int)1;		HX_STACK_VAR(wIndexStep,"wIndexStep");
				HX_STACK_LINE(43)
				::FFTElement x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();		HX_STACK_VAR(x,"x");
				HX_STACK_LINE(43)
				int k = (int)0;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(43)
				Float scale = 1.0;		HX_STACK_VAR(scale,"scale");
				HX_STACK_LINE(43)
				while((true)){
					HX_STACK_LINE(43)
					if ((!(((x != null()))))){
						HX_STACK_LINE(43)
						break;
					}
					HX_STACK_LINE(43)
					x->re = (scale * xRe->__get(k));
					HX_STACK_LINE(43)
					x->im = (scale * xIm->__get(k));
					HX_STACK_LINE(43)
					x = x->next;
					HX_STACK_LINE(43)
					(k)++;
				}
				HX_STACK_LINE(43)
				Dynamic math = hx::ClassOf< ::Math >();		HX_STACK_VAR(math,"math");
				HX_STACK_LINE(43)
				{
					HX_STACK_LINE(43)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(43)
					int _g4 = fft->m_logN;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(43)
					while((true)){
						HX_STACK_LINE(43)
						if ((!(((_g1 < _g4))))){
							HX_STACK_LINE(43)
							break;
						}
						HX_STACK_LINE(43)
						int stage = (_g1)++;		HX_STACK_VAR(stage,"stage");
						HX_STACK_LINE(43)
						Float wAngleInc = (Float(((wIndexStep * 2.0) * math->__Field(HX_CSTRING("PI"),true))) / Float(fft->m_N));		HX_STACK_VAR(wAngleInc,"wAngleInc");
						HX_STACK_LINE(43)
						hx::MultEq(wAngleInc,(int)-1);
						HX_STACK_LINE(43)
						Float wMulRe = math->__Field(HX_CSTRING("cos"),true)(wAngleInc);		HX_STACK_VAR(wMulRe,"wMulRe");
						HX_STACK_LINE(43)
						Float wMulIm = math->__Field(HX_CSTRING("sin"),true)(wAngleInc);		HX_STACK_VAR(wMulIm,"wMulIm");
						HX_STACK_LINE(43)
						int start = (int)0;		HX_STACK_VAR(start,"start");
						HX_STACK_LINE(43)
						while((true)){
							HX_STACK_LINE(43)
							if ((!(((start < fft->m_N))))){
								HX_STACK_LINE(43)
								break;
							}
							HX_STACK_LINE(43)
							::FFTElement xTop = fft->m_X->__get(start).StaticCast< ::FFTElement >();		HX_STACK_VAR(xTop,"xTop");
							HX_STACK_LINE(43)
							::FFTElement xBot = fft->m_X->__get((start + span)).StaticCast< ::FFTElement >();		HX_STACK_VAR(xBot,"xBot");
							HX_STACK_LINE(43)
							Float wRe = 1.0;		HX_STACK_VAR(wRe,"wRe");
							HX_STACK_LINE(43)
							Float wIm = 0.0;		HX_STACK_VAR(wIm,"wIm");
							HX_STACK_LINE(43)
							{
								HX_STACK_LINE(43)
								int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
								HX_STACK_LINE(43)
								while((true)){
									HX_STACK_LINE(43)
									if ((!(((_g21 < numFlies))))){
										HX_STACK_LINE(43)
										break;
									}
									HX_STACK_LINE(43)
									int flyCount = (_g21)++;		HX_STACK_VAR(flyCount,"flyCount");
									HX_STACK_LINE(43)
									Float xTopRe = xTop->re;		HX_STACK_VAR(xTopRe,"xTopRe");
									HX_STACK_LINE(43)
									Float xTopIm = xTop->im;		HX_STACK_VAR(xTopIm,"xTopIm");
									HX_STACK_LINE(43)
									Float xBotRe = xBot->re;		HX_STACK_VAR(xBotRe,"xBotRe");
									HX_STACK_LINE(43)
									Float xBotIm = xBot->im;		HX_STACK_VAR(xBotIm,"xBotIm");
									HX_STACK_LINE(43)
									xTop->re = (xTopRe + xBotRe);
									HX_STACK_LINE(43)
									xTop->im = (xTopIm + xBotIm);
									HX_STACK_LINE(43)
									xBotRe = (xTopRe - xBotRe);
									HX_STACK_LINE(43)
									xBotIm = (xTopIm - xBotIm);
									HX_STACK_LINE(43)
									xBot->re = ((xBotRe * wRe) - (xBotIm * wIm));
									HX_STACK_LINE(43)
									xBot->im = ((xBotRe * wIm) + (xBotIm * wRe));
									HX_STACK_LINE(43)
									xTop = xTop->next;
									HX_STACK_LINE(43)
									xBot = xBot->next;
									HX_STACK_LINE(43)
									Float tRe = wRe;		HX_STACK_VAR(tRe,"tRe");
									HX_STACK_LINE(43)
									wRe = ((wRe * wMulRe) - (wIm * wMulIm));
									HX_STACK_LINE(43)
									wIm = ((tRe * wMulIm) + (wIm * wMulRe));
								}
							}
							HX_STACK_LINE(43)
							hx::AddEq(start,spacing);
						}
						HX_STACK_LINE(43)
						hx::ShrEq(numFlies,(int)1);
						HX_STACK_LINE(43)
						hx::ShrEq(span,(int)1);
						HX_STACK_LINE(43)
						hx::ShrEq(spacing,(int)1);
						HX_STACK_LINE(43)
						hx::ShlEq(wIndexStep,(int)1);
					}
				}
				HX_STACK_LINE(43)
				x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();
				HX_STACK_LINE(43)
				while((true)){
					HX_STACK_LINE(43)
					if ((!(((x != null()))))){
						HX_STACK_LINE(43)
						break;
					}
					HX_STACK_LINE(43)
					int target = x->revTgt;		HX_STACK_VAR(target,"target");
					HX_STACK_LINE(43)
					xRe[target] = x->re;
					HX_STACK_LINE(43)
					xIm[target] = x->im;
					HX_STACK_LINE(43)
					x = x->next;
				}
			}
			HX_STACK_LINE(44)
			{
				HX_STACK_LINE(44)
				int numFlies = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(numFlies,"numFlies");
				HX_STACK_LINE(44)
				int span = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(span,"span");
				HX_STACK_LINE(44)
				int spacing = fft->m_N;		HX_STACK_VAR(spacing,"spacing");
				HX_STACK_LINE(44)
				int wIndexStep = (int)1;		HX_STACK_VAR(wIndexStep,"wIndexStep");
				HX_STACK_LINE(44)
				::FFTElement x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();		HX_STACK_VAR(x,"x");
				HX_STACK_LINE(44)
				int k = (int)0;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(44)
				Float scale = fft->m_invN;		HX_STACK_VAR(scale,"scale");
				HX_STACK_LINE(44)
				while((true)){
					HX_STACK_LINE(44)
					if ((!(((x != null()))))){
						HX_STACK_LINE(44)
						break;
					}
					HX_STACK_LINE(44)
					x->re = (scale * xRe->__get(k));
					HX_STACK_LINE(44)
					x->im = (scale * xIm->__get(k));
					HX_STACK_LINE(44)
					x = x->next;
					HX_STACK_LINE(44)
					(k)++;
				}
				HX_STACK_LINE(44)
				Dynamic math = hx::ClassOf< ::Math >();		HX_STACK_VAR(math,"math");
				HX_STACK_LINE(44)
				{
					HX_STACK_LINE(44)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(44)
					int _g4 = fft->m_logN;		HX_STACK_VAR(_g4,"_g4");
					HX_STACK_LINE(44)
					while((true)){
						HX_STACK_LINE(44)
						if ((!(((_g1 < _g4))))){
							HX_STACK_LINE(44)
							break;
						}
						HX_STACK_LINE(44)
						int stage = (_g1)++;		HX_STACK_VAR(stage,"stage");
						HX_STACK_LINE(44)
						Float wAngleInc = (Float(((wIndexStep * 2.0) * math->__Field(HX_CSTRING("PI"),true))) / Float(fft->m_N));		HX_STACK_VAR(wAngleInc,"wAngleInc");
						HX_STACK_LINE(44)
						Float wMulRe = math->__Field(HX_CSTRING("cos"),true)(wAngleInc);		HX_STACK_VAR(wMulRe,"wMulRe");
						HX_STACK_LINE(44)
						Float wMulIm = math->__Field(HX_CSTRING("sin"),true)(wAngleInc);		HX_STACK_VAR(wMulIm,"wMulIm");
						HX_STACK_LINE(44)
						int start = (int)0;		HX_STACK_VAR(start,"start");
						HX_STACK_LINE(44)
						while((true)){
							HX_STACK_LINE(44)
							if ((!(((start < fft->m_N))))){
								HX_STACK_LINE(44)
								break;
							}
							HX_STACK_LINE(44)
							::FFTElement xTop = fft->m_X->__get(start).StaticCast< ::FFTElement >();		HX_STACK_VAR(xTop,"xTop");
							HX_STACK_LINE(44)
							::FFTElement xBot = fft->m_X->__get((start + span)).StaticCast< ::FFTElement >();		HX_STACK_VAR(xBot,"xBot");
							HX_STACK_LINE(44)
							Float wRe = 1.0;		HX_STACK_VAR(wRe,"wRe");
							HX_STACK_LINE(44)
							Float wIm = 0.0;		HX_STACK_VAR(wIm,"wIm");
							HX_STACK_LINE(44)
							{
								HX_STACK_LINE(44)
								int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
								HX_STACK_LINE(44)
								while((true)){
									HX_STACK_LINE(44)
									if ((!(((_g21 < numFlies))))){
										HX_STACK_LINE(44)
										break;
									}
									HX_STACK_LINE(44)
									int flyCount = (_g21)++;		HX_STACK_VAR(flyCount,"flyCount");
									HX_STACK_LINE(44)
									Float xTopRe = xTop->re;		HX_STACK_VAR(xTopRe,"xTopRe");
									HX_STACK_LINE(44)
									Float xTopIm = xTop->im;		HX_STACK_VAR(xTopIm,"xTopIm");
									HX_STACK_LINE(44)
									Float xBotRe = xBot->re;		HX_STACK_VAR(xBotRe,"xBotRe");
									HX_STACK_LINE(44)
									Float xBotIm = xBot->im;		HX_STACK_VAR(xBotIm,"xBotIm");
									HX_STACK_LINE(44)
									xTop->re = (xTopRe + xBotRe);
									HX_STACK_LINE(44)
									xTop->im = (xTopIm + xBotIm);
									HX_STACK_LINE(44)
									xBotRe = (xTopRe - xBotRe);
									HX_STACK_LINE(44)
									xBotIm = (xTopIm - xBotIm);
									HX_STACK_LINE(44)
									xBot->re = ((xBotRe * wRe) - (xBotIm * wIm));
									HX_STACK_LINE(44)
									xBot->im = ((xBotRe * wIm) + (xBotIm * wRe));
									HX_STACK_LINE(44)
									xTop = xTop->next;
									HX_STACK_LINE(44)
									xBot = xBot->next;
									HX_STACK_LINE(44)
									Float tRe = wRe;		HX_STACK_VAR(tRe,"tRe");
									HX_STACK_LINE(44)
									wRe = ((wRe * wMulRe) - (wIm * wMulIm));
									HX_STACK_LINE(44)
									wIm = ((tRe * wMulIm) + (wIm * wMulRe));
								}
							}
							HX_STACK_LINE(44)
							hx::AddEq(start,spacing);
						}
						HX_STACK_LINE(44)
						hx::ShrEq(numFlies,(int)1);
						HX_STACK_LINE(44)
						hx::ShrEq(span,(int)1);
						HX_STACK_LINE(44)
						hx::ShrEq(spacing,(int)1);
						HX_STACK_LINE(44)
						hx::ShlEq(wIndexStep,(int)1);
					}
				}
				HX_STACK_LINE(44)
				x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();
				HX_STACK_LINE(44)
				while((true)){
					HX_STACK_LINE(44)
					if ((!(((x != null()))))){
						HX_STACK_LINE(44)
						break;
					}
					HX_STACK_LINE(44)
					int target = x->revTgt;		HX_STACK_VAR(target,"target");
					HX_STACK_LINE(44)
					xRe[target] = x->re;
					HX_STACK_LINE(44)
					xIm[target] = x->im;
					HX_STACK_LINE(44)
					x = x->next;
				}
			}
		}
	}
	HX_STACK_LINE(46)
	Float _g4 = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(46)
	Float _g5 = (_g4 * (int)1000);		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(46)
	int endTime = ::Std_obj::_int(_g5);		HX_STACK_VAR(endTime,"endTime");
	HX_STACK_LINE(49)
	int elapsed = (endTime - startTime);		HX_STACK_VAR(elapsed,"elapsed");
	HX_STACK_LINE(50)
	Float timePerFFT = (Float(elapsed) / Float(2000.));		HX_STACK_VAR(timePerFFT,"timePerFFT");
	HX_STACK_LINE(52)
	int _g6 = ::Std_obj::_int((timePerFFT * (int)1000));		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(52)
	Float _g7 = (Float(_g6) / Float((int)1000));		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(51)
	::String _g8 = (((((((int)1000 + HX_CSTRING(" fwd-inv pairs of ")) + (int)1024) + HX_CSTRING(" pt FFTs took ")) + elapsed) + HX_CSTRING(" ms, or ")) + _g7);		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(51)
	::String _g9 = (_g8 + HX_CSTRING(" ms per FFT."));		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(51)
	this->print(_g9);
	HX_STACK_LINE(54)
	{
		HX_STACK_LINE(54)
		Array< Float > xRe1;		HX_STACK_VAR(xRe1,"xRe1");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(54)
			xRe1 = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(54)
		Array< Float > xIm1;		HX_STACK_VAR(xIm1,"xIm1");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(54)
			xIm1 = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(54)
		Array< Float > xRe2;		HX_STACK_VAR(xRe2,"xRe2");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(54)
			xRe2 = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(54)
		Array< Float > xIm2;		HX_STACK_VAR(xIm2,"xIm2");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(54)
			xIm2 = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				if ((!(((_g < (int)1024))))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(54)
				xRe1[i] = xRe2[i] = ::Math_obj::cos((Float(((((int)2 * ::Math_obj::PI) * (int)2) * i)) / Float((int)1024)));
				HX_STACK_LINE(54)
				xIm1[i] = xIm2[i] = 0.0;
			}
		}
		HX_STACK_LINE(54)
		::FFT fft1 = ::FFT_obj::__new();		HX_STACK_VAR(fft1,"fft1");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			fft1->m_logN = (int)10;
			HX_STACK_LINE(54)
			fft1->m_N = (int((int)1) << int(fft1->m_logN));
			HX_STACK_LINE(54)
			fft1->m_invN = (Float(1.0) / Float(fft1->m_N));
			HX_STACK_LINE(54)
			Array< ::Dynamic > _g10;		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(54)
			{
				HX_STACK_LINE(54)
				bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
				HX_STACK_LINE(54)
				_g10 = Array_obj< ::Dynamic >::__new();
			}
			HX_STACK_LINE(54)
			fft1->m_X = _g10;
			HX_STACK_LINE(54)
			{
				HX_STACK_LINE(54)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(54)
				int _g = fft1->m_N;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(54)
				while((true)){
					HX_STACK_LINE(54)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(54)
						break;
					}
					HX_STACK_LINE(54)
					int k = (_g1)++;		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(54)
					fft1->m_X[k] = ::FFTElement_obj::__new();
				}
			}
			HX_STACK_LINE(54)
			{
				HX_STACK_LINE(54)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(54)
				int _g = (fft1->m_N - (int)1);		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(54)
				while((true)){
					HX_STACK_LINE(54)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(54)
						break;
					}
					HX_STACK_LINE(54)
					int k = (_g1)++;		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(54)
					fft1->m_X->__get(k).StaticCast< ::FFTElement >()->next = fft1->m_X->__get((k + (int)1)).StaticCast< ::FFTElement >();
				}
			}
			HX_STACK_LINE(54)
			{
				HX_STACK_LINE(54)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(54)
				int _g = fft1->m_N;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(54)
				while((true)){
					HX_STACK_LINE(54)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(54)
						break;
					}
					HX_STACK_LINE(54)
					int k = (_g1)++;		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(54)
					int _g11;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(54)
					{
						HX_STACK_LINE(54)
						int x = k;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(54)
						int y = (int)0;		HX_STACK_VAR(y,"y");
						HX_STACK_LINE(54)
						{
							HX_STACK_LINE(54)
							int _g12 = (int)0;		HX_STACK_VAR(_g12,"_g12");
							HX_STACK_LINE(54)
							while((true)){
								HX_STACK_LINE(54)
								if ((!(((_g12 < (int)10))))){
									HX_STACK_LINE(54)
									break;
								}
								HX_STACK_LINE(54)
								int i = (_g12)++;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(54)
								hx::ShlEq(y,(int)1);
								HX_STACK_LINE(54)
								hx::OrEq(y,(int(x) & int((int)1)));
								HX_STACK_LINE(54)
								hx::ShrEq(x,(int)1);
							}
						}
						HX_STACK_LINE(54)
						_g11 = y;
					}
					HX_STACK_LINE(54)
					fft1->m_X->__get(k).StaticCast< ::FFTElement >()->revTgt = _g11;
				}
			}
		}
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			int numFlies = (int(fft1->m_N) >> int((int)1));		HX_STACK_VAR(numFlies,"numFlies");
			HX_STACK_LINE(54)
			int span = (int(fft1->m_N) >> int((int)1));		HX_STACK_VAR(span,"span");
			HX_STACK_LINE(54)
			int spacing = fft1->m_N;		HX_STACK_VAR(spacing,"spacing");
			HX_STACK_LINE(54)
			int wIndexStep = (int)1;		HX_STACK_VAR(wIndexStep,"wIndexStep");
			HX_STACK_LINE(54)
			::FFTElement x = fft1->m_X->__get((int)0).StaticCast< ::FFTElement >();		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(54)
			int k = (int)0;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(54)
			Float scale = 1.0;		HX_STACK_VAR(scale,"scale");
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				if ((!(((x != null()))))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				x->re = (scale * xRe1->__get(k));
				HX_STACK_LINE(54)
				x->im = (scale * xIm1->__get(k));
				HX_STACK_LINE(54)
				x = x->next;
				HX_STACK_LINE(54)
				(k)++;
			}
			HX_STACK_LINE(54)
			Dynamic math = hx::ClassOf< ::Math >();		HX_STACK_VAR(math,"math");
			HX_STACK_LINE(54)
			{
				HX_STACK_LINE(54)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(54)
				int _g = fft1->m_logN;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(54)
				while((true)){
					HX_STACK_LINE(54)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(54)
						break;
					}
					HX_STACK_LINE(54)
					int stage = (_g1)++;		HX_STACK_VAR(stage,"stage");
					HX_STACK_LINE(54)
					Float wAngleInc = (Float(((wIndexStep * 2.0) * math->__Field(HX_CSTRING("PI"),true))) / Float(fft1->m_N));		HX_STACK_VAR(wAngleInc,"wAngleInc");
					HX_STACK_LINE(54)
					hx::MultEq(wAngleInc,(int)-1);
					HX_STACK_LINE(54)
					Float wMulRe = math->__Field(HX_CSTRING("cos"),true)(wAngleInc);		HX_STACK_VAR(wMulRe,"wMulRe");
					HX_STACK_LINE(54)
					Float wMulIm = math->__Field(HX_CSTRING("sin"),true)(wAngleInc);		HX_STACK_VAR(wMulIm,"wMulIm");
					HX_STACK_LINE(54)
					int start = (int)0;		HX_STACK_VAR(start,"start");
					HX_STACK_LINE(54)
					while((true)){
						HX_STACK_LINE(54)
						if ((!(((start < fft1->m_N))))){
							HX_STACK_LINE(54)
							break;
						}
						HX_STACK_LINE(54)
						::FFTElement xTop = fft1->m_X->__get(start).StaticCast< ::FFTElement >();		HX_STACK_VAR(xTop,"xTop");
						HX_STACK_LINE(54)
						::FFTElement xBot = fft1->m_X->__get((start + span)).StaticCast< ::FFTElement >();		HX_STACK_VAR(xBot,"xBot");
						HX_STACK_LINE(54)
						Float wRe = 1.0;		HX_STACK_VAR(wRe,"wRe");
						HX_STACK_LINE(54)
						Float wIm = 0.0;		HX_STACK_VAR(wIm,"wIm");
						HX_STACK_LINE(54)
						{
							HX_STACK_LINE(54)
							int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(54)
							while((true)){
								HX_STACK_LINE(54)
								if ((!(((_g21 < numFlies))))){
									HX_STACK_LINE(54)
									break;
								}
								HX_STACK_LINE(54)
								int flyCount = (_g21)++;		HX_STACK_VAR(flyCount,"flyCount");
								HX_STACK_LINE(54)
								Float xTopRe = xTop->re;		HX_STACK_VAR(xTopRe,"xTopRe");
								HX_STACK_LINE(54)
								Float xTopIm = xTop->im;		HX_STACK_VAR(xTopIm,"xTopIm");
								HX_STACK_LINE(54)
								Float xBotRe = xBot->re;		HX_STACK_VAR(xBotRe,"xBotRe");
								HX_STACK_LINE(54)
								Float xBotIm = xBot->im;		HX_STACK_VAR(xBotIm,"xBotIm");
								HX_STACK_LINE(54)
								xTop->re = (xTopRe + xBotRe);
								HX_STACK_LINE(54)
								xTop->im = (xTopIm + xBotIm);
								HX_STACK_LINE(54)
								xBotRe = (xTopRe - xBotRe);
								HX_STACK_LINE(54)
								xBotIm = (xTopIm - xBotIm);
								HX_STACK_LINE(54)
								xBot->re = ((xBotRe * wRe) - (xBotIm * wIm));
								HX_STACK_LINE(54)
								xBot->im = ((xBotRe * wIm) + (xBotIm * wRe));
								HX_STACK_LINE(54)
								xTop = xTop->next;
								HX_STACK_LINE(54)
								xBot = xBot->next;
								HX_STACK_LINE(54)
								Float tRe = wRe;		HX_STACK_VAR(tRe,"tRe");
								HX_STACK_LINE(54)
								wRe = ((wRe * wMulRe) - (wIm * wMulIm));
								HX_STACK_LINE(54)
								wIm = ((tRe * wMulIm) + (wIm * wMulRe));
							}
						}
						HX_STACK_LINE(54)
						hx::AddEq(start,spacing);
					}
					HX_STACK_LINE(54)
					hx::ShrEq(numFlies,(int)1);
					HX_STACK_LINE(54)
					hx::ShrEq(span,(int)1);
					HX_STACK_LINE(54)
					hx::ShrEq(spacing,(int)1);
					HX_STACK_LINE(54)
					hx::ShlEq(wIndexStep,(int)1);
				}
			}
			HX_STACK_LINE(54)
			x = fft1->m_X->__get((int)0).StaticCast< ::FFTElement >();
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				if ((!(((x != null()))))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				int target = x->revTgt;		HX_STACK_VAR(target,"target");
				HX_STACK_LINE(54)
				xRe1[target] = x->re;
				HX_STACK_LINE(54)
				xIm1[target] = x->im;
				HX_STACK_LINE(54)
				x = x->next;
			}
		}
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			int numFlies = (int(fft1->m_N) >> int((int)1));		HX_STACK_VAR(numFlies,"numFlies");
			HX_STACK_LINE(54)
			int span = (int(fft1->m_N) >> int((int)1));		HX_STACK_VAR(span,"span");
			HX_STACK_LINE(54)
			int spacing = fft1->m_N;		HX_STACK_VAR(spacing,"spacing");
			HX_STACK_LINE(54)
			int wIndexStep = (int)1;		HX_STACK_VAR(wIndexStep,"wIndexStep");
			HX_STACK_LINE(54)
			::FFTElement x = fft1->m_X->__get((int)0).StaticCast< ::FFTElement >();		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(54)
			int k = (int)0;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(54)
			Float scale = fft1->m_invN;		HX_STACK_VAR(scale,"scale");
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				if ((!(((x != null()))))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				x->re = (scale * xRe1->__get(k));
				HX_STACK_LINE(54)
				x->im = (scale * xIm1->__get(k));
				HX_STACK_LINE(54)
				x = x->next;
				HX_STACK_LINE(54)
				(k)++;
			}
			HX_STACK_LINE(54)
			Dynamic math = hx::ClassOf< ::Math >();		HX_STACK_VAR(math,"math");
			HX_STACK_LINE(54)
			{
				HX_STACK_LINE(54)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(54)
				int _g = fft1->m_logN;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(54)
				while((true)){
					HX_STACK_LINE(54)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(54)
						break;
					}
					HX_STACK_LINE(54)
					int stage = (_g1)++;		HX_STACK_VAR(stage,"stage");
					HX_STACK_LINE(54)
					Float wAngleInc = (Float(((wIndexStep * 2.0) * math->__Field(HX_CSTRING("PI"),true))) / Float(fft1->m_N));		HX_STACK_VAR(wAngleInc,"wAngleInc");
					HX_STACK_LINE(54)
					Float wMulRe = math->__Field(HX_CSTRING("cos"),true)(wAngleInc);		HX_STACK_VAR(wMulRe,"wMulRe");
					HX_STACK_LINE(54)
					Float wMulIm = math->__Field(HX_CSTRING("sin"),true)(wAngleInc);		HX_STACK_VAR(wMulIm,"wMulIm");
					HX_STACK_LINE(54)
					int start = (int)0;		HX_STACK_VAR(start,"start");
					HX_STACK_LINE(54)
					while((true)){
						HX_STACK_LINE(54)
						if ((!(((start < fft1->m_N))))){
							HX_STACK_LINE(54)
							break;
						}
						HX_STACK_LINE(54)
						::FFTElement xTop = fft1->m_X->__get(start).StaticCast< ::FFTElement >();		HX_STACK_VAR(xTop,"xTop");
						HX_STACK_LINE(54)
						::FFTElement xBot = fft1->m_X->__get((start + span)).StaticCast< ::FFTElement >();		HX_STACK_VAR(xBot,"xBot");
						HX_STACK_LINE(54)
						Float wRe = 1.0;		HX_STACK_VAR(wRe,"wRe");
						HX_STACK_LINE(54)
						Float wIm = 0.0;		HX_STACK_VAR(wIm,"wIm");
						HX_STACK_LINE(54)
						{
							HX_STACK_LINE(54)
							int _g21 = (int)0;		HX_STACK_VAR(_g21,"_g21");
							HX_STACK_LINE(54)
							while((true)){
								HX_STACK_LINE(54)
								if ((!(((_g21 < numFlies))))){
									HX_STACK_LINE(54)
									break;
								}
								HX_STACK_LINE(54)
								int flyCount = (_g21)++;		HX_STACK_VAR(flyCount,"flyCount");
								HX_STACK_LINE(54)
								Float xTopRe = xTop->re;		HX_STACK_VAR(xTopRe,"xTopRe");
								HX_STACK_LINE(54)
								Float xTopIm = xTop->im;		HX_STACK_VAR(xTopIm,"xTopIm");
								HX_STACK_LINE(54)
								Float xBotRe = xBot->re;		HX_STACK_VAR(xBotRe,"xBotRe");
								HX_STACK_LINE(54)
								Float xBotIm = xBot->im;		HX_STACK_VAR(xBotIm,"xBotIm");
								HX_STACK_LINE(54)
								xTop->re = (xTopRe + xBotRe);
								HX_STACK_LINE(54)
								xTop->im = (xTopIm + xBotIm);
								HX_STACK_LINE(54)
								xBotRe = (xTopRe - xBotRe);
								HX_STACK_LINE(54)
								xBotIm = (xTopIm - xBotIm);
								HX_STACK_LINE(54)
								xBot->re = ((xBotRe * wRe) - (xBotIm * wIm));
								HX_STACK_LINE(54)
								xBot->im = ((xBotRe * wIm) + (xBotIm * wRe));
								HX_STACK_LINE(54)
								xTop = xTop->next;
								HX_STACK_LINE(54)
								xBot = xBot->next;
								HX_STACK_LINE(54)
								Float tRe = wRe;		HX_STACK_VAR(tRe,"tRe");
								HX_STACK_LINE(54)
								wRe = ((wRe * wMulRe) - (wIm * wMulIm));
								HX_STACK_LINE(54)
								wIm = ((tRe * wMulIm) + (wIm * wMulRe));
							}
						}
						HX_STACK_LINE(54)
						hx::AddEq(start,spacing);
					}
					HX_STACK_LINE(54)
					hx::ShrEq(numFlies,(int)1);
					HX_STACK_LINE(54)
					hx::ShrEq(span,(int)1);
					HX_STACK_LINE(54)
					hx::ShrEq(spacing,(int)1);
					HX_STACK_LINE(54)
					hx::ShlEq(wIndexStep,(int)1);
				}
			}
			HX_STACK_LINE(54)
			x = fft1->m_X->__get((int)0).StaticCast< ::FFTElement >();
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				if ((!(((x != null()))))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				int target = x->revTgt;		HX_STACK_VAR(target,"target");
				HX_STACK_LINE(54)
				xRe1[target] = x->re;
				HX_STACK_LINE(54)
				xIm1[target] = x->im;
				HX_STACK_LINE(54)
				x = x->next;
			}
		}
		HX_STACK_LINE(54)
		bool ok = true;		HX_STACK_VAR(ok,"ok");
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(54)
			while((true)){
				HX_STACK_LINE(54)
				if ((!(((_g < (int)1024))))){
					HX_STACK_LINE(54)
					break;
				}
				HX_STACK_LINE(54)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				struct _Function_4_1{
					inline static bool Block( int &i,Array< Float > &xRe2,Array< Float > &xRe1){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","FFTTimingTest.hx",54,0xdec66c8e)
						{
							HX_STACK_LINE(54)
							Float a = xRe1->__get(i);		HX_STACK_VAR(a,"a");
							HX_STACK_LINE(54)
							Float b = xRe2->__get(i);		HX_STACK_VAR(b,"b");
							HX_STACK_LINE(54)
							return (bool((a < (b + .0001))) && bool((a > (b - .0001))));
						}
						return null();
					}
				};
				HX_STACK_LINE(54)
				if ((!(_Function_4_1::Block(i,xRe2,xRe1)))){
					HX_STACK_LINE(54)
					ok = false;
					HX_STACK_LINE(54)
					break;
				}
			}
		}
		HX_STACK_LINE(54)
		this->print(((HX_CSTRING("Haxe translation is ") + ((  ((ok)) ? ::String(HX_CSTRING("")) : ::String(HX_CSTRING("in")) ))) + HX_CSTRING("correct.")));
	}
}
;
	return null();
}

//FFTTimingTest_obj::~FFTTimingTest_obj() { }

Dynamic FFTTimingTest_obj::__CreateEmpty() { return  new FFTTimingTest_obj; }
hx::ObjectPtr< FFTTimingTest_obj > FFTTimingTest_obj::__new()
{  hx::ObjectPtr< FFTTimingTest_obj > result = new FFTTimingTest_obj();
	result->__construct();
	return result;}

Dynamic FFTTimingTest_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FFTTimingTest_obj > result = new FFTTimingTest_obj();
	result->__construct();
	return result;}

int FFTTimingTest_obj::getTimer( ){
	HX_STACK_FRAME("FFTTimingTest","getTimer",0x0bc6134d,"FFTTimingTest.getTimer","FFTTimingTest.hx",56,0xdec66c8e)
	HX_STACK_THIS(this)
	HX_STACK_LINE(56)
	Float _g = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(56)
	Float _g1 = (_g * (int)1000);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(56)
	return ::Std_obj::_int(_g1);
}


HX_DEFINE_DYNAMIC_FUNC0(FFTTimingTest_obj,getTimer,return )

Void FFTTimingTest_obj::checkIfHaxeTranslationIsCorrect( ){
{
		HX_STACK_FRAME("FFTTimingTest","checkIfHaxeTranslationIsCorrect",0x2806bf5c,"FFTTimingTest.checkIfHaxeTranslationIsCorrect","FFTTimingTest.hx",58,0xdec66c8e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(60)
		Array< Float > xRe;		HX_STACK_VAR(xRe,"xRe");
		HX_STACK_LINE(60)
		{
			HX_STACK_LINE(60)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(60)
			xRe = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(61)
		Array< Float > xIm;		HX_STACK_VAR(xIm,"xIm");
		HX_STACK_LINE(61)
		{
			HX_STACK_LINE(61)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(61)
			xIm = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(64)
		Array< Float > xRe2;		HX_STACK_VAR(xRe2,"xRe2");
		HX_STACK_LINE(64)
		{
			HX_STACK_LINE(64)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(64)
			xRe2 = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(65)
		Array< Float > xIm2;		HX_STACK_VAR(xIm2,"xIm2");
		HX_STACK_LINE(65)
		{
			HX_STACK_LINE(65)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(65)
			xIm2 = Array_obj< Float >::__new();
		}
		HX_STACK_LINE(68)
		{
			HX_STACK_LINE(68)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(68)
			while((true)){
				HX_STACK_LINE(68)
				if ((!(((_g < (int)1024))))){
					HX_STACK_LINE(68)
					break;
				}
				HX_STACK_LINE(68)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(69)
				xRe[i] = xRe2[i] = ::Math_obj::cos((Float(((((int)2 * ::Math_obj::PI) * (int)2) * i)) / Float((int)1024)));
				HX_STACK_LINE(70)
				xIm[i] = xIm2[i] = 0.0;
			}
		}
		HX_STACK_LINE(74)
		::FFT fft = ::FFT_obj::__new();		HX_STACK_VAR(fft,"fft");
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			fft->m_logN = (int)10;
			HX_STACK_LINE(75)
			fft->m_N = (int((int)1) << int(fft->m_logN));
			HX_STACK_LINE(75)
			fft->m_invN = (Float(1.0) / Float(fft->m_N));
			HX_STACK_LINE(75)
			Array< ::Dynamic > _g;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(75)
			{
				HX_STACK_LINE(75)
				bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
				HX_STACK_LINE(75)
				_g = Array_obj< ::Dynamic >::__new();
			}
			HX_STACK_LINE(75)
			fft->m_X = _g;
			HX_STACK_LINE(75)
			{
				HX_STACK_LINE(75)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(75)
				int _g2 = fft->m_N;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(75)
				while((true)){
					HX_STACK_LINE(75)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(75)
						break;
					}
					HX_STACK_LINE(75)
					int k = (_g1)++;		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(75)
					fft->m_X[k] = ::FFTElement_obj::__new();
				}
			}
			HX_STACK_LINE(75)
			{
				HX_STACK_LINE(75)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(75)
				int _g2 = (fft->m_N - (int)1);		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(75)
				while((true)){
					HX_STACK_LINE(75)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(75)
						break;
					}
					HX_STACK_LINE(75)
					int k = (_g1)++;		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(75)
					fft->m_X->__get(k).StaticCast< ::FFTElement >()->next = fft->m_X->__get((k + (int)1)).StaticCast< ::FFTElement >();
				}
			}
			HX_STACK_LINE(75)
			{
				HX_STACK_LINE(75)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(75)
				int _g2 = fft->m_N;		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(75)
				while((true)){
					HX_STACK_LINE(75)
					if ((!(((_g1 < _g2))))){
						HX_STACK_LINE(75)
						break;
					}
					HX_STACK_LINE(75)
					int k = (_g1)++;		HX_STACK_VAR(k,"k");
					HX_STACK_LINE(75)
					int _g11;		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(75)
					{
						HX_STACK_LINE(75)
						int x = k;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(75)
						int y = (int)0;		HX_STACK_VAR(y,"y");
						HX_STACK_LINE(75)
						{
							HX_STACK_LINE(75)
							int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
							HX_STACK_LINE(75)
							while((true)){
								HX_STACK_LINE(75)
								if ((!(((_g3 < (int)10))))){
									HX_STACK_LINE(75)
									break;
								}
								HX_STACK_LINE(75)
								int i = (_g3)++;		HX_STACK_VAR(i,"i");
								HX_STACK_LINE(75)
								hx::ShlEq(y,(int)1);
								HX_STACK_LINE(75)
								hx::OrEq(y,(int(x) & int((int)1)));
								HX_STACK_LINE(75)
								hx::ShrEq(x,(int)1);
							}
						}
						HX_STACK_LINE(75)
						_g11 = y;
					}
					HX_STACK_LINE(75)
					fft->m_X->__get(k).StaticCast< ::FFTElement >()->revTgt = _g11;
				}
			}
		}
		HX_STACK_LINE(78)
		{
			HX_STACK_LINE(78)
			int numFlies = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(numFlies,"numFlies");
			HX_STACK_LINE(78)
			int span = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(span,"span");
			HX_STACK_LINE(78)
			int spacing = fft->m_N;		HX_STACK_VAR(spacing,"spacing");
			HX_STACK_LINE(78)
			int wIndexStep = (int)1;		HX_STACK_VAR(wIndexStep,"wIndexStep");
			HX_STACK_LINE(78)
			::FFTElement x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(78)
			int k = (int)0;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(78)
			Float scale = 1.0;		HX_STACK_VAR(scale,"scale");
			HX_STACK_LINE(78)
			while((true)){
				HX_STACK_LINE(78)
				if ((!(((x != null()))))){
					HX_STACK_LINE(78)
					break;
				}
				HX_STACK_LINE(78)
				x->re = (scale * xRe->__get(k));
				HX_STACK_LINE(78)
				x->im = (scale * xIm->__get(k));
				HX_STACK_LINE(78)
				x = x->next;
				HX_STACK_LINE(78)
				(k)++;
			}
			HX_STACK_LINE(78)
			Dynamic math = hx::ClassOf< ::Math >();		HX_STACK_VAR(math,"math");
			HX_STACK_LINE(78)
			{
				HX_STACK_LINE(78)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(78)
				int _g = fft->m_logN;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(78)
				while((true)){
					HX_STACK_LINE(78)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(78)
						break;
					}
					HX_STACK_LINE(78)
					int stage = (_g1)++;		HX_STACK_VAR(stage,"stage");
					HX_STACK_LINE(78)
					Float wAngleInc = (Float(((wIndexStep * 2.0) * math->__Field(HX_CSTRING("PI"),true))) / Float(fft->m_N));		HX_STACK_VAR(wAngleInc,"wAngleInc");
					HX_STACK_LINE(78)
					hx::MultEq(wAngleInc,(int)-1);
					HX_STACK_LINE(78)
					Float wMulRe = math->__Field(HX_CSTRING("cos"),true)(wAngleInc);		HX_STACK_VAR(wMulRe,"wMulRe");
					HX_STACK_LINE(78)
					Float wMulIm = math->__Field(HX_CSTRING("sin"),true)(wAngleInc);		HX_STACK_VAR(wMulIm,"wMulIm");
					HX_STACK_LINE(78)
					int start = (int)0;		HX_STACK_VAR(start,"start");
					HX_STACK_LINE(78)
					while((true)){
						HX_STACK_LINE(78)
						if ((!(((start < fft->m_N))))){
							HX_STACK_LINE(78)
							break;
						}
						HX_STACK_LINE(78)
						::FFTElement xTop = fft->m_X->__get(start).StaticCast< ::FFTElement >();		HX_STACK_VAR(xTop,"xTop");
						HX_STACK_LINE(78)
						::FFTElement xBot = fft->m_X->__get((start + span)).StaticCast< ::FFTElement >();		HX_STACK_VAR(xBot,"xBot");
						HX_STACK_LINE(78)
						Float wRe = 1.0;		HX_STACK_VAR(wRe,"wRe");
						HX_STACK_LINE(78)
						Float wIm = 0.0;		HX_STACK_VAR(wIm,"wIm");
						HX_STACK_LINE(78)
						{
							HX_STACK_LINE(78)
							int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(78)
							while((true)){
								HX_STACK_LINE(78)
								if ((!(((_g2 < numFlies))))){
									HX_STACK_LINE(78)
									break;
								}
								HX_STACK_LINE(78)
								int flyCount = (_g2)++;		HX_STACK_VAR(flyCount,"flyCount");
								HX_STACK_LINE(78)
								Float xTopRe = xTop->re;		HX_STACK_VAR(xTopRe,"xTopRe");
								HX_STACK_LINE(78)
								Float xTopIm = xTop->im;		HX_STACK_VAR(xTopIm,"xTopIm");
								HX_STACK_LINE(78)
								Float xBotRe = xBot->re;		HX_STACK_VAR(xBotRe,"xBotRe");
								HX_STACK_LINE(78)
								Float xBotIm = xBot->im;		HX_STACK_VAR(xBotIm,"xBotIm");
								HX_STACK_LINE(78)
								xTop->re = (xTopRe + xBotRe);
								HX_STACK_LINE(78)
								xTop->im = (xTopIm + xBotIm);
								HX_STACK_LINE(78)
								xBotRe = (xTopRe - xBotRe);
								HX_STACK_LINE(78)
								xBotIm = (xTopIm - xBotIm);
								HX_STACK_LINE(78)
								xBot->re = ((xBotRe * wRe) - (xBotIm * wIm));
								HX_STACK_LINE(78)
								xBot->im = ((xBotRe * wIm) + (xBotIm * wRe));
								HX_STACK_LINE(78)
								xTop = xTop->next;
								HX_STACK_LINE(78)
								xBot = xBot->next;
								HX_STACK_LINE(78)
								Float tRe = wRe;		HX_STACK_VAR(tRe,"tRe");
								HX_STACK_LINE(78)
								wRe = ((wRe * wMulRe) - (wIm * wMulIm));
								HX_STACK_LINE(78)
								wIm = ((tRe * wMulIm) + (wIm * wMulRe));
							}
						}
						HX_STACK_LINE(78)
						hx::AddEq(start,spacing);
					}
					HX_STACK_LINE(78)
					hx::ShrEq(numFlies,(int)1);
					HX_STACK_LINE(78)
					hx::ShrEq(span,(int)1);
					HX_STACK_LINE(78)
					hx::ShrEq(spacing,(int)1);
					HX_STACK_LINE(78)
					hx::ShlEq(wIndexStep,(int)1);
				}
			}
			HX_STACK_LINE(78)
			x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();
			HX_STACK_LINE(78)
			while((true)){
				HX_STACK_LINE(78)
				if ((!(((x != null()))))){
					HX_STACK_LINE(78)
					break;
				}
				HX_STACK_LINE(78)
				int target = x->revTgt;		HX_STACK_VAR(target,"target");
				HX_STACK_LINE(78)
				xRe[target] = x->re;
				HX_STACK_LINE(78)
				xIm[target] = x->im;
				HX_STACK_LINE(78)
				x = x->next;
			}
		}
		HX_STACK_LINE(79)
		{
			HX_STACK_LINE(79)
			int numFlies = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(numFlies,"numFlies");
			HX_STACK_LINE(79)
			int span = (int(fft->m_N) >> int((int)1));		HX_STACK_VAR(span,"span");
			HX_STACK_LINE(79)
			int spacing = fft->m_N;		HX_STACK_VAR(spacing,"spacing");
			HX_STACK_LINE(79)
			int wIndexStep = (int)1;		HX_STACK_VAR(wIndexStep,"wIndexStep");
			HX_STACK_LINE(79)
			::FFTElement x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();		HX_STACK_VAR(x,"x");
			HX_STACK_LINE(79)
			int k = (int)0;		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(79)
			Float scale = fft->m_invN;		HX_STACK_VAR(scale,"scale");
			HX_STACK_LINE(79)
			while((true)){
				HX_STACK_LINE(79)
				if ((!(((x != null()))))){
					HX_STACK_LINE(79)
					break;
				}
				HX_STACK_LINE(79)
				x->re = (scale * xRe->__get(k));
				HX_STACK_LINE(79)
				x->im = (scale * xIm->__get(k));
				HX_STACK_LINE(79)
				x = x->next;
				HX_STACK_LINE(79)
				(k)++;
			}
			HX_STACK_LINE(79)
			Dynamic math = hx::ClassOf< ::Math >();		HX_STACK_VAR(math,"math");
			HX_STACK_LINE(79)
			{
				HX_STACK_LINE(79)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(79)
				int _g = fft->m_logN;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(79)
				while((true)){
					HX_STACK_LINE(79)
					if ((!(((_g1 < _g))))){
						HX_STACK_LINE(79)
						break;
					}
					HX_STACK_LINE(79)
					int stage = (_g1)++;		HX_STACK_VAR(stage,"stage");
					HX_STACK_LINE(79)
					Float wAngleInc = (Float(((wIndexStep * 2.0) * math->__Field(HX_CSTRING("PI"),true))) / Float(fft->m_N));		HX_STACK_VAR(wAngleInc,"wAngleInc");
					HX_STACK_LINE(79)
					Float wMulRe = math->__Field(HX_CSTRING("cos"),true)(wAngleInc);		HX_STACK_VAR(wMulRe,"wMulRe");
					HX_STACK_LINE(79)
					Float wMulIm = math->__Field(HX_CSTRING("sin"),true)(wAngleInc);		HX_STACK_VAR(wMulIm,"wMulIm");
					HX_STACK_LINE(79)
					int start = (int)0;		HX_STACK_VAR(start,"start");
					HX_STACK_LINE(79)
					while((true)){
						HX_STACK_LINE(79)
						if ((!(((start < fft->m_N))))){
							HX_STACK_LINE(79)
							break;
						}
						HX_STACK_LINE(79)
						::FFTElement xTop = fft->m_X->__get(start).StaticCast< ::FFTElement >();		HX_STACK_VAR(xTop,"xTop");
						HX_STACK_LINE(79)
						::FFTElement xBot = fft->m_X->__get((start + span)).StaticCast< ::FFTElement >();		HX_STACK_VAR(xBot,"xBot");
						HX_STACK_LINE(79)
						Float wRe = 1.0;		HX_STACK_VAR(wRe,"wRe");
						HX_STACK_LINE(79)
						Float wIm = 0.0;		HX_STACK_VAR(wIm,"wIm");
						HX_STACK_LINE(79)
						{
							HX_STACK_LINE(79)
							int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
							HX_STACK_LINE(79)
							while((true)){
								HX_STACK_LINE(79)
								if ((!(((_g2 < numFlies))))){
									HX_STACK_LINE(79)
									break;
								}
								HX_STACK_LINE(79)
								int flyCount = (_g2)++;		HX_STACK_VAR(flyCount,"flyCount");
								HX_STACK_LINE(79)
								Float xTopRe = xTop->re;		HX_STACK_VAR(xTopRe,"xTopRe");
								HX_STACK_LINE(79)
								Float xTopIm = xTop->im;		HX_STACK_VAR(xTopIm,"xTopIm");
								HX_STACK_LINE(79)
								Float xBotRe = xBot->re;		HX_STACK_VAR(xBotRe,"xBotRe");
								HX_STACK_LINE(79)
								Float xBotIm = xBot->im;		HX_STACK_VAR(xBotIm,"xBotIm");
								HX_STACK_LINE(79)
								xTop->re = (xTopRe + xBotRe);
								HX_STACK_LINE(79)
								xTop->im = (xTopIm + xBotIm);
								HX_STACK_LINE(79)
								xBotRe = (xTopRe - xBotRe);
								HX_STACK_LINE(79)
								xBotIm = (xTopIm - xBotIm);
								HX_STACK_LINE(79)
								xBot->re = ((xBotRe * wRe) - (xBotIm * wIm));
								HX_STACK_LINE(79)
								xBot->im = ((xBotRe * wIm) + (xBotIm * wRe));
								HX_STACK_LINE(79)
								xTop = xTop->next;
								HX_STACK_LINE(79)
								xBot = xBot->next;
								HX_STACK_LINE(79)
								Float tRe = wRe;		HX_STACK_VAR(tRe,"tRe");
								HX_STACK_LINE(79)
								wRe = ((wRe * wMulRe) - (wIm * wMulIm));
								HX_STACK_LINE(79)
								wIm = ((tRe * wMulIm) + (wIm * wMulRe));
							}
						}
						HX_STACK_LINE(79)
						hx::AddEq(start,spacing);
					}
					HX_STACK_LINE(79)
					hx::ShrEq(numFlies,(int)1);
					HX_STACK_LINE(79)
					hx::ShrEq(span,(int)1);
					HX_STACK_LINE(79)
					hx::ShrEq(spacing,(int)1);
					HX_STACK_LINE(79)
					hx::ShlEq(wIndexStep,(int)1);
				}
			}
			HX_STACK_LINE(79)
			x = fft->m_X->__get((int)0).StaticCast< ::FFTElement >();
			HX_STACK_LINE(79)
			while((true)){
				HX_STACK_LINE(79)
				if ((!(((x != null()))))){
					HX_STACK_LINE(79)
					break;
				}
				HX_STACK_LINE(79)
				int target = x->revTgt;		HX_STACK_VAR(target,"target");
				HX_STACK_LINE(79)
				xRe[target] = x->re;
				HX_STACK_LINE(79)
				xIm[target] = x->im;
				HX_STACK_LINE(79)
				x = x->next;
			}
		}
		HX_STACK_LINE(82)
		bool ok = true;		HX_STACK_VAR(ok,"ok");
		HX_STACK_LINE(83)
		{
			HX_STACK_LINE(83)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(83)
			while((true)){
				HX_STACK_LINE(83)
				if ((!(((_g < (int)1024))))){
					HX_STACK_LINE(83)
					break;
				}
				HX_STACK_LINE(83)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				struct _Function_3_1{
					inline static bool Block( int &i,Array< Float > &xRe2,Array< Float > &xRe){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","FFTTimingTest.hx",84,0xdec66c8e)
						{
							HX_STACK_LINE(84)
							Float a = xRe->__get(i);		HX_STACK_VAR(a,"a");
							HX_STACK_LINE(84)
							Float b = xRe2->__get(i);		HX_STACK_VAR(b,"b");
							HX_STACK_LINE(84)
							return (bool((a < (b + .0001))) && bool((a > (b - .0001))));
						}
						return null();
					}
				};
				HX_STACK_LINE(84)
				if ((!(_Function_3_1::Block(i,xRe2,xRe)))){
					HX_STACK_LINE(85)
					ok = false;
					HX_STACK_LINE(86)
					break;
				}
			}
		}
		HX_STACK_LINE(89)
		this->print(((HX_CSTRING("Haxe translation is ") + ((  ((ok)) ? ::String(HX_CSTRING("")) : ::String(HX_CSTRING("in")) ))) + HX_CSTRING("correct.")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FFTTimingTest_obj,checkIfHaxeTranslationIsCorrect,(void))

bool FFTTimingTest_obj::almostEqual( Float a,Float b){
	HX_STACK_FRAME("FFTTimingTest","almostEqual",0x55aba8a8,"FFTTimingTest.almostEqual","FFTTimingTest.hx",92,0xdec66c8e)
	HX_STACK_THIS(this)
	HX_STACK_ARG(a,"a")
	HX_STACK_ARG(b,"b")
	HX_STACK_LINE(92)
	return (bool((a < (b + .0001))) && bool((a > (b - .0001))));
}


HX_DEFINE_DYNAMIC_FUNC2(FFTTimingTest_obj,almostEqual,return )

Void FFTTimingTest_obj::initTest( ){
{
		HX_STACK_FRAME("FFTTimingTest","initTest",0xed6a3b80,"FFTTimingTest.initTest","FFTTimingTest.hx",112,0xdec66c8e)
		HX_STACK_THIS(this)
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(FFTTimingTest_obj,initTest,(void))

Void FFTTimingTest_obj::print( ::String s){
{
		HX_STACK_FRAME("FFTTimingTest","print",0x796ec96f,"FFTTimingTest.print","FFTTimingTest.hx",119,0xdec66c8e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(s,"s")
		HX_STACK_LINE(119)
		::haxe::Log_obj::trace(s,hx::SourceInfo(HX_CSTRING("FFTTimingTest.hx"),119,HX_CSTRING("FFTTimingTest"),HX_CSTRING("print")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FFTTimingTest_obj,print,(void))

int FFTTimingTest_obj::LOG_N;

int FFTTimingTest_obj::N;

int FFTTimingTest_obj::NUM_LOOPS;

Void FFTTimingTest_obj::main( ){
{
		HX_STACK_FRAME("FFTTimingTest","main",0xf1e22537,"FFTTimingTest.main","FFTTimingTest.hx",17,0xdec66c8e)
		HX_STACK_LINE(17)
		::FFTTimingTest_obj::__new();
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(FFTTimingTest_obj,main,(void))

Float FFTTimingTest_obj::PRECISION;


FFTTimingTest_obj::FFTTimingTest_obj()
{
}

Dynamic FFTTimingTest_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getTimer") ) { return getTimer_dyn(); }
		if (HX_FIELD_EQ(inName,"initTest") ) { return initTest_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"almostEqual") ) { return almostEqual_dyn(); }
		break;
	case 31:
		if (HX_FIELD_EQ(inName,"checkIfHaxeTranslationIsCorrect") ) { return checkIfHaxeTranslationIsCorrect_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FFTTimingTest_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FFTTimingTest_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("LOG_N"),
	HX_CSTRING("N"),
	HX_CSTRING("NUM_LOOPS"),
	HX_CSTRING("main"),
	HX_CSTRING("PRECISION"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("getTimer"),
	HX_CSTRING("checkIfHaxeTranslationIsCorrect"),
	HX_CSTRING("almostEqual"),
	HX_CSTRING("initTest"),
	HX_CSTRING("print"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FFTTimingTest_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FFTTimingTest_obj::LOG_N,"LOG_N");
	HX_MARK_MEMBER_NAME(FFTTimingTest_obj::N,"N");
	HX_MARK_MEMBER_NAME(FFTTimingTest_obj::NUM_LOOPS,"NUM_LOOPS");
	HX_MARK_MEMBER_NAME(FFTTimingTest_obj::PRECISION,"PRECISION");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FFTTimingTest_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FFTTimingTest_obj::LOG_N,"LOG_N");
	HX_VISIT_MEMBER_NAME(FFTTimingTest_obj::N,"N");
	HX_VISIT_MEMBER_NAME(FFTTimingTest_obj::NUM_LOOPS,"NUM_LOOPS");
	HX_VISIT_MEMBER_NAME(FFTTimingTest_obj::PRECISION,"PRECISION");
};

#endif

Class FFTTimingTest_obj::__mClass;

void FFTTimingTest_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("FFTTimingTest"), hx::TCanCast< FFTTimingTest_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void FFTTimingTest_obj::__boot()
{
	LOG_N= (int)10;
	N= (int)1024;
	NUM_LOOPS= (int)1000;
	PRECISION= .0001;
}

