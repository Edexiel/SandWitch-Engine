cmake_minimum_required(VERSION 4.0)
project(SandwitchEngine)

# Find all code files
file(GLOB_RECURSE SANDWITCH_ENGINE_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE SANDWITCH_ENGINE_SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SANDWITCH_ENGINE_SOURCES} ${SANDWITCH_ENGINE_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Warnings — errors only in Debug to avoid CI noise from third-party headers in Release
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
        $<$<CONFIG:Debug>:/WX>
    )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra -Wpedantic
        $<$<CONFIG:Debug>:-Werror>
        $<$<CONFIG:Release>:-O3>
    )
endif()

if(SW_LTO_SUPPORTED)
    set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} PRIVATE enTT glm::glm SDL3 fmt jsoncpp imgui jolt glm glad)