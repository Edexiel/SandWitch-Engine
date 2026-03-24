cmake_minimum_required(VERSION 4.0)
project(SandWitchEngine VERSION 0.1 LANGUAGES CXX C)

# Default to Release if no build type specified
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS ">>> Defaulting to Release build")
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS Debug Release RelWithDebInfo MinSizeRel)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CheckIPOSupported)
check_ipo_supported(RESULT LTO_SUPPORTED OUTPUT _ipo_output)
if(LTO_SUPPORTED)
    message(STATUS ">>> LTO supported — enabled for Release targets")
else()
    message(STATUS ">>> LTO not supported: ${_ipo_output}")
endif()

# add dependencies
include(cmake/CPM.cmake)

if(LINUX)
    message(STATUS ">>> Linux ${CMAKE_SYSTEM}")
    add_compile_definitions(LINUX)
elseif(WIN32)
    message(STATUS ">>> Windows ${CMAKE_SYSTEM}")
    add_compile_definitions(WIN32_SANDWITCH)
else()
    message(FATAL_ERROR ">>> Unsupported platform ${CMAKE_SYSTEM}")
endif()

add_subdirectory(engine)
add_subdirectory(editor)
add_subdirectory(game)