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

    ~Sandbox()
    {
        ALRC_INFO("Sandbox shutdown...");
    }
};

Aalforreca::Application * Aalforreca::createApplication()
{
    return new Sandbox();
}
