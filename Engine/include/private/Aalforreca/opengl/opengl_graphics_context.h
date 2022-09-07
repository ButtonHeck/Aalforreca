#pragma once

#include "Aalforreca/graphics/graphics_context.h"

struct GLFWwindow;

namespace Aalforreca
{
    class OpenGLGraphicsContext : public IGraphicsContext
    {
    public:
        OpenGLGraphicsContext(GLFWwindow* windowHandle);

        ExitCode initialize() override;

    private:
        GLFWwindow* const _windowHandle;
    };
}
