#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/root.h"
#include "Aalforreca/core/log.h"
#include "Aalforreca/core/window_manager.h"
#include "Aalforreca/core/config_manager.h"

namespace Aalforreca
{
    Root::Root()
        : _configManager(createUnique<ConfigManager>())
        , _windowManager(createUnique<WindowManager>())
    {
    }

    Root::~Root()
    {
        ALRC_CORE_INFO("Root shutdown...");
    }
}
