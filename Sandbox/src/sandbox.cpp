#include <Aalforreca/Aalforreca.h>
#include <Aalforreca/core/entry_point.h>

class Sandbox : public Aalforreca::Application
{
public:
    Sandbox()
        : Aalforreca::Application()
    {
        ALRC_INFO("Sandbox start...");
    }

    void initialize() override final
    {
        Aalforreca::WindowProperties windowProps;
        windowProps.title = "Sandbox";
        windowProps.resolution = {1920, 1080};
        windowProps.fullscreen = false;

        _window->initialize(windowProps);
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
