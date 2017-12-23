project(PluginLibrary)

set(PLUGIN_HEADERS include/PluginSystem/Plugin.h)


if (UNIX)
    set(PLUGIN_SOURCES_SPEC
            source/PluginLinux.cpp)
endif (UNIX)


set(PLUGIN_SOURCES
        ${PLUGIN_SOURCES_SPEC}
        source/PluginShared.cpp)


include_directories(include)

add_library(PluginLibrary STATIC ${PLUGIN_HEADERS} ${PLUGIN_SOURCES})
target_include_directories(PluginLibrary PUBLIC include)

if(UNIX)
    target_link_libraries(PluginLibrary dl)
endif(UNIX)
