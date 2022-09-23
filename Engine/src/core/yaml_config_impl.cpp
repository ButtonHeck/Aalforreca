#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/yaml_config_impl.h"
#include "Aalforreca/core/log.h"

namespace Aalforreca
{
    YamlConfigImpl::YamlConfigImpl()
        : _root(YAML::Node(YAML::NodeType::Sequence))
        , _currentNode(&_root)
    {
    }

    YamlConfigImpl::~YamlConfigImpl()
    {
    }

    ExitCode YamlConfigImpl::saveSettings(const std::string& file)
    {
        std::ofstream out(file);
        if (!out.is_open())
        {
            ALRC_CORE_ERROR("Error opening \"{}\"", file);
            return FileIOFailExitCode;
        }

        out << _root;
        out.close();

        if (out.bad())
        {
            ALRC_CORE_ERROR("Error saving default settings to \"{}\"", file);
            return FileIOFailExitCode;
        }

        return SuccessExitCode;
    }

    ExitCode YamlConfigImpl::loadSettings(const std::string& file)
    {
        try
        {
            _root = YAML::LoadFile(file);
        }
        catch (YAML::ParserException exception)
        {
            ALRC_CORE_ERROR("Failed to load settings from \"{}\", message: {}", file, exception.what());
            return FileIOFailExitCode;
        }

        return SuccessExitCode;
    }

    void YamlConfigImpl::beginGroup(const std::string& name)
    {
        YAML::Node groupNode = _root[name] ? _root[name] : YAML::Node(YAML::NodeType::Sequence);
        _groups.push({name, groupNode});
        _currentNode = &_groups.top().node;
    }

    void YamlConfigImpl::endGroup()
    {
        if (_groups.empty())
        {
            _currentNode = &_root;
        }
        else
        {
            const auto completedConfigNode = _groups.top();
            _root[completedConfigNode.name] = completedConfigNode.node;
            _groups.pop();
            _currentNode = &_groups.top().node;
        }
    }
}
