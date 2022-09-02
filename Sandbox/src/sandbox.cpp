#include <Aalforreca/Aalforreca.h>
#include <Aalforreca/core/main.h>

class Sandbox : public Aalforreca::Application
{
public:
    Sandbox()
        : Aalforreca::Application()
    {
        ALRC_INFO("Sandbox start...");
    }

    Aalforreca::ExitCode initialize() override final
    {
        Aalforreca::WindowProperties windowProps;
        windowProps.title = "Sandbox";
        windowProps.resolution = {1920, 1080};
        windowProps.fullscreen = false;

        return _window->initialize(windowProps);
    }

    ~Sandbox()
    {
        ALRC_INFO("Sandbox shutdown...");
    }
};

Aalforreca::Application* Aalforreca::createApplication()
{
    return new Sandbox();
}
