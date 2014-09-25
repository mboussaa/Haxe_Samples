#ifndef INCLUDED_Functions
#define INCLUDED_Functions

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <Interface.h>
HX_DECLARE_CLASS0(Functions)
HX_DECLARE_CLASS0(Interface)


class HXCPP_CLASS_ATTRIBUTES  Functions_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Functions_obj OBJ_;
		Functions_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Functions_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Functions_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		inline operator ::Interface_obj *()
			{ return new ::Interface_delegate_< Functions_obj >(this); }
		hx::Object *__ToInterface(const hx::type_info &inType);
		::String __ToString() const { return HX_CSTRING("Functions"); }

		virtual ::String lookAndSay( ::String s);
		Dynamic lookAndSay_dyn();

		virtual bool isValidEmail( ::String email);
		Dynamic isValidEmail_dyn();

		virtual int FibIter( int limit);
		Dynamic FibIter_dyn();

		virtual Void findOpenLockers( int n);
		Dynamic findOpenLockers_dyn();

};


#endif /* INCLUDED_Functions */ 
