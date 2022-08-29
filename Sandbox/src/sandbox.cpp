#include <Aalforreca/Core/entry_point.h>

class Sandbox : public Aalforreca::Application
{
public:
    Sandbox()
        : Aalforreca::Application()
    {}

    ~Sandbox()
    {}
};

Aalforreca::Application * Aalforreca::createApplication()
{
    return new Sandbox();
}
