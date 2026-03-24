cmake_minimum_required(VERSION 3.31.6)
project(SandwitchGame VERSION 0.1 LANGUAGES CXX C)

file(GLOB_RECURSE SANDWITCH_GAME_HEADERS "src/*.hpp" "src/*.h")
file(GLOB_RECURSE SANDWITCH_GAME_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SANDWITCH_GAME_SOURCES} ${SANDWITCH_GAME_HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE src)

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

# LTO in Release
if(SW_LTO_SUPPORTED)
    set_property(TARGET ${PROJECT_NAME} PROPERTY INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SandwitchEngine)