#include <iostream>

extern "C"
{

    struct PluginCDetails
    {
        char* pluginName;
        char* pluginEntryName;
        char* pluginVersion;
    };
    PluginCDetails PluginInit()
    {
        return PluginCDetails
                {
                        const_cast<char *>("TestPlugin"),
                        const_cast<char *>("OtherFunction"),
                        const_cast<char *>("0.0.1")
                };
    }

    void OtherFunction()
    {
        std::cout << "Hello world!\n";
    }

    void EntryPlugin()
    {
        std::cout << "Esta funcion es de otra libreria y esta siendo cargada en tiempo de ejecución uwu" << '\n';
    }

}
