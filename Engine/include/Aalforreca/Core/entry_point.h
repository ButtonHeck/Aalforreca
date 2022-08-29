#pragma once

#include "Aalforreca/Core/application.h"

extern Aalforreca::Application * Aalforreca::createApplication();

int main(int argc, char** argv)
{
    auto application = Aalforreca::createApplication();
    const auto execCode = application->exec();
    delete application;
    return execCode;
}
