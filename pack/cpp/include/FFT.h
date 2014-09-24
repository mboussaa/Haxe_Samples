#ifndef INCLUDED_FFT
#define INCLUDED_FFT

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(FFT)
HX_DECLARE_CLASS0(FFTElement)
HX_DECLARE_CLASS0(FFTElementEssentials)


class HXCPP_CLASS_ATTRIBUTES  FFT_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FFT_obj OBJ_;
		FFT_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FFT_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FFT_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FFT"); }

		int m_logN;
		int m_N;
		Float m_invN;
		Array< ::Dynamic > m_X;
		virtual Void init( int logN);
		Dynamic init_dyn();

		virtual Void run( Array< Float > xRe,Array< Float > xIm,hx::Null< bool >  inverse);
		Dynamic run_dyn();

		virtual int BitReverse( int x,int numBits);
		Dynamic BitReverse_dyn();

		static bool FORWARD;
		static bool INVERSE;
		static Dynamic newArray( hx::Null< int >  len,hx::Null< bool >  fixed);
		static Dynamic newArray_dyn();

};


#endif /* INCLUDED_FFT */ 
