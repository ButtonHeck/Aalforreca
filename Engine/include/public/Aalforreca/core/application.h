#pragma once

#include "Aalforreca/core/pointers.h"

namespace Aalforreca
{
    class Window;

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

        virtual void initialize();

        int exec();

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
