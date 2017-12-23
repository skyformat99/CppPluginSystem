cmake_minimum_required(VERSION 3.5)
project(PluginSystem)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(PluginSystem)

add_executable(PluginTest main.cpp)
add_library(PluginTestLibrary SHARED Plugin.cpp)
target_link_libraries(PluginTest PluginLibrary)

