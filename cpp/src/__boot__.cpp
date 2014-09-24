#include <hxcpp.h>

#include <haxe/Log.h>
#include <TestCpp.h>
#include <Std.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::haxe::Log_obj::__register();
::TestCpp_obj::__register();
::Std_obj::__register();
::haxe::Log_obj::__boot();
::Std_obj::__boot();
::TestCpp_obj::__boot();
}

