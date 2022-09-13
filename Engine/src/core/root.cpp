#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/root.h"
#include "Aalforreca/core/log.h"
#include "Aalforreca/core/window_manager.h"

namespace Aalforreca
{
    Root::Root()
        : _windowManager(createUnique<WindowManager>())
    {
    }

    Root::~Root()
    {
        ALRC_CORE_INFO("Root shutdown...");
    }

    ExitCode Root::initializeRoot()
    {
        Log::initialize();
        ALRC_CORE_INFO("Root inititialize...");

        auto exitCode = _windowManager->initialize();

        return exitCode;
    }
}
