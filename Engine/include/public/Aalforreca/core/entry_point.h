#pragma once

#include "Aalforreca/core/pointers.h"
#include "Aalforreca/core/application.h"
#include "Aalforreca/core/log.h"

extern Aalforreca::Application * Aalforreca::createApplication();

int main(int argc, char** argv)
{
    Aalforreca::Log::init();
//    ALRC_CORE_INFO("Aalforreca engine {}.{}", Aalforreca::Application::versionMajor(), Aalforreca::Application::versionMinor());

    auto application = Aalforreca::createApplication();
    const auto execCode = application->exec();
    delete application;
    return execCode;
}
