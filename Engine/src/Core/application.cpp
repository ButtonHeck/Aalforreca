#include "alrcpch.h"
#include "Aalforreca/Core/application.h"
#include "Aalforreca/Core/log.h"
#include <AalforrecaEngineConfig.h>

namespace Aalforreca
{
    Application * Application::_app = nullptr;

    Application::Application()
        : _running(true)
    {
        _app = this;
    }

    Application::~Application()
    {
        ALRC_CORE_INFO("Engine shutdown...");
    }

    Application & Application::app()
    {
        return *_app;
    }

    int Application::versionMajor()
    {
        return AALFORRECA_ENGINE_VERSION_MAJOR;
    }

    int Application::versionMinor()
    {
        return AALFORRECA_ENGINE_VERSION_MINOR;
    }

    int Application::exec()
    {
        while (_running)
        {
        }

        return 0;
    }
}
