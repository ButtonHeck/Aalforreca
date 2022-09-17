#pragma once

#include <string>

namespace Aalforreca
{
    namespace PathHelper
    {
        std::string path(const char* prefix, const char* filename);
        std::string stripFilename(const char* fullFilename);
    }
}
