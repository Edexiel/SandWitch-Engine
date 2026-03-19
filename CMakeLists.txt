cmake_minimum_required(VERSION 3.31.6)
project(SandWitchEngine VERSION 0.1 LANGUAGES CXX C)

# add dependencies
include(cmake/CPM.cmake)

if (EMSCRIPTEN)
    message(STATUS ">>> Web/Emscripten ${CMAKE_SYSTEM}")
    add_definitions(-DWEB)
elseif (LINUX)
    message(STATUS ">>> Linux ${CMAKE_SYSTEM}")
    add_definitions(-DLINUX)
elseif (WIN32)
    add_definitions(-DWIN32)
    message(STATUS ">>> Windows ${CMAKE_SYSTEM}")
else ()
    message(FATAL_ERROR ">>> Not supported platform ${CMAKE_SYSTEM}")
endif ()

add_subdirectory(engine)
if (NOT EMSCRIPTEN)
    add_subdirectory(editor)
endif ()
add_subdirectory(game)

