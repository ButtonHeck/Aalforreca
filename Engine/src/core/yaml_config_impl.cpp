#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/yaml_config_impl.h"
#include "Aalforreca/core/log.h"

namespace Aalforreca
{
    YamlConfigImpl::YamlConfigImpl()
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
}
