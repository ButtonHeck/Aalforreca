#pragma once

#include "Aalforreca/graphics/graphics_api.h"

namespace Aalforreca
{
    class OpenGLGraphicsAPI : public IGraphicsAPI
    {
    public:
        virtual ExitCode initialize() override;
        virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
        virtual void setClearColor(const glm::vec4& color) override;
        virtual void clear() override;
    };
}
