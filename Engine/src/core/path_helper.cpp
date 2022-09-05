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
    }
}
