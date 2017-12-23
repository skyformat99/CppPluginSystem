#include <PluginSystem/Plugin.h>

namespace PluginSystem
{
    const std::string& Plugin::GetPluginName() const
    {
        return m_pluginName;
    }

    const std::string& Plugin::GetPluginVersion() const
    {
        return m_pluginVersion;
    }


    Plugin::Plugin(void *plugin)  : m_plugin{plugin}
    {
    }
}

