#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/config_manager.h"
#include "Aalforreca/core/path_helper.h"
#include "Aalforreca/core/config.h"

#include <cstdlib>

namespace Aalforreca
{
    ALRC_SINGLETON(ConfigManager)

    ConfigManager::ConfigManager()
        : _rootConfig(createShared<Config>())
    {
    }

    ConfigManager::~ConfigManager()
    {
        saveSettings();
    }

    ExitCode ConfigManager::initialize(const char* programName)
    {
        ALRC_CORE_TRACE("Config manager initialize...");

        char* home = getenv("HOME");
        const auto programNameStripped = std::filesystem::path(programName).filename();
        if (!home)
        {
            ALRC_CORE_WARN("Environment variable \"HOME\" not found");
            _configPath = (std::filesystem::current_path() / programNameStripped).string().append(".conf");
        }
        else
            _configPath = (std::filesystem::path(home) / ".config" / programNameStripped).string().append(".conf");

        loadSettings();

        ALRC_CORE_TRACE(_configPath);

        return SuccessExitCode;
    }

    Shared<Config> ConfigManager::rootConfig() const
    {
        return _rootConfig;
    }

    ExitCode ConfigManager::saveSettings()
    {
        ALRC_CORE_TRACE("ConfigManager saving settings...");

        if (!std::filesystem::exists(_configPath))
        {
            ALRC_CORE_ERROR("\"{}\" does not exist, could not save", _configPath);
            return FileIOFailExitCode;
        }

        return _rootConfig->saveSettings(_configPath);
    }

    ExitCode ConfigManager::loadSettings()
    {
        if (!std::filesystem::exists(_configPath))
        {
            ALRC_CORE_WARN("\"{}\" does not exist, creating one...", _configPath);
            std::ofstream out(_configPath);
            out.close();
        }

        return _rootConfig->loadSettings(_configPath);
    }
}
