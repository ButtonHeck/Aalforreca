#pragma once

#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/core/pointers.h"
#include "Aalforreca/core/singleton.h"

struct GLFWwindow;

namespace Aalforreca
{
    class Window;
    class Config;

    class WindowManager : public Singleton<WindowManager>
    {
    public:
        WindowManager();
        ~WindowManager();

        ExitCode initialize();

        void saveSettings(Shared<Config> config);
        void loadSettings(Shared<Config> config);

        Unique<Window> createWindow();
        void destroyWindow(GLFWwindow* window);

    private:
        uint8_t _windowCount;
    };
}
