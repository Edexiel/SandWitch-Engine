cmake_minimum_required(VERSION 3.31.6)
project(SandwitchGame VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SANDWITCH_GAME_HEADERS "src/*.hpp" "src/*.h")
file(GLOB_RECURSE SANDWITCH_GAME_SOURCES "src/*.cpp")

add_executable(${PROJECT_NAME} ${SANDWITCH_GAME_SOURCES} ${SANDWITCH_GAME_HEADERS})
target_include_directories(${PROJECT_NAME} PRIVATE src)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE SandwitchEngine)

if (EMSCRIPTEN)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
    target_link_options(${PROJECT_NAME} PRIVATE
            -sWASM=1
            -sUSE_WEBGL2=1
            -sFULL_ES3=1
            -sALLOW_MEMORY_GROWTH=1
            -sASYNCIFY=1
    )
endif ()