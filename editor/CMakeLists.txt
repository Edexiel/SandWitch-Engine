cmake_minimum_required(VERSION 3.31.6)
project(SandwitchEditor VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SANDWITCH_EDITOR_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE SANDWITCH_EDITOR_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SANDWITCH_EDITOR_SOURCES} ${SANDWITCH_EDITOR_HEADERS} )
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Set Warning level 4 and warnings as errors flags
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} PRIVATE SandwitchEngine)
