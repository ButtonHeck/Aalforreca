#pragma once

#include "Aalforreca/core/application.h"

extern Aalforreca::Application* Aalforreca::createApplication();

int main(int argc, char** argv)
{
    auto application = Aalforreca::createApplication();
    auto exitCode = application->initialize();
    if (exitCode == Aalforreca::SuccessExitCode)
        exitCode = application->exec();

    delete application;
    return exitCode;
}
