#include <iostream>
#include <PluginSystem/Plugin.h>

int main()
{
    PluginSystem::PluginManager pluginManager;
    pluginManager.LoadPlugin("PluginTestLibrary");
    return 0;
}