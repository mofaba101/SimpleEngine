workspace "SimpleEngine"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SimpleEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "SimpleEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "SimpleEngine/vendor/ImGui"
IncludeDir["glm"] = "SimpleEngine/vendor/glm"

include "SimpleEngine/vendor/GLFW"
include "SimpleEngine/vendor/Glad"
include "SimpleEngine/vendor/ImGui"

project "SimpleEngine"
    location "SimpleEngine"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sepch.h"
    pchsource "SimpleEngine/src/sepch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm**.hpp",
        "%{prj.name}/vendor/glm/glm**.inl"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib",
        "dwmapi.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"
        
        buildoptions { "/utf-8" }  -- Enables UTF-8 code page in MSVC compiler

        defines
        {
            "SE_PLATFORM_WINDOWS",
            "SE_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "UNICODE",
            "_UNICODE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }

    filter "configurations:Debug"
        defines { "SE_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "SE_RELEASE" }
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines { "SE_DIST" }
        runtime "Release"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    staticruntime "off"
    
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    
    includedirs
    {
        "SimpleEngine/src/",
        "SimpleEngine/vendor/spdlog/include",
        "%{IncludeDir.glm}"
    }

    links
    {
        "SimpleEngine"
    }
    
    filter "system:windows"
        cppdialect "C++17"
        systemversion "latest"

        buildoptions { "/utf-8" }  -- Enables UTF-8 code page in MSVC compiler
    
        defines
        {
            "SE_PLATFORM_WINDOWS",
            "UNICODE",
            "_UNICODE"
        }
    
    filter "configurations:Debug"
        defines { "SE_DEBUG" }
        runtime "Debug"
        symbols "On"
    
    filter "configurations:Release"
        defines { "SE_RELEASE" }
        runtime "Release"
        optimize "On"
    
    filter "configurations:Dist"
        defines { "SE_DIST" }
        runtime "Release"
        optimize "On"