#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/yaml_config_impl.h"
#include "Aalforreca/core/log.h"

namespace Aalforreca
{
    YamlConfigImpl::YamlConfigImpl()
        : _root(YAML::Node(YAML::NodeType::Sequence))
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
            ALRC_CORE_ERROR("Failed to load settings from \"{}\", message: {}, loading defaults...", file, exception.what());
            return SuccessExitCode; //todo: change code
        }

        return SuccessExitCode;
    }

    void YamlConfigImpl::beginGroup(const std::string& name)
    {
        YAML::Node groupNode;
        _groups.push(groupNode);
        _root[name] = _groups.top();
    }

    void YamlConfigImpl::endGroup()
    {
        const auto node = _groups.top();
        _groups.pop();
    }
}
