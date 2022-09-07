#pragma once

#include "Aalforreca/core/pointers.h"
#include "Aalforreca/core/exit_codes.h"

#include <glm/vec4.hpp>

namespace Aalforreca
{
    class IGraphicsAPI
    {
    public:
        enum class API
        {
            NoneAPI = 0,
            OpenGLAPI
        };

        static API api();
        static Unique<IGraphicsAPI> create();

    private:
        static API _api;

    public:
        virtual ~IGraphicsAPI() = default;

        virtual ExitCode initialize() = 0;
        virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
        virtual void setClearColor(const glm::vec4& color) = 0;
        virtual void clear() = 0;
    };
}
