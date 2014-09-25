#include <hxcpp.h>

#include <haxe/io/Eof.h>
#include <haxe/Log.h>
#include <Sys.h>
#include <Std.h>
#include <Main.h>
#include <Functions.h>
#include <Interface.h>
#include <EReg.h>
#include <cpp/Lib.h>

void __files__boot();

void __boot_all()
{
__files__boot();
hx::RegisterResources( hx::GetResources() );
::haxe::io::Eof_obj::__register();
::haxe::Log_obj::__register();
::Sys_obj::__register();
::Std_obj::__register();
::Main_obj::__register();
::Functions_obj::__register();
::Interface_obj::__register();
::EReg_obj::__register();
::cpp::Lib_obj::__register();
::cpp::Lib_obj::__boot();
::EReg_obj::__boot();
::haxe::Log_obj::__boot();
::Interface_obj::__boot();
::Functions_obj::__boot();
::Main_obj::__boot();
::Std_obj::__boot();
::Sys_obj::__boot();
::haxe::io::Eof_obj::__boot();
}

