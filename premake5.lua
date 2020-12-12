workspace "Physics-Project"
location ""
configurations {"Debug", "Release"}
platforms {"x64"}
filter {"platforms:x64"}
system "Windows"
architecture "x64"
filter {}

project "Physics-Project"
kind "WindowedApp"
language "C++"
location ""
targetname("Physics-Project")
targetdir "Bin/%{cfg.buildcfg}"
objdir "Obj/%{cfg.buildcfg}"
debugdir "Bin/%{cfg.buildcfg}"
systemversion "10.0"
flags {"MultiProcessorCompile", "NoMinimalRebuild", "NoBufferSecurityCheck"}
warnings "Extra"
includedirs {"Include"}
links {
    "dxgi", "d3d11", "d3dcompiler", "d2d1", "dwrite", "dxguid",
    "winmm", "Xinput9_1_0"
}
libdirs {"Lib/%{cfg.buildcfg}"}
files {"**.h", "**.hpp", "**.cpp", "**.inl"}
buildoptions {"-std:c++17"}
removefiles {"**Template.cpp"}
disablewarnings {
    "4505", "4456", "4201", "4100", "4189", "4458", "4819", "4127", "4701",
    "4291", "6385"
}
defines {"_CRT_SECURE_NO_WARNINGS", "WIN32_LEAN_AND_MEAN", "PHY_WIN32", "PHY_DIRECTX11"}

filter "configurations:Debug"
defines {"DEBUG"}
symbols "On"
filter "configurations:Release"
defines {"NDEBUG"}
optimize "On"
filter {}

