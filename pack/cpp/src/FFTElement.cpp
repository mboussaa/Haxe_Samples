#include <hxcpp.h>

#ifndef INCLUDED_FFTElement
#include <FFTElement.h>
#endif
#ifndef INCLUDED_FFTElementEssentials
#include <FFTElementEssentials.h>
#endif

Void FFTElement_obj::__construct()
{
HX_STACK_FRAME("FFTElement","new",0x9c5e0afa,"FFTElement.new","FFT.hx",229,0x82b10c2a)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(229)
	super::__construct();
}
;
	return null();
}

//FFTElement_obj::~FFTElement_obj() { }

Dynamic FFTElement_obj::__CreateEmpty() { return  new FFTElement_obj; }
hx::ObjectPtr< FFTElement_obj > FFTElement_obj::__new()
{  hx::ObjectPtr< FFTElement_obj > result = new FFTElement_obj();
	result->__construct();
	return result;}

Dynamic FFTElement_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FFTElement_obj > result = new FFTElement_obj();
	result->__construct();
	return result;}


FFTElement_obj::FFTElement_obj()
{
}

void FFTElement_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FFTElement);
	HX_MARK_MEMBER_NAME(next,"next");
	HX_MARK_END_CLASS();
}

void FFTElement_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(next,"next");
}

Dynamic FFTElement_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { return next; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FFTElement_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"next") ) { next=inValue.Cast< ::FFTElement >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FFTElement_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("next"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::FFTElement*/ ,(int)offsetof(FFTElement_obj,next),HX_CSTRING("next")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("next"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FFTElement_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FFTElement_obj::__mClass,"__mClass");
};

#endif

Class FFTElement_obj::__mClass;

void FFTElement_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("FFTElement"), hx::TCanCast< FFTElement_obj> ,sStaticFields,sMemberFields,
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

void FFTElement_obj::__boot()
{
}

