project "Start"
    kind "WindowedApp"

    includedirs
    {
        "include",
    }

    files "src/**"
    links{ }

    filter "system:linux"
        defines{ "_X11" }

    filter "system:windows"
        defines { "_WINDOWS" }

    filter "system:Mac"
        defines { "_MAC" }

