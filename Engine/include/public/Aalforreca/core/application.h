#pragma once

#include "Aalforreca/core/pointers.h"
#include "Aalforreca/core/exit_codes.h"

namespace Aalforreca
{
    class Window;
    struct Event;
    struct WindowCloseEvent;

    class Application
    {
    public:
        static const Application& app();
        static int versionMajor();
        static int versionMinor();

    protected:
        Application();

    public:
        virtual ~Application();

        virtual ExitCode initialize();

        ExitCode exec();
        void onEvent(Event& event);

    private:
        bool onWindowClose(WindowCloseEvent& event);

    private:
        static Application* _app;

    protected:
        Unique<Window> _window;

    private:
        bool _running;
    };

    // Implement this on the application side
    Application* createApplication();
}
