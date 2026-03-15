cmake_minimum_required(VERSION 3.31.6)
project(SandWitchEngine VERSION 0.1 LANGUAGES CXX C)

# add dependencies
include(cmake/CPM.cmake)

if (LINUX)
    message(STATUS ">>> Linux ${CMAKE_SYSTEM}")
    # linux stuff here
    add_definitions(-DLINUX)
elseif (WIN32)
    add_definitions(-DWIN32)
    message(STATUS ">>> Not Linux ${CMAKE_SYSTEM}")
    # stuff that should happen on Win32
else ()
    message(FATAL_ERROR ">>> Not supported platform ${CMAKE_SYSTEM}")
endif ()

add_subdirectory(engine)
add_subdirectory(editor)
add_subdirectory(game)

