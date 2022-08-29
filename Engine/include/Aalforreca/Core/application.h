#pragma once

namespace Aalforreca
{
    class Application
    {
    protected:
        Application();

    public:
        virtual ~Application();

        static Application & get();
        int exec();

    private:
        static Application * _app;
        bool _running;
    };

    Application * createApplication();
}
