#pragma once

#include "Aalforreca/core/pointers.h"
#include "Aalforreca/core/exit_codes.h"

namespace Aalforreca
{
    class IGraphicsContext
    {
    public:
        static Unique<IGraphicsContext> create(void* windowHandle);

    public:
        virtual ~IGraphicsContext() = default;

        virtual ExitCode initialize() = 0;
    };
}
