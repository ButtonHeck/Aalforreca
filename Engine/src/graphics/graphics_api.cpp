#include "Aalforreca/alrcpch.h"
#include "Aalforreca/graphics/graphics_api.h"
#include "Aalforreca/opengl/opengl_graphics_api.h"
#include "Aalforreca/core/log.h"

namespace Aalforreca
{
    //todo: temporary opengl only. Make this non-hardcoded in the future (probably via cmake and c++ helper function)
    IGraphicsAPI::API IGraphicsAPI::_api = IGraphicsAPI::API::OpenGLAPI;

    IGraphicsAPI::API IGraphicsAPI::api()
    {
        return _api;
    }

    Unique<IGraphicsAPI> IGraphicsAPI::create()
    {
        switch(_api)
        {
        case IGraphicsAPI::API::NoneAPI:
            ALRC_CORE_CRITICAL("Graphics API is not provided");
            return nullptr;

        case IGraphicsAPI::API::OpenGLAPI:
            return createUnique<OpenGLGraphicsAPI>();

        default:
            ALRC_CORE_CRITICAL("Unknown graphics API");
            return nullptr;
        }
    }
}
