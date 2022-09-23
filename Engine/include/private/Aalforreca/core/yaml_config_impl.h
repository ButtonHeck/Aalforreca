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
            if (!_currentNode)
                return defaultValue;

            if (!(*_currentNode)[name])
                (*_currentNode)[name] = defaultValue;

            return (*_currentNode)[name].as<ValueType>(defaultValue);
        }

        template<typename ValueType>
        void set(const std::string& name, ValueType value)
        {
            if (!_currentNode)
                return;

            (*_currentNode)[name] = value;
        }

    private:
        struct ConfigNode
        {
            std::string name;
            YAML::Node node;
        };

    private:
        YAML::Node _root;
        YAML::Node* _currentNode;
        std::stack<ConfigNode> _groups;
    };
}
