#pragma once

#include "Aalforreca/Core/pointers.h"
#include "Aalforreca/Core/application.h"
#include "Aalforreca/Core/log.h"

extern Aalforreca::Application * Aalforreca::createApplication();

int main(int argc, char** argv)
{
    Aalforreca::Log::init();
    ALRC_CORE_INFO("Aalforreca engine {}.{}", Aalforreca::Application::versionMajor(), Aalforreca::Application::versionMinor());

    auto application = Aalforreca::createApplication();
    const auto execCode = application->exec();
    delete application;
    return execCode;
}
