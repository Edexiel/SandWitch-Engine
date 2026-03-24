cmake_minimum_required(VERSION 4.0)
project(SandwitchEditor VERSION 0.1 LANGUAGES CXX C)

file(GLOB_RECURSE SANDWITCH_EDITOR_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE SANDWITCH_EDITOR_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SANDWITCH_EDITOR_SOURCES} ${SANDWITCH_EDITOR_HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE include)

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

if(LTO_SUPPORTED)
    set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} PRIVATE SandwitchEngine)