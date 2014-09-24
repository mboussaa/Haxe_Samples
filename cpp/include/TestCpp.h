#ifndef INCLUDED_TestCpp
#define INCLUDED_TestCpp

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(TestCpp)


class HXCPP_CLASS_ATTRIBUTES  TestCpp_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TestCpp_obj OBJ_;
		TestCpp_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< TestCpp_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~TestCpp_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("TestCpp"); }

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_TestCpp */ 
