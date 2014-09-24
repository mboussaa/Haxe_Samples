#ifndef INCLUDED_FFTElementEssentials
#define INCLUDED_FFTElementEssentials

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(FFTElementEssentials)


class HXCPP_CLASS_ATTRIBUTES  FFTElementEssentials_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FFTElementEssentials_obj OBJ_;
		FFTElementEssentials_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FFTElementEssentials_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FFTElementEssentials_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FFTElementEssentials"); }

		Float re;
		Float im;
		int revTgt;
};


#endif /* INCLUDED_FFTElementEssentials */ 
