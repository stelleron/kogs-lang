--premake5.lua
workspace "kogs-lang"
    architecture "x64"
    configurations {"Debug", "Release"}

project "kogs"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"

    targetdir "bin/"
    objdir "bin/obj/kogs"

    includedirs {"src/headers/"}
    files {"src/**.cpp"}

    filter "configurations:Debug"
        defines { "NDEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "DEBUG" }
        optimize "On"

project "kogs-cli"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir "bin/"
    objdir "bin/obj/kogs-cli"

    includedirs {"src/headers/"}
    files {"cli/**.cpp"}    
    libdirs {"bin/"}
    links {"kogs"}

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "DEBUG" }
        optimize "On"    
