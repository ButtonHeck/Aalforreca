#include "Aalforreca/alrcpch.h"
#include "Aalforreca/graphics/graphics_context.h"
#include "Aalforreca/graphics/graphics_api.h"
#include "Aalforreca/opengl/opengl_graphics_context.h"
#include "Aalforreca/core/log.h"

namespace Aalforreca
{
    Unique<IGraphicsContext> IGraphicsContext::create(void* windowHandle)
    {
        switch (IGraphicsAPI::api())
        {
        case IGraphicsAPI::API::NoneAPI:
            ALRC_CORE_CRITICAL("Graphics API is not provided");
            return nullptr;

        case IGraphicsAPI::API::OpenGLAPI:
            return createUnique<OpenGLGraphicsContext>(static_cast<GLFWwindow*>(windowHandle));

        default:
            ALRC_CORE_CRITICAL("Unknown graphics API");
            return nullptr;
        }
    }
}
