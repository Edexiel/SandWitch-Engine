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
        GIT_TAG v5.3.0
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 1.0.1
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME entt
        GIT_REPOSITORY https://github.com/skypjack/entt.git
        GIT_TAG v3.14.0
        GIT_SHALLOW TRUE
)

CPMAddPackage(
        NAME fastgltf
        GIT_REPOSITORY https://github.com/spnda/fastgltf.git
        GIT_TAG v0.8.0
        GIT_SHALLOW TRUE
)

#Configure
##GLAD
add_library(glad glad/include/glad/gl.h glad/src/gl.c)
target_include_directories(glad PUBLIC glad/include/)