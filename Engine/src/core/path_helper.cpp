#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/path_helper.h"

namespace Aalforreca
{
    namespace PathHelper
    {
        std::string path(const char* prefix, const char* filename)
        {
            return std::filesystem::path(prefix).append(filename).string();
        }

        std::string stripFilename(const char* fullFilename)
        {
            return std::filesystem::path(fullFilename).filename().string();
        }

    }
}
