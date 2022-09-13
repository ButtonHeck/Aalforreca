#pragma once

#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/pointers.h"
#include "Aalforreca/core/singleton.h"

struct GLFWwindow;

namespace Aalforreca
{
    class Window;

    class WindowManager : public Singleton<WindowManager>
    {
    public:
        WindowManager();
        ~WindowManager();

        ExitCode initialize();

        Unique<Window> createWindow();
        void destroyWindow(GLFWwindow* window);

    private:
        uint8_t _windowCount;
    };
}
