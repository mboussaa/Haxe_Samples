#ifndef INCLUDED_FFTTimingTest
#define INCLUDED_FFTTimingTest

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(FFTTimingTest)


class HXCPP_CLASS_ATTRIBUTES  FFTTimingTest_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FFTTimingTest_obj OBJ_;
		FFTTimingTest_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=false)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< FFTTimingTest_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~FFTTimingTest_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		::String __ToString() const { return HX_CSTRING("FFTTimingTest"); }

		virtual int getTimer( );
		Dynamic getTimer_dyn();

		virtual Void checkIfHaxeTranslationIsCorrect( );
		Dynamic checkIfHaxeTranslationIsCorrect_dyn();

		virtual bool almostEqual( Float a,Float b);
		Dynamic almostEqual_dyn();

		virtual Void initTest( );
		Dynamic initTest_dyn();

		virtual Void print( ::String s);
		Dynamic print_dyn();

		static int LOG_N;
		static int N;
		static int NUM_LOOPS;
		static Void main( );
		static Dynamic main_dyn();

		static Float PRECISION;
};


#endif /* INCLUDED_FFTTimingTest */ 
