#pragma once

#include "Aalforreca/core/exit_codes.h"

#include "yaml-cpp/yaml.h"

namespace Aalforreca
{
    class YamlConfigImpl
    {
    public:
        YamlConfigImpl();
        ~YamlConfigImpl();

        ExitCode saveSettings(const std::string& file);
        ExitCode loadSettings(const std::string& file);

        template<typename ValueType>
        ValueType get(const std::string& name, ValueType defaultValue)
        {
            if (!_root[name])
                _root[name] = defaultValue;

            return _root[name].as<ValueType>(defaultValue);
        }

        template<typename ValueType>
        void set(const std::string& name, ValueType value)
        {
            _root[name] = value;
        }

    private:
        YAML::Node _root;
    };
}
