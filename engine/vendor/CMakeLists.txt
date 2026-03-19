CPMAddPackage(
        NAME fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 11.1.4
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.2.8
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.91.9b
        GIT_SHALLOW TRUE
)


CPMAddPackage(
        NAME jsoncpp
        GIT_REPOSITORY https://github.com/jart/json.cpp.git
        GIT_TAG main
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME jolt
        GIT_REPOSITORY https://github.com/jrouwe/JoltPhysics.git
        GIT_TAG v5.5.0
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.3
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.16.0
        GIT_SHALLOW TRUE
)


CPMAddPackage(
        NAME nlohmann_json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME sol2
        GIT_REPOSITORY https://github.com/ThePhD/sol2.git
        GIT_TAG v3.3.0
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v3.1.0
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME stb
        GIT_REPOSITORY https://github.com/nothings/stb.git
        GIT_TAG master
        GIT_SHALLOW TRUE
        DOWNLOAD_ONLY TRUE
)

CPMAddPackage(
        NAME miniaudio
        GIT_REPOSITORY https://github.com/mackron/miniaudio.git
        GIT_TAG 0.11.21
        GIT_SHALLOW TRUE
        DOWNLOAD_ONLY TRUE
)

if (NOT EMSCRIPTEN)
    CPMAddPackage(
            NAME steam-audio
            GIT_REPOSITORY https://github.com/ValveSoftware/steam-audio.git
            GIT_TAG v4.6.1
            GIT_SHALLOW TRUE
            DOWNLOAD_ONLY TRUE
    )
endif ()

if (NOT EMSCRIPTEN)
    CPMAddPackage(
            NAME GameNetworkingSockets
            GIT_REPOSITORY https://github.com/ValveSoftware/GameNetworkingSockets.git
            GIT_TAG v1.4.1
            GIT_SHALLOW TRUE
    )
endif ()


CPMAddPackage(
        NAME ozz-animation
        GIT_REPOSITORY https://github.com/guillaumeblanc/ozz-animation.git
        GIT_TAG 0.15.0
        GIT_SHALLOW TRUE
)

if (NOT EMSCRIPTEN)
    CPMAddPackage(
            NAME tracy
            GIT_REPOSITORY https://github.com/wolfpld/tracy.git
            GIT_TAG v0.11.1
            GIT_SHALLOW TRUE
    )
endif ()




CPMAddPackage(
        NAME xxhash
        GIT_REPOSITORY https://github.com/Cyan4973/xxHash.git
        GIT_TAG v0.8.2
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME implot
        GIT_REPOSITORY https://github.com/epezent/implot.git
        GIT_TAG v0.16
        GIT_SHALLOW TRUE
)


CPMAddPackage(
        NAME zstd
        GIT_REPOSITORY https://github.com/facebook/zstd.git
        GIT_TAG v1.5.6
        GIT_SHALLOW TRUE
        SOURCE_SUBDIR build/cmake
)


CPMAddPackage(
        NAME taskflow
        GIT_REPOSITORY https://github.com/taskflow/taskflow.git
        GIT_TAG v3.8.0
        GIT_SHALLOW TRUE
)

if (NOT EMSCRIPTEN)
    CPMAddPackage(
            NAME cpptrace
            GIT_REPOSITORY https://github.com/jeremy-rifkin/cpptrace.git
            GIT_TAG v0.7.5
            GIT_SHALLOW TRUE
    )
endif ()

CPMAddPackage(
        NAME magic_enum
        GIT_REPOSITORY https://github.com/Neargye/magic_enum.git
        GIT_TAG v0.9.7
        GIT_SHALLOW TRUE
)

#Configure
##GLAD (not needed on Emscripten — WebGL is accessed via Emscripten's built-in GL bindings)
if (NOT EMSCRIPTEN)
    add_library(glad glad/include/glad/gl.h glad/src/gl.c)
    target_include_directories(glad PUBLIC glad/include/)
endif ()