#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/vendor_initializer.h"
#include "Aalforreca/core/log.h"
#include "Aalforreca/core/exit_codes.h"

#include <GLFW/glfw3.h>

namespace Aalforreca
{
    int initializeVendorModules()
    {
        Log::init();

        const int glfwInitCode = glfwInit();
        if (glfwInitCode != GLFW_TRUE)
            return VendorLibrariesInitFailedExitCode;

        return SuccessExitCode;
    }

    void finalizeVendorModules()
    {
        glfwTerminate();
    }

}
