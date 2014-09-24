#ifndef INCLUDED_FFTElement
#define INCLUDED_FFTElement

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <FFTElementEssentials.h>
HX_DECLARE_CLASS0(FFTElement)
HX_DECLARE_CLASS0(FFTElementEssentials)


class HXCPP_CLASS_ATTRIBUTES  FFTElement_obj : public ::FFTElementEssentials_obj{
	public:
		typedef ::FFTElementEssentials_obj super;
		typedef FFTElement_obj OBJ_;
		FFTElement_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FFTElement_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FFTElement_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FFTElement"); }

		::FFTElement next;
};


#endif /* INCLUDED_FFTElement */ 
