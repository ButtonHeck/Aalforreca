#include <Aalforreca/Aalforreca.h>
#include <Aalforreca/core/main.h>

class Sandbox : public Aalforreca::Application
{
public:
    Sandbox()
        : Aalforreca::Application()
    {
    }

    Aalforreca::ExitCode initializeClient() override final
    {
        ALRC_CLIENT_INFO("Sandbox initialize...");

        Aalforreca::WindowProperties windowProps;
        windowProps.title = "Sandbox";
        windowProps.resolution = {1920, 1080};
        windowProps.fullscreen = false;
        windowProps.iconFilename = Aalforreca::PathHelper::path(ALRC_APP_ASSETS_PATH, "sandbox.png");

        return _window->initialize(windowProps);
    }

    ~Sandbox()
    {
        ALRC_CLIENT_INFO("Sandbox shutdown...");
    }
};

Aalforreca::Application* Aalforreca::createApplication()
{
    return new Sandbox();
}
