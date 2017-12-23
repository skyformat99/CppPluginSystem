#pragma once

#include <string>
#include <vector>

extern "C"
{
    struct PluginCDetails
    {
        char* pluginName;
        char* pluginEntryName;
        char* pluginVersion;
    };
}

namespace PluginSystem
{

    typedef void (*PluginEntry)();
    typedef ::PluginCDetails (*PluginDetails)();

    /**
     * @brief Represent a plugin
     * Contains the info about a plugin
     */
    class Plugin
    {
        std::string m_pluginName;
        std::string m_pluginVersion;
        PluginEntry m_entryFunction;
        PluginDetails m_pluginDetailsEntry;
        void* m_plugin;
    public:
        explicit Plugin(void* plugin);
        ~Plugin();

        bool InitPlugin();

        const std::string& GetPluginName() const;

        const std::string& GetPluginVersion() const;
    };

    class PluginManager
    {
        std::vector<Plugin> m_loadedPlugins;
    public:
        bool LoadPlugin(std::string pluginName);

        bool RemovePlugin(const std::string& pluginName);
    };

}
