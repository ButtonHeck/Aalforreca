#pragma once

#include "Aalforreca/core/exit_codes.h"

#include "yaml-cpp/yaml.h"
#include <stack>

namespace Aalforreca
{
    class YamlConfigImpl
    {
    public:
        YamlConfigImpl();
        ~YamlConfigImpl();

        ExitCode saveSettings(const std::string& file);
        ExitCode loadSettings(const std::string& file);

        void beginGroup(const std::string& name);
        void endGroup();

        template<typename ValueType>
        ValueType get(const std::string& name, ValueType defaultValue)
        {
            auto currentNode = _groups.top();
            if (!currentNode[name])
                currentNode[name] = defaultValue;

            return currentNode[name].as<ValueType>(defaultValue);
        }

        template<typename ValueType>
        void set(const std::string& name, ValueType value)
        {
            auto currentNode = _groups.top();
            currentNode[name] = value;
        }

    private:
        YAML::Node _root;
        std::stack<YAML::Node> _groups;
    };
}
