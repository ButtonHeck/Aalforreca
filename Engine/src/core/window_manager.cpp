#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/window_manager.h"
#include "Aalforreca/core/window.h"
#include "Aalforreca/core/log.h"
#include "Aalforreca/core/config.h"
#include "Aalforreca/core/helper_macros.h"

#include <GLFW/glfw3.h>

namespace Aalforreca
{
    ALRC_SINGLETON(WindowManager)

    WindowManager::WindowManager()
        : _windowCount(0)
    {
    }

    WindowManager::~WindowManager()
    {
        if (_windowCount != 0)
            ALRC_CORE_WARN("Some windows were not destroyed during shutdown");

        glfwTerminate();
    }

    ExitCode WindowManager::initialize()
    {
        ALRC_CORE_TRACE("Window manager initialize...");

        if (glfwInit() != GLFW_TRUE)
        {
            ALRC_CORE_CRITICAL("GLFW Initialization error");
            return WindowInitializationFailExitCode;
        }

        return SuccessExitCode;
    }

    void WindowManager::saveSettings(Shared<Config> config)
    {
        ALRC_UNUSED(config);
    }

    void WindowManager::loadSettings(Shared<Config> config)
    {
        ALRC_UNUSED(config);
    }

    Unique<Window> WindowManager::createWindow()
    {
        _windowCount++;
        return createUnique<Window>(this);
    }

    void WindowManager::destroyWindow(GLFWwindow* window)
    {
        _windowCount--;
        glfwDestroyWindow(window);
    }
}
