cmake_minimum_required(VERSION 4.0)
project(SandwitchEngine)

file(GLOB_RECURSE SANDWITCH_ENGINE_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE SANDWITCH_ENGINE_SOURCES "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SANDWITCH_ENGINE_SOURCES} ${SANDWITCH_ENGINE_HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)

if(LTO_SUPPORTED)
    set_target_properties(${PROJECT_NAME} PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
endif()

add_subdirectory(vendor)

target_link_libraries(${PROJECT_NAME} PRIVATE SandwitchOptions enTT glm::glm SDL3 fmt jsoncpp imgui jolt glm glad)