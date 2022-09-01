#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/window.h"
#include "Aalforreca/core/log.h"
#include "Aalforreca/core/helper_macros.h"
#include "Aalforreca/events/application_event.h"
#include "Aalforreca/events/key_event.h"
#include "Aalforreca/events/mouse_event.h"

#include <GLFW/glfw3.h>

namespace Aalforreca
{
    static void GLFWerrorCallback(int errorCode, const char* description)
    {
        ALRC_CORE_ERROR("GLFW error ({}): {}", errorCode, description);
    }

    static uint8_t alrcWindowCount = 0;


    Window::~Window()
    {
        glfwDestroyWindow(_window);
        --alrcWindowCount;
    }

    void Window::initialize(const WindowProperties& props)
    {
        _userData.title = props.title;

        glfwSetErrorCallback(GLFWerrorCallback);

        GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* vidmode = glfwGetVideoMode(primaryMonitor);
        if (!props.fullscreen && (props.resolution.width > vidmode->width || props.resolution.height > vidmode->height))
        {
            _userData.resolution = WindowProperties().resolution;
            ALRC_CORE_WARN("Given resolution ({}x{}) is more than your display supports ({}x{}), resolution set to default",
                           props.resolution.width, props.resolution.height, vidmode->width, vidmode->height);
        }
        else
        {
            _userData.resolution = props.fullscreen ? WindowResolution{uint32_t(vidmode->width), uint32_t(vidmode->height)} : props.resolution;
        }

        ALRC_CORE_INFO("Initializing window \"{}\" ({}x{}, fullscreen: {}, vSync: {})", props.title, props.resolution.width, props.resolution.height, props.fullscreen, props.vSync);

#if ALRC_DEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif

        _window = glfwCreateWindow(int(_userData.resolution.width), int(_userData.resolution.height), _userData.title, props.fullscreen ? primaryMonitor : nullptr, nullptr);
        ++alrcWindowCount;

        // todo context
        glfwMakeContextCurrent(_window);

        glfwSetWindowUserPointer(_window, &_userData);
        setVSync(props.vSync);
        initCallbacks();
    }

    void Window::onUpdate()
    {
        // todo context
        //glfwPollEvents();
    }

    uint32_t Window::width() const
    {
        return _userData.resolution.width;
    }

    uint32_t Window::height() const
    {
        return _userData.resolution.height;
    }

    void Window::setEventCallback(const EventCallback& callback)
    {
        _userData.eventCallback = callback;
    }

    void Window::setVSync(bool enabled)
    {
        glfwSwapInterval(enabled ? 1 : 0);
        _userData.vSync = enabled;
    }

    bool Window::vSync() const
    {
        return _userData.vSync;
    }

    void Window::initCallbacks()
    {
        glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, int width, int height)
        {
            WindowUserData& data = *(static_cast<WindowUserData*>(glfwGetWindowUserPointer(window)));
            data.resolution.width = width;
            data.resolution.height = height;

            WindowResizeEvent event(width, height);
            data.eventCallback(event);
        });

        glfwSetWindowCloseCallback(_window, [](GLFWwindow* window)
        {
            WindowUserData& data = *(static_cast<WindowUserData*>(glfwGetWindowUserPointer(window)));

            WindowCloseEvent event;
            data.eventCallback(event);
        });

        glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            ALRC_UNUSED(scancode);
            ALRC_UNUSED(mods);

            WindowUserData& data = *(static_cast<WindowUserData*>(glfwGetWindowUserPointer(window)));

            switch (action)
            {
            case GLFW_PRESS:
            {
                KeyPressedEvent event(key, 0);
                data.eventCallback(event);
                break;
            }

            case GLFW_RELEASE:
            {
                KeyReleasedEvent event(key);
                data.eventCallback(event);
                break;
            }
            case GLFW_REPEAT:
            {
                KeyPressedEvent event(key, true);
                data.eventCallback(event);
                break;
            }
            }
        });

        glfwSetCharCallback(_window, [](GLFWwindow* window, unsigned int keyCode)
        {
            WindowUserData& data = *(static_cast<WindowUserData*>(glfwGetWindowUserPointer(window)));

            KeyTypedEvent event(keyCode);
            data.eventCallback(event);
        });

        glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods)
        {
            ALRC_UNUSED(mods);

            WindowUserData& data = *(static_cast<WindowUserData*>(glfwGetWindowUserPointer(window)));

            switch (action)
            {
            case GLFW_PRESS:
            {
                MouseButtonPressedEvent event(button);
                data.eventCallback(event);
                break;
            }
            case GLFW_RELEASE:
            {
                MouseButtonReleasedEvent event(button);
                data.eventCallback(event);
                break;
            }
            }
        });

        glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowUserData& data = *(static_cast<WindowUserData*>(glfwGetWindowUserPointer(window)));

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.eventCallback(event);
        });

        glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowUserData& data = *(static_cast<WindowUserData*>(glfwGetWindowUserPointer(window)));

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.eventCallback(event);
        });
    }
}
