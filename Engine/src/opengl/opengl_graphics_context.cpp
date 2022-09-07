#include "Aalforreca/alrcpch.h"
#include "Aalforreca/opengl/opengl_graphics_context.h"
#include "Aalforreca/core/log.h"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Aalforreca
{
    OpenGLGraphicsContext::OpenGLGraphicsContext(GLFWwindow* windowHandle)
        : _windowHandle(windowHandle)
    {
    }

    ExitCode OpenGLGraphicsContext::initialize()
    {
        glfwMakeContextCurrent(_windowHandle);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            ALRC_CORE_CRITICAL("Failed to initialize OpenGL graphics context (error with glad)");
            return ContextInitializationFailExitCode;
        }

        ALRC_CORE_INFO("OpenGL Context:");
        ALRC_CORE_INFO("  Vendor: {}", glGetString(GL_VENDOR));
        ALRC_CORE_INFO("  Renderer: {}", glGetString(GL_RENDERER));
        ALRC_CORE_INFO("  Version: {}", glGetString(GL_VERSION));

        return SuccessExitCode;
    }
}
