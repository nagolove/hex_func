workspace "love"
    architecture "x64"
    configurations {
        "Debug",
        "Release"
    }

project "loader"
    kind "ConsoleApp" language "C++"
    
    defines {
        --"LOVE_ENABLE_LUA53=0"
    }
    targetdir "."
    includedirs {
    }
    links {
        "stdc++",
    }
    libdirs {
    }
    files {
        "*.cpp",
    }
