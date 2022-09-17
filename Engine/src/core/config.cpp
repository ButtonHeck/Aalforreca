#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/config.h"
#include "Aalforreca/core/yaml_config_impl.h"

namespace Aalforreca
{
    Config::Config()
        : _impl(createUnique<YamlConfigImpl>())
    {
    }

    Config::~Config()
    {
    }

    ExitCode Config::saveSettings(const std::string& file)
    {
        return _impl->saveSettings(file);
    }

    ExitCode Config::loadSettings(const std::string& file)
    {
        return _impl->loadSettings(file);
    }

    bool Config::getBool(const std::string& name, bool defaultValue) const
    {
        return _impl->get<bool>(name, defaultValue);
    }

    void Config::setBool(const std::string& name, bool value)
    {
        _impl->set<bool>(name, value);
    }

    int Config::getInt(const std::string& name, int defaultValue) const
    {
        return _impl->get<int>(name, defaultValue);
    }

    void Config::setInt(const std::string& name, int value)
    {
        _impl->set<int>(name, value);
    }

    float Config::getFloat(const std::string& name, float defaultValue) const
    {
        return _impl->get<float>(name, defaultValue);
    }

    void Config::setFloat(const std::string& name, float value)
    {
        _impl->set<float>(name, value);
    }

    std::string Config::getString(const std::string& name, const std::string& defaultValue) const
    {
        return _impl->get<std::string>(name, defaultValue);
    }

    void Config::setString(const std::string& name, const std::string& value)
    {
        _impl->set<std::string>(name, value);
    }
}
