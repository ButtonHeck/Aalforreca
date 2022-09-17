#pragma once

#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/singleton.h"
#include "Aalforreca/core/config.h"

namespace Aalforreca
{
    class ConfigManager : public Singleton<ConfigManager>
    {
    public:
        ConfigManager();
        ~ConfigManager();

        ExitCode initialize(const char* programName);

        Shared<Config> rootConfig() const;

    private:
        ExitCode saveSettings();
        ExitCode loadSettings();

    private:
        std::string _configPath;
        Shared<Config> _rootConfig;
    };
}
