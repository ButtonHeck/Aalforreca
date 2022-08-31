#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/vendor_initializer.h"

#include <GLFW/glfw3.h>

namespace Aalforreca
{
    int initializeVendorModules()
    {
        const auto glfwInitResult = glfwInit();
        if (glfwInitResult != GLFW_TRUE)
            return -1;

        return 0;
    }

    void finalizeVendorModules()
    {
        glfwTerminate();
    }

}
