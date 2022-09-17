#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/application.h"
#include "Aalforreca/core/window_manager.h"
#include "Aalforreca/core/config_manager.h"
#include "Aalforreca/core/window.h"
#include "Aalforreca/core/log.h"
#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/helper_macros.h"
#include "Aalforreca/events/event.h"
#include "Aalforreca/events/window_event.h"
#include <AalforrecaEngineConfig.h>

namespace Aalforreca
{
    ALRC_SINGLETON(Application)

    int Application::versionMajor()
    {
        return AALFORRECA_ENGINE_VERSION_MAJOR;
    }

    int Application::versionMinor()
    {
        return AALFORRECA_ENGINE_VERSION_MINOR;
    }


    Application::~Application()
    {
        ALRC_CORE_INFO("Core shutdown...");
    }

    ExitCode Application::initialize(int argc, char** argv)
    {
        if (_coreInitialized)
        {
            ALRC_CORE_WARN("Core is already initialized!");
            return SuccessExitCode;
        }

        Log::initialize();
        ALRC_CORE_INFO("Core inititialize...");

        auto exitCode = _configManager->initialize(argv[0]);
        if (exitCode != SuccessExitCode)
            return exitCode;

        exitCode = _windowManager->initialize();
        if (exitCode != SuccessExitCode)
            return exitCode;

        Shared<Config> rootConfig = _configManager->rootConfig();
//        _configManager->beginGroup("WindowManager");
//        _windowManager->loadSettings();
//        _configManager->endGroup();

        ALRC_CORE_INFO("Aalforreca engine {}.{}", versionMajor(), versionMinor());

        _window = _windowManager->createWindow();
        _window->setEventCallback(ALRC_BIND_EVENT_FUNCTION(Application::onEvent));

        _running = true;
        _coreInitialized = true;

        return initializeClient();
    }

    ExitCode Application::exec()
    {
        while (_running)
        {
            _window->onUpdate();
        }

        return SuccessExitCode;
    }

    ExitCode Application::initializeClient()
    {
        return _window->initialize(WindowProperties());
    }

    void Application::onEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.dispatch<WindowCloseEvent>(ALRC_BIND_EVENT_FUNCTION(Application::onWindowClose));
    }

    bool Application::onWindowClose(WindowCloseEvent& event)
    {
        _running = false;
        return true;
    }
}
