CPMAddPackage(
        NAME fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 12.1.0
)

CPMAddPackage(
        NAME SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.4.2
)

CPMAddPackage(
        NAME imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.92.6
        DOWNLOAD_ONLY TRUE
)
set(IMGUI_EXAMPLES FALSE)
set(IMGUI_DEMO FALSE)
set(IMGUI_ENABLE_STDLIB_SUPPORT TRUE)

CPMAddPackage(
        NAME jsoncpp
        GIT_REPOSITORY https://github.com/jart/json.cpp.git
        GIT_TAG main
        DOWNLOAD_ONLY TRUE
)

CPMAddPackage(
        NAME jolt
        GIT_REPOSITORY https://github.com/jrouwe/JoltPhysics.git
        GIT_TAG v5.5.0
)

CPMAddPackage(
        NAME glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.3
)

CPMAddPackage(
        NAME entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.16.0
        DOWNLOAD_ONLY True
)

CPMAddPackage(
        NAME sol2
        GIT_REPOSITORY https://github.com/ThePhD/sol2.git
        GIT_TAG v3.3.0
)

CPMAddPackage(
        NAME box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v3.1.0
)

CPMAddPackage(
        NAME stb
        GIT_REPOSITORY https://github.com/nothings/stb.git
        GIT_TAG master
        DOWNLOAD_ONLY TRUE
)

CPMAddPackage(
        NAME miniaudio
        GIT_REPOSITORY https://github.com/mackron/miniaudio.git
        GIT_TAG 0.11.21
        DOWNLOAD_ONLY TRUE
)

CPMAddPackage(
        NAME steam-audio
        GIT_REPOSITORY https://github.com/ValveSoftware/steam-audio.git
        GIT_TAG v4.6.1
        DOWNLOAD_ONLY TRUE
)

CPMAddPackage(
        NAME GameNetworkingSockets
        GIT_REPOSITORY https://github.com/ValveSoftware/GameNetworkingSockets.git
        GIT_TAG v1.4.1
)

CPMAddPackage(
        NAME ozz-animation
        GIT_REPOSITORY https://github.com/guillaumeblanc/ozz-animation.git
        GIT_TAG 0.15.0
        OPTIONS
            "ozz_build_samples OFF"
            "ozz_build_tools OFF"
            "ozz_build_fbx OFF"
            "ozz_build_tests OFF"
)

CPMAddPackage(
        NAME tracy
        GIT_REPOSITORY https://github.com/wolfpld/tracy.git
        GIT_TAG v0.11.1
)

CPMAddPackage(
        NAME xxhash
        GIT_REPOSITORY https://github.com/Cyan4973/xxHash.git
        GIT_TAG v0.8.2
)

CPMAddPackage(
        NAME implot
        GIT_REPOSITORY https://github.com/epezent/implot.git
        GIT_TAG v0.16
        DOWNLOAD_ONLY TRUE
)

CPMAddPackage(
        NAME zstd
        GIT_REPOSITORY https://github.com/facebook/zstd.git
        GIT_TAG v1.5.6
        SOURCE_SUBDIR build/cmake
)

CPMAddPackage(
        NAME taskflow
        GIT_REPOSITORY https://github.com/taskflow/taskflow.git
        GIT_TAG v3.8.0
)

CPMAddPackage(
        NAME cpptrace
        GIT_REPOSITORY https://github.com/jeremy-rifkin/cpptrace.git
        GIT_TAG v0.7.5
)

CPMAddPackage(
        NAME magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG v0.9.7
)

add_library(glad glad/include/glad/gl.h glad/src/gl.c)
target_include_directories(glad PUBLIC glad/include/)