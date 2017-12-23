#include <PluginSystem/Plugin.h>
#include <dlfcn.h>
#include <iostream>

namespace PluginSystem
{
    bool PluginManager::LoadPlugin(std::string pluginName)
    {
        pluginName.insert(0, "lib");
        pluginName += ".so";

        auto pluginToLoad = dlopen(pluginName.c_str(), RTLD_NOW);
        if(pluginToLoad == nullptr) return false;
        auto plugin = Plugin{pluginToLoad};
        if(!plugin.InitPlugin())
        {
            return false;
        }
        m_loadedPlugins.emplace_back(plugin);
        return true;
    }

    bool Plugin::InitPlugin()
    {
        m_pluginDetailsEntry = reinterpret_cast<PluginDetails>(dlsym(m_plugin, "PluginInit"));
        if(!m_pluginDetailsEntry)
        {
            return false;
        }
        auto pluginDetails = m_pluginDetailsEntry();
        m_pluginName = pluginDetails.pluginName;
        m_pluginVersion = pluginDetails.pluginVersion;
        m_entryFunction = reinterpret_cast<PluginEntry>(dlsym(m_plugin, pluginDetails.pluginEntryName));
        if(!m_entryFunction)
        {
            return false;
        }
        // Load the plugin :D
        m_entryFunction();
        return true;
    }

    Plugin::~Plugin()
    {
        dlclose(m_plugin);
    }
}

