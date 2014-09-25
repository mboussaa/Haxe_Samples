#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_Functions
#include <Functions.h>
#endif
#ifndef INCLUDED_Interface
#include <Interface.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif

Void Functions_obj::__construct()
{
HX_STACK_FRAME("Functions","new",0x3f72c4ad,"Functions.new","Functions.hx",6,0x105b2f63)
HX_STACK_THIS(this)
{
}
;
	return null();
}

//Functions_obj::~Functions_obj() { }

Dynamic Functions_obj::__CreateEmpty() { return  new Functions_obj; }
hx::ObjectPtr< Functions_obj > Functions_obj::__new()
{  hx::ObjectPtr< Functions_obj > result = new Functions_obj();
	result->__construct();
	return result;}

Dynamic Functions_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Functions_obj > result = new Functions_obj();
	result->__construct();
	return result;}

hx::Object *Functions_obj::__ToInterface(const hx::type_info &inType) {
	if (inType==typeid( ::Interface_obj)) return operator ::Interface_obj *();
	return super::__ToInterface(inType);
}

::String Functions_obj::lookAndSay( ::String s){
	HX_STACK_FRAME("Functions","lookAndSay",0xa3a200a6,"Functions.lookAndSay","Functions.hx",10,0x105b2f63)
	HX_STACK_THIS(this)
	HX_STACK_ARG(s,"s")
	HX_STACK_LINE(11)
	if (((bool((s == null())) || bool((s == HX_CSTRING("")))))){
		HX_STACK_LINE(11)
		return HX_CSTRING("");
	}
	HX_STACK_LINE(13)
	::String results = HX_CSTRING("");		HX_STACK_VAR(results,"results");
	HX_STACK_LINE(14)
	::String repeat = s.charAt((int)0);		HX_STACK_VAR(repeat,"repeat");
	HX_STACK_LINE(15)
	int amount = (int)1;		HX_STACK_VAR(amount,"amount");
	HX_STACK_LINE(16)
	{
		HX_STACK_LINE(16)
		int _g1 = (int)1;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(16)
		int _g = s.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(16)
		while((true)){
			HX_STACK_LINE(16)
			if ((!(((_g1 < _g))))){
				HX_STACK_LINE(16)
				break;
			}
			HX_STACK_LINE(16)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(18)
			::String actual = s.charAt(i);		HX_STACK_VAR(actual,"actual");
			HX_STACK_LINE(19)
			if (((actual != repeat))){
				HX_STACK_LINE(21)
				hx::AddEq(results,amount);
				HX_STACK_LINE(22)
				hx::AddEq(results,repeat);
				HX_STACK_LINE(23)
				repeat = actual;
				HX_STACK_LINE(24)
				amount = (int)0;
			}
			HX_STACK_LINE(26)
			(amount)++;
		}
	}
	HX_STACK_LINE(28)
	hx::AddEq(results,amount);
	HX_STACK_LINE(29)
	hx::AddEq(results,repeat);
	HX_STACK_LINE(31)
	return results;
}


HX_DEFINE_DYNAMIC_FUNC1(Functions_obj,lookAndSay,return )

bool Functions_obj::isValidEmail( ::String email){
	HX_STACK_FRAME("Functions","isValidEmail",0x4df5fb1d,"Functions.isValidEmail","Functions.hx",35,0x105b2f63)
	HX_STACK_THIS(this)
	HX_STACK_ARG(email,"email")
	HX_STACK_LINE(36)
	::EReg emailExpression = ::EReg_obj::__new(HX_CSTRING("^[\\w-\\.]{2,}@[\xc3""\x85""\xc3""\x84""\xc3""\x96""\xc3""\xa5""\xc3""\xa4""\xc3""\xb6""\\w-\\.]{2,}\\.[a-z]{2,6}$"),HX_CSTRING("i"));		HX_STACK_VAR(emailExpression,"emailExpression");
	HX_STACK_LINE(37)
	return emailExpression->match(email);
}


HX_DEFINE_DYNAMIC_FUNC1(Functions_obj,isValidEmail,return )

int Functions_obj::FibIter( int limit){
	HX_STACK_FRAME("Functions","FibIter",0x39b8c524,"Functions.FibIter","Functions.hx",40,0x105b2f63)
	HX_STACK_THIS(this)
	HX_STACK_ARG(limit,"limit")
	HX_STACK_LINE(40)
	Array< int > limit1 = Array_obj< int >::__new().Add(limit);		HX_STACK_VAR(limit1,"limit1");
	HX_STACK_LINE(42)
	Array< int > current = Array_obj< int >::__new();		HX_STACK_VAR(current,"current");
	HX_STACK_LINE(43)
	Array< int > nextItem = Array_obj< int >::__new();		HX_STACK_VAR(nextItem,"nextItem");
	HX_STACK_LINE(44)
	int lim;		HX_STACK_VAR(lim,"lim");
	HX_STACK_LINE(46)
	current[(int)0] = (int)0;
	HX_STACK_LINE(47)
	nextItem[(int)0] = (int)1;
	HX_STACK_LINE(48)
	lim = limit1->__get((int)0);

	HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_1_1,Array< int >,limit1)
	bool run(){
		HX_STACK_FRAME("*","_Function_1_1",0x5200ed37,"*._Function_1_1","Functions.hx",51,0x105b2f63)
		{
			HX_STACK_LINE(51)
			return (limit1->__get((int)0) > (int)0);
		}
		return null();
	}
	HX_END_LOCAL_FUNC0(return)

	HX_STACK_LINE(51)
	Dynamic hasNext =  Dynamic(new _Function_1_1(limit1));		HX_STACK_VAR(hasNext,"hasNext");

	HX_BEGIN_LOCAL_FUNC_S3(hx::LocalFunc,_Function_1_2,Array< int >,nextItem,Array< int >,limit1,Array< int >,current)
	int run(){
		HX_STACK_FRAME("*","_Function_1_2",0x5200ed38,"*._Function_1_2","Functions.hx",53,0x105b2f63)
		{
			HX_STACK_LINE(54)
			(limit1[(int)0])--;
			HX_STACK_LINE(55)
			int ret = current->__get((int)0);		HX_STACK_VAR(ret,"ret");
			HX_STACK_LINE(56)
			int temp = (current->__get((int)0) + nextItem->__get((int)0));		HX_STACK_VAR(temp,"temp");
			HX_STACK_LINE(57)
			current[(int)0] = nextItem->__get((int)0);
			HX_STACK_LINE(58)
			nextItem[(int)0] = temp;
			HX_STACK_LINE(59)
			return ret;
		}
		return null();
	}
	HX_END_LOCAL_FUNC0(return)

	HX_STACK_LINE(53)
	Dynamic next =  Dynamic(new _Function_1_2(nextItem,limit1,current));		HX_STACK_VAR(next,"next");
	HX_STACK_LINE(61)
	return lim;
}


HX_DEFINE_DYNAMIC_FUNC1(Functions_obj,FibIter,return )

Void Functions_obj::findOpenLockers( int n){
{
		HX_STACK_FRAME("Functions","findOpenLockers",0x7749e5c5,"Functions.findOpenLockers","Functions.hx",65,0x105b2f63)
		HX_STACK_THIS(this)
		HX_STACK_ARG(n,"n")
		HX_STACK_LINE(66)
		int i = (int)1;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(68)
		while((true)){
			HX_STACK_LINE(68)
			if ((!((((i * i) <= n))))){
				HX_STACK_LINE(68)
				break;
			}
			HX_STACK_LINE(70)
			::Sys_obj::print(((i * i) + HX_CSTRING("\n")));
			HX_STACK_LINE(71)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Functions_obj,findOpenLockers,(void))


Functions_obj::Functions_obj()
{
}

Dynamic Functions_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"FibIter") ) { return FibIter_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lookAndSay") ) { return lookAndSay_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isValidEmail") ) { return isValidEmail_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"findOpenLockers") ) { return findOpenLockers_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Functions_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Functions_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo *sMemberStorageInfo = 0;
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("lookAndSay"),
	HX_CSTRING("isValidEmail"),
	HX_CSTRING("FibIter"),
	HX_CSTRING("findOpenLockers"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Functions_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Functions_obj::__mClass,"__mClass");
};

#endif

Class Functions_obj::__mClass;

void Functions_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Functions"), hx::TCanCast< Functions_obj> ,sStaticFields,sMemberFields,
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

void Functions_obj::__boot()
{
}

