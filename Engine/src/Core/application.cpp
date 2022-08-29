#include "alrcpch.h"
#include "Core/application.h"

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
    }

    Application & Application::get()
    {
        return *_app;
    }

    int Application::exec()
    {
        while (_running)
        {
        }

        return 0;
    }

}
