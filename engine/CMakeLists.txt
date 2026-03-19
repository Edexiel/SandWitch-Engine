cmake_minimum_required(VERSION 3.31.6)
project(SandwitchEngine)

set(CMAKE_CXX_STANDARD 17)

# Find all code files
file(GLOB_RECURSE SANDWITCH_ENGINE_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE SANDWITCH_ENGINE_SOURCES "src/*.cpp")


add_library(${PROJECT_NAME} STATIC ${SANDWITCH_ENGINE_SOURCES} ${SANDWITCH_ENGINE_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

# Set Warning level 4 and warnings as errors flags
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(vendor)

if (EMSCRIPTEN)
    target_link_libraries(${PROJECT_NAME} PRIVATE enTT glm::glm SDL3 fmt jsoncpp imgui jolt glm)
else ()
    target_link_libraries(${PROJECT_NAME} PRIVATE enTT glm::glm SDL3 fmt jsoncpp imgui jolt glm glad)
endif ()



