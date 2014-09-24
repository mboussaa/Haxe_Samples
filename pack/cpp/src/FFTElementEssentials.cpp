#include <hxcpp.h>

#ifndef INCLUDED_FFTElementEssentials
#include <FFTElementEssentials.h>
#endif

Void FFTElementEssentials_obj::__construct()
{
HX_STACK_FRAME("FFTElementEssentials","new",0xdb7ddfbf,"FFTElementEssentials.new","FFT.hx",214,0x82b10c2a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(215)
	this->re = (int)0;
	HX_STACK_LINE(216)
	this->im = (int)0;
}
;
	return null();
}

//FFTElementEssentials_obj::~FFTElementEssentials_obj() { }

Dynamic FFTElementEssentials_obj::__CreateEmpty() { return  new FFTElementEssentials_obj; }
hx::ObjectPtr< FFTElementEssentials_obj > FFTElementEssentials_obj::__new()
{  hx::ObjectPtr< FFTElementEssentials_obj > result = new FFTElementEssentials_obj();
	result->__construct();
	return result;}

Dynamic FFTElementEssentials_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FFTElementEssentials_obj > result = new FFTElementEssentials_obj();
	result->__construct();
	return result;}


FFTElementEssentials_obj::FFTElementEssentials_obj()
{
}

Dynamic FFTElementEssentials_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"re") ) { return re; }
		if (HX_FIELD_EQ(inName,"im") ) { return im; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"revTgt") ) { return revTgt; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FFTElementEssentials_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"re") ) { re=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"im") ) { im=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"revTgt") ) { revTgt=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FFTElementEssentials_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("re"));
	outFields->push(HX_CSTRING("im"));
	outFields->push(HX_CSTRING("revTgt"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsFloat,(int)offsetof(FFTElementEssentials_obj,re),HX_CSTRING("re")},
	{hx::fsFloat,(int)offsetof(FFTElementEssentials_obj,im),HX_CSTRING("im")},
	{hx::fsInt,(int)offsetof(FFTElementEssentials_obj,revTgt),HX_CSTRING("revTgt")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("re"),
	HX_CSTRING("im"),
	HX_CSTRING("revTgt"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FFTElementEssentials_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FFTElementEssentials_obj::__mClass,"__mClass");
};

#endif

Class FFTElementEssentials_obj::__mClass;

void FFTElementEssentials_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("FFTElementEssentials"), hx::TCanCast< FFTElementEssentials_obj> ,sStaticFields,sMemberFields,
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

void FFTElementEssentials_obj::__boot()
{
}

