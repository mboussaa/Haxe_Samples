#include <hxcpp.h>

#include <haxe/Timer.h>
#include <haxe/Log.h>
#include <Std.h>
#include <FFTTimingTest.h>
#include <FFTElement.h>
#include <FFTElementEssentials.h>
#include <FFT.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::haxe::Timer_obj::__register();
::haxe::Log_obj::__register();
::Std_obj::__register();
::FFTTimingTest_obj::__register();
::FFTElement_obj::__register();
::FFTElementEssentials_obj::__register();
::FFT_obj::__register();
::haxe::Log_obj::__boot();
::FFT_obj::__boot();
::FFTElementEssentials_obj::__boot();
::FFTElement_obj::__boot();
::FFTTimingTest_obj::__boot();
::Std_obj::__boot();
::haxe::Timer_obj::__boot();
}

