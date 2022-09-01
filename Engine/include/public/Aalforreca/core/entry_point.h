#pragma once

#include "Aalforreca/core/application.h"

extern Aalforreca::Application* Aalforreca::createApplication();

int main(int argc, char** argv)
{
    auto application = Aalforreca::createApplication();
    application->initialize();
    const auto execCode = application->exec();
    delete application;
    return execCode;
}
