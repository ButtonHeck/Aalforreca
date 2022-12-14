#pragma once

#include "Aalforreca/core/pointers.h"
#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/singleton.h"
#include "Aalforreca/core/root.h"

namespace Aalforreca
{
    class Window;
    struct Event;
    struct WindowCloseEvent;

    class Application : public Singleton<Application>, private Root
    {
    public:
        static int versionMajor();
        static int versionMinor();

    protected:
        Application() = default;

    public:
        virtual ~Application();

        ExitCode initialize(int argc, char** argv);
        ExitCode exec();

    protected:
        virtual ExitCode initializeClient();

    private:
        void onEvent(Event& event);
        bool onWindowClose(WindowCloseEvent& event);
        void loadSettings();

    protected:
        Unique<Window> _window;

    private:
        bool _initialized;
        bool _running;
    };

    // Implement this on the application side
    Application* createApplication();
}
