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
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif

Void FFT_obj::__construct()
{
HX_STACK_FRAME("FFT","new",0xd83e1606,"FFT.new","FFT.hx",45,0x82b10c2a)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//FFT_obj::~FFT_obj() { }

Dynamic FFT_obj::__CreateEmpty() { return  new FFT_obj; }
hx::ObjectPtr< FFT_obj > FFT_obj::__new()
{  hx::ObjectPtr< FFT_obj > result = new FFT_obj();
	result->__construct();
	return result;}

Dynamic FFT_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FFT_obj > result = new FFT_obj();
	result->__construct();
	return result;}

Void FFT_obj::init( int logN){
{
		HX_STACK_FRAME("FFT","init",0x5acde6aa,"FFT.init","FFT.hx",55,0x82b10c2a)
		HX_STACK_THIS(this)
		HX_STACK_ARG(logN,"logN")
		HX_STACK_LINE(56)
		this->m_logN = logN;
		HX_STACK_LINE(57)
		this->m_N = (int((int)1) << int(this->m_logN));
		HX_STACK_LINE(58)
		this->m_invN = (Float(1.0) / Float(this->m_N));
		HX_STACK_LINE(61)
		Array< ::Dynamic > _g;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(61)
		{
			HX_STACK_LINE(61)
			bool fixed = false;		HX_STACK_VAR(fixed,"fixed");
			HX_STACK_LINE(61)
			_g = Array_obj< ::Dynamic >::__new();
		}
		HX_STACK_LINE(61)
		this->m_X = _g;
		HX_STACK_LINE(62)
		{
			HX_STACK_LINE(62)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(62)
			int _g2 = this->m_N;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(62)
			while((true)){
				HX_STACK_LINE(62)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(62)
					break;
				}
				HX_STACK_LINE(62)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(63)
				this->m_X[k] = ::FFTElement_obj::__new();
			}
		}
		HX_STACK_LINE(66)
		{
			HX_STACK_LINE(66)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(66)
			int _g2 = (this->m_N - (int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(66)
			while((true)){
				HX_STACK_LINE(66)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(66)
					break;
				}
				HX_STACK_LINE(66)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(67)
				this->m_X->__get(k).StaticCast< ::FFTElement >()->next = this->m_X->__get((k + (int)1)).StaticCast< ::FFTElement >();
			}
		}
		HX_STACK_LINE(70)
		{
			HX_STACK_LINE(70)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(70)
			int _g2 = this->m_N;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(70)
			while((true)){
				HX_STACK_LINE(70)
				if ((!(((_g1 < _g2))))){
					HX_STACK_LINE(70)
					break;
				}
				HX_STACK_LINE(70)
				int k = (_g1)++;		HX_STACK_VAR(k,"k");
				HX_STACK_LINE(71)
				int _g11;		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(71)
				{
					HX_STACK_LINE(71)
					int x = k;		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(71)
					int y = (int)0;		HX_STACK_VAR(y,"y");
					HX_STACK_LINE(71)
					{
						HX_STACK_LINE(71)
						int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(71)
						while((true)){
							HX_STACK_LINE(71)
							if ((!(((_g3 < logN))))){
								HX_STACK_LINE(71)
								break;
							}
							HX_STACK_LINE(71)
							int i = (_g3)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(71)
							hx::ShlEq(y,(int)1);
							HX_STACK_LINE(71)
							hx::OrEq(y,(int(x) & int((int)1)));
							HX_STACK_LINE(71)
							hx::ShrEq(x,(int)1);
						}
					}
					HX_STACK_LINE(71)
					_g11 = y;
				}
				HX_STACK_LINE(71)
				this->m_X->__get(k).StaticCast< ::FFTElement >()->revTgt = _g11;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FFT_obj,init,(void))

Void FFT_obj::run( Array< Float > xRe,Array< Float > xIm,hx::Null< bool >  __o_inverse){
bool inverse = __o_inverse.Default(false);
	HX_STACK_FRAME("FFT","run",0xd8412cf1,"FFT.run","FFT.hx",85,0x82b10c2a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(xRe,"xRe")
	HX_STACK_ARG(xIm,"xIm")
	HX_STACK_ARG(inverse,"inverse")
{
		HX_STACK_LINE(86)
		int numFlies = (int(this->m_N) >> int((int)1));		HX_STACK_VAR(numFlies,"numFlies");
		HX_STACK_LINE(87)
		int span = (int(this->m_N) >> int((int)1));		HX_STACK_VAR(span,"span");
		HX_STACK_LINE(88)
		int spacing = this->m_N;		HX_STACK_VAR(spacing,"spacing");
		HX_STACK_LINE(89)
		int wIndexStep = (int)1;		HX_STACK_VAR(wIndexStep,"wIndexStep");
		HX_STACK_LINE(93)
		::FFTElement x = this->m_X->__get((int)0).StaticCast< ::FFTElement >();		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(94)
		int k = (int)0;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(95)
		Float scale;		HX_STACK_VAR(scale,"scale");
		HX_STACK_LINE(95)
		if ((inverse)){
			HX_STACK_LINE(95)
			scale = this->m_invN;
		}
		else{
			HX_STACK_LINE(95)
			scale = 1.0;
		}
		HX_STACK_LINE(96)
		while((true)){
			HX_STACK_LINE(96)
			if ((!(((x != null()))))){
				HX_STACK_LINE(96)
				break;
			}
			HX_STACK_LINE(98)
			x->re = (scale * xRe->__get(k));
			HX_STACK_LINE(99)
			x->im = (scale * xIm->__get(k));
			HX_STACK_LINE(100)
			x = x->next;
			HX_STACK_LINE(101)
			(k)++;
		}
		HX_STACK_LINE(103)
		Dynamic math = hx::ClassOf< ::Math >();		HX_STACK_VAR(math,"math");
		HX_STACK_LINE(105)
		{
			HX_STACK_LINE(105)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(105)
			int _g = this->m_logN;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(105)
			while((true)){
				HX_STACK_LINE(105)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(105)
					break;
				}
				HX_STACK_LINE(105)
				int stage = (_g1)++;		HX_STACK_VAR(stage,"stage");
				HX_STACK_LINE(114)
				Float wAngleInc = (Float(((wIndexStep * 2.0) * math->__Field(HX_CSTRING("PI"),true))) / Float(this->m_N));		HX_STACK_VAR(wAngleInc,"wAngleInc");
				HX_STACK_LINE(115)
				if ((!(inverse))){
					HX_STACK_LINE(116)
					hx::MultEq(wAngleInc,(int)-1);
				}
				HX_STACK_LINE(117)
				Float wMulRe = math->__Field(HX_CSTRING("cos"),true)(wAngleInc);		HX_STACK_VAR(wMulRe,"wMulRe");
				HX_STACK_LINE(118)
				Float wMulIm = math->__Field(HX_CSTRING("sin"),true)(wAngleInc);		HX_STACK_VAR(wMulIm,"wMulIm");
				HX_STACK_LINE(120)
				int start = (int)0;		HX_STACK_VAR(start,"start");
				HX_STACK_LINE(121)
				while((true)){
					HX_STACK_LINE(121)
					if ((!(((start < this->m_N))))){
						HX_STACK_LINE(121)
						break;
					}
					HX_STACK_LINE(122)
					::FFTElement xTop = this->m_X->__get(start).StaticCast< ::FFTElement >();		HX_STACK_VAR(xTop,"xTop");
					HX_STACK_LINE(123)
					::FFTElement xBot = this->m_X->__get((start + span)).StaticCast< ::FFTElement >();		HX_STACK_VAR(xBot,"xBot");
					HX_STACK_LINE(125)
					Float wRe = 1.0;		HX_STACK_VAR(wRe,"wRe");
					HX_STACK_LINE(126)
					Float wIm = 0.0;		HX_STACK_VAR(wIm,"wIm");
					HX_STACK_LINE(129)
					{
						HX_STACK_LINE(129)
						int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(129)
						while((true)){
							HX_STACK_LINE(129)
							if ((!(((_g2 < numFlies))))){
								HX_STACK_LINE(129)
								break;
							}
							HX_STACK_LINE(129)
							int flyCount = (_g2)++;		HX_STACK_VAR(flyCount,"flyCount");
							HX_STACK_LINE(132)
							Float xTopRe = xTop->re;		HX_STACK_VAR(xTopRe,"xTopRe");
							HX_STACK_LINE(133)
							Float xTopIm = xTop->im;		HX_STACK_VAR(xTopIm,"xTopIm");
							HX_STACK_LINE(134)
							Float xBotRe = xBot->re;		HX_STACK_VAR(xBotRe,"xBotRe");
							HX_STACK_LINE(135)
							Float xBotIm = xBot->im;		HX_STACK_VAR(xBotIm,"xBotIm");
							HX_STACK_LINE(138)
							xTop->re = (xTopRe + xBotRe);
							HX_STACK_LINE(139)
							xTop->im = (xTopIm + xBotIm);
							HX_STACK_LINE(143)
							xBotRe = (xTopRe - xBotRe);
							HX_STACK_LINE(144)
							xBotIm = (xTopIm - xBotIm);
							HX_STACK_LINE(145)
							xBot->re = ((xBotRe * wRe) - (xBotIm * wIm));
							HX_STACK_LINE(146)
							xBot->im = ((xBotRe * wIm) + (xBotIm * wRe));
							HX_STACK_LINE(149)
							xTop = xTop->next;
							HX_STACK_LINE(150)
							xBot = xBot->next;
							HX_STACK_LINE(155)
							Float tRe = wRe;		HX_STACK_VAR(tRe,"tRe");
							HX_STACK_LINE(156)
							wRe = ((wRe * wMulRe) - (wIm * wMulIm));
							HX_STACK_LINE(157)
							wIm = ((tRe * wMulIm) + (wIm * wMulRe));
						}
					}
					HX_STACK_LINE(159)
					hx::AddEq(start,spacing);
				}
				HX_STACK_LINE(162)
				hx::ShrEq(numFlies,(int)1);
				HX_STACK_LINE(163)
				hx::ShrEq(span,(int)1);
				HX_STACK_LINE(164)
				hx::ShrEq(spacing,(int)1);
				HX_STACK_LINE(165)
				hx::ShlEq(wIndexStep,(int)1);
			}
		}
		HX_STACK_LINE(171)
		x = this->m_X->__get((int)0).StaticCast< ::FFTElement >();
		HX_STACK_LINE(172)
		while((true)){
			HX_STACK_LINE(172)
			if ((!(((x != null()))))){
				HX_STACK_LINE(172)
				break;
			}
			HX_STACK_LINE(174)
			int target = x->revTgt;		HX_STACK_VAR(target,"target");
			HX_STACK_LINE(175)
			xRe[target] = x->re;
			HX_STACK_LINE(176)
			xIm[target] = x->im;
			HX_STACK_LINE(177)
			x = x->next;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(FFT_obj,run,(void))

int FFT_obj::BitReverse( int x,int numBits){
	HX_STACK_FRAME("FFT","BitReverse",0xf42e6b0f,"FFT.BitReverse","FFT.hx",191,0x82b10c2a)
	HX_STACK_THIS(this)
	HX_STACK_ARG(x,"x")
	HX_STACK_ARG(numBits,"numBits")
	HX_STACK_LINE(192)
	int y = (int)0;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(193)
	{
		HX_STACK_LINE(193)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(193)
		while((true)){
			HX_STACK_LINE(193)
			if ((!(((_g < numBits))))){
				HX_STACK_LINE(193)
				break;
			}
			HX_STACK_LINE(193)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(195)
			hx::ShlEq(y,(int)1);
			HX_STACK_LINE(196)
			hx::OrEq(y,(int(x) & int((int)1)));
			HX_STACK_LINE(197)
			hx::ShrEq(x,(int)1);
		}
	}
	HX_STACK_LINE(199)
	return y;
}


HX_DEFINE_DYNAMIC_FUNC2(FFT_obj,BitReverse,return )

bool FFT_obj::FORWARD;

bool FFT_obj::INVERSE;

Dynamic FFT_obj::newArray( hx::Null< int >  __o_len,hx::Null< bool >  __o_fixed){
int len = __o_len.Default(0);
bool fixed = __o_fixed.Default(false);
	HX_STACK_FRAME("FFT","newArray",0x7fd331b3,"FFT.newArray","FFT.hx",203,0x82b10c2a)
	HX_STACK_ARG(len,"len")
	HX_STACK_ARG(fixed,"fixed")
{
		HX_STACK_LINE(203)
		return Dynamic( Array_obj<Dynamic>::__new() );
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(FFT_obj,newArray,return )


FFT_obj::FFT_obj()
{
}

void FFT_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FFT);
	HX_MARK_MEMBER_NAME(m_logN,"m_logN");
	HX_MARK_MEMBER_NAME(m_N,"m_N");
	HX_MARK_MEMBER_NAME(m_invN,"m_invN");
	HX_MARK_MEMBER_NAME(m_X,"m_X");
	HX_MARK_END_CLASS();
}

void FFT_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m_logN,"m_logN");
	HX_VISIT_MEMBER_NAME(m_N,"m_N");
	HX_VISIT_MEMBER_NAME(m_invN,"m_invN");
	HX_VISIT_MEMBER_NAME(m_X,"m_X");
}

Dynamic FFT_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_N") ) { return m_N; }
		if (HX_FIELD_EQ(inName,"m_X") ) { return m_X; }
		if (HX_FIELD_EQ(inName,"run") ) { return run_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_logN") ) { return m_logN; }
		if (HX_FIELD_EQ(inName,"m_invN") ) { return m_invN; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"newArray") ) { return newArray_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"BitReverse") ) { return BitReverse_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FFT_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"m_N") ) { m_N=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_X") ) { m_X=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"m_logN") ) { m_logN=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"m_invN") ) { m_invN=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FFT_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m_logN"));
	outFields->push(HX_CSTRING("m_N"));
	outFields->push(HX_CSTRING("m_invN"));
	outFields->push(HX_CSTRING("m_X"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FORWARD"),
	HX_CSTRING("INVERSE"),
	HX_CSTRING("newArray"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(FFT_obj,m_logN),HX_CSTRING("m_logN")},
	{hx::fsInt,(int)offsetof(FFT_obj,m_N),HX_CSTRING("m_N")},
	{hx::fsFloat,(int)offsetof(FFT_obj,m_invN),HX_CSTRING("m_invN")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(FFT_obj,m_X),HX_CSTRING("m_X")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("m_logN"),
	HX_CSTRING("m_N"),
	HX_CSTRING("m_invN"),
	HX_CSTRING("m_X"),
	HX_CSTRING("init"),
	HX_CSTRING("run"),
	HX_CSTRING("BitReverse"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FFT_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FFT_obj::FORWARD,"FORWARD");
	HX_MARK_MEMBER_NAME(FFT_obj::INVERSE,"INVERSE");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FFT_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FFT_obj::FORWARD,"FORWARD");
	HX_VISIT_MEMBER_NAME(FFT_obj::INVERSE,"INVERSE");
};

#endif

Class FFT_obj::__mClass;

void FFT_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("FFT"), hx::TCanCast< FFT_obj> ,sStaticFields,sMemberFields,
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

void FFT_obj::__boot()
{
	FORWARD= false;
	INVERSE= true;
}

