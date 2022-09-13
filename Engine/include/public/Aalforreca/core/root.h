#pragma once

#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/pointers.h"

namespace Aalforreca
{
    class WindowManager;

    class Root
    {
    protected:
        Root();
        ~Root();

        ExitCode initializeRoot();

    protected:
        Unique<WindowManager> _windowManager;
    };
}
