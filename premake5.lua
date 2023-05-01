-- The name of your workspace will be used, for example, to name the Visual Studio .sln file generated by Premake.
workspace "Accelerated"
    -- We set the location of the files Premake will generate
    location "generated"

    -- We indicate that all the projects are C++ only
    language "C++"

    -- We will compile for x86_64. You can change this to x86 for 32 bit builds.
    architecture "x86_64"

    -- Configurations are often used to store some compiler / linker settings together.
    -- The Debug configuration will be used by us while debugging.
    -- The optimized Release configuration will be used when shipping the app.
    configurations { "Debug", "Release" }

    -- We use filters to set options, a new feature of Premake5.
    -- We now only set settings for the Debug configuration
    filter { "configurations:Debug" }
        -- We want debug symbols in our debug config
        symbols "On"

    -- We now only set settings for Release
    filter { "configurations:Release" }
        -- Release should be optimized
        optimize "On"

    filter "system:linux"
        defines{ "_X11" }

    filter "system:windows"
        defines { "_WINDOWS" }

    filter "system:Mac"
        defines { "_MAC" }

    -- Reset the filter for other settings
    filter { }

    -- Here we use some "tokens" (the things between %{ ... }). They will be replaced by Premake
    -- automatically when configuring the projects.
    -- * %{prj.name} will be replaced by "ExampleLib" / "App" / "UnitTests"
    --  * %{cfg.longname} will be replaced by "Debug" or "Release" depending on the configuration
    -- The path is relative to *this* folder
    targetdir ("build/bin/%{prj.name}/%{cfg.longname}")
    objdir ("build/obj/%{prj.name}/%{cfg.longname}")

include "projects/0-Getting-Started"
include "projects/1-Strings"
include "projects/2-Loops"
include "projects/3-Data-batches"
include "projects/4-Organising-programs"
include "projects/4.2-Organising-programs-several-students"
include "projects/5-Sequential_containers"
include "projects/6-Library-Algo"
include "projects/7-Using-associative-containers"
include "projects/8-Writing-generic-functions"
