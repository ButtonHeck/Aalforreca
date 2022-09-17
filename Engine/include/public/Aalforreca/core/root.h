#pragma once

#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/pointers.h"

namespace Aalforreca
{
    class WindowManager;
    class ConfigManager;

    class Root
    {
    protected:
        Root();
        ~Root();

    protected:
        Unique<ConfigManager> _configManager;
        Unique<WindowManager> _windowManager;
    };
}
