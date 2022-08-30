#pragma once

namespace Aalforreca
{
    class Application
    {
    public:
        static Application& app();
        static int versionMajor();
        static int versionMinor();

    protected:
        Application();

    public:
        virtual ~Application();

        int exec();

    private:
        static Application* _app;
        bool _running;
    };

    // Implement this on the application side
    Application* createApplication();
}
