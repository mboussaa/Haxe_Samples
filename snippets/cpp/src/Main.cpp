#include <hxcpp.h>

#ifndef INCLUDED_Functions
#include <Functions.h>
#endif
#ifndef INCLUDED_Interface
#include <Interface.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif

Void Main_obj::__construct()
{
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",6,0x087e5c05)
		HX_STACK_LINE(9)
		::Functions fun = ::Functions_obj::__new();		HX_STACK_VAR(fun,"fun");
		HX_STACK_LINE(12)
		::String test = HX_CSTRING("1");		HX_STACK_VAR(test,"test");
		HX_STACK_LINE(13)
		{
			HX_STACK_LINE(13)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(13)
			while((true)){
				HX_STACK_LINE(13)
				if ((!(((_g < (int)11))))){
					HX_STACK_LINE(13)
					break;
				}
				HX_STACK_LINE(13)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(14)
				::Sys_obj::println(test);
				HX_STACK_LINE(15)
				::String _g1 = fun->lookAndSay(test);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(15)
				test = _g1;
			}
		}
		HX_STACK_LINE(19)
		bool resp = fun->isValidEmail(HX_CSTRING("medmed@med.com"));		HX_STACK_VAR(resp,"resp");
		HX_STACK_LINE(20)
		::haxe::Log_obj::trace(resp,hx::SourceInfo(HX_CSTRING("Main.hx"),20,HX_CSTRING("Main"),HX_CSTRING("main")));
		HX_STACK_LINE(23)
		int x = fun->FibIter((int)10);		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(24)
		::Sys_obj::println(x);
		HX_STACK_LINE(27)
		fun->findOpenLockers((int)100);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
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
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
}

