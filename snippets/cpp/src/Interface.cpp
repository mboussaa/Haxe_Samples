#include <hxcpp.h>

#ifndef INCLUDED_Interface
#include <Interface.h>
#endif

HX_DEFINE_DYNAMIC_FUNC1(Interface_obj,lookAndSay,return )

HX_DEFINE_DYNAMIC_FUNC1(Interface_obj,isValidEmail,return )

HX_DEFINE_DYNAMIC_FUNC1(Interface_obj,FibIter,return )

HX_DEFINE_DYNAMIC_FUNC1(Interface_obj,findOpenLockers,)


static ::String sMemberFields[] = {
	HX_CSTRING("lookAndSay"),
	HX_CSTRING("isValidEmail"),
	HX_CSTRING("FibIter"),
	HX_CSTRING("findOpenLockers"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Interface_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Interface_obj::__mClass,"__mClass");
};

#endif

Class Interface_obj::__mClass;

void Interface_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Interface"), hx::TCanCast< Interface_obj> ,0,sMemberFields,
	0, 0,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , 0
#endif
);
}

void Interface_obj::__boot()
{
}

