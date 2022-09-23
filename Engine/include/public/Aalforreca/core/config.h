#pragma once

#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/pointers.h"

namespace Aalforreca
{
    class YamlConfigImpl;

    class Config
    {
    public:
        Config();
        ~Config();

        ExitCode saveSettings(const std::string& file);
        ExitCode loadSettings(const std::string& file);

        void beginGroup(const std::string& name);
        void endGroup();

        bool getBool(const std::string& name, bool defaultValue) const;
        void setBool(const std::string& name, bool value);

        int getInt(const std::string& name, int defaultValue) const;
        void setInt(const std::string& name, int value);

        float getFloat(const std::string& name, float defaultValue) const;
        void setFloat(const std::string& name, float value);

        std::string getString(const std::string& name, const std::string& defaultValue) const;
        void setString(const std::string& name, const std::string& value);

    private:
        Unique<YamlConfigImpl> _impl;
    };
}
