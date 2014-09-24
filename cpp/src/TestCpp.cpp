#include <hxcpp.h>

#ifndef INCLUDED_TestCpp
#include <TestCpp.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void TestCpp_obj::__construct()
{
	return null();
}

//TestCpp_obj::~TestCpp_obj() { }

Dynamic TestCpp_obj::__CreateEmpty() { return  new TestCpp_obj; }
hx::ObjectPtr< TestCpp_obj > TestCpp_obj::__new()
{  hx::ObjectPtr< TestCpp_obj > result = new TestCpp_obj();
	result->__construct();
	return result;}

Dynamic TestCpp_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestCpp_obj > result = new TestCpp_obj();
	result->__construct();
	return result;}

Void TestCpp_obj::main( ){
{
		HX_STACK_FRAME("TestCpp","main",0x17bcd9f6,"TestCpp.main","TestCpp.hx",5,0x6c06238d)
		HX_STACK_LINE(5)
		::haxe::Log_obj::trace(HX_CSTRING("Hello TestCpp"),hx::SourceInfo(HX_CSTRING("TestCpp.hx"),5,HX_CSTRING("TestCpp"),HX_CSTRING("main")));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(TestCpp_obj,main,(void))


TestCpp_obj::TestCpp_obj()
{
}

Dynamic TestCpp_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TestCpp_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void TestCpp_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TestCpp_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TestCpp_obj::__mClass,"__mClass");
};

#endif

Class TestCpp_obj::__mClass;

void TestCpp_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("TestCpp"), hx::TCanCast< TestCpp_obj> ,sStaticFields,sMemberFields,
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

void TestCpp_obj::__boot()
{
}

