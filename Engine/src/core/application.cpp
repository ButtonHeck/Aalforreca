#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/application.h"
#include "Aalforreca/core/window.h"
#include "Aalforreca/core/log.h"
#include "Aalforreca/core/vendor_initializer.h"
#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/events/event.h"
#include "Aalforreca/events/application_event.h"
#include <AalforrecaEngineConfig.h>

namespace Aalforreca
{
    Application* Application::_app = nullptr;

    const Application& Application::app()
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


    Application::Application()
    {
        const int vendorOk = initializeVendorModules();
        assert(vendorOk == ExitCode::SuccessExitCode);

        ALRC_CORE_INFO("Aalforreca engine {}.{}", versionMajor(), versionMinor());

        _window = createUnique<Window>();
        _window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

        _running = true;
        _app = this;
    }

    Application::~Application()
    {
        ALRC_CORE_INFO("Engine shutdown...");
        finalizeVendorModules();
    }

    void Application::initialize()
    {
        _window->initialize(WindowProperties());
    }

    int Application::exec()
    {
        while (_running)
        {
            _window->onUpdate();
        }

        return SuccessExitCode;
    }

    void Application::onEvent(Event& event)
    {
        EventDispatcher dispatcher(event);
        dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));

        ALRC_CORE_TRACE(event);
    }

    bool Application::onWindowClose(WindowCloseEvent& event)
    {
        _running = false;
        return true;
    }
}
