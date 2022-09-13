#pragma once

#include "Aalforreca/events/event.h"
#include "Aalforreca/core/exit_codes.h"
#include "Aalforreca/graphics/graphics_context.h"

#include <functional>

struct GLFWwindow;

namespace Aalforreca
{
    class WindowManager;

    struct WindowResolution
    {
        uint32_t width;
        uint32_t height;
    };

    struct WindowProperties
    {
        const char* title;
        WindowResolution resolution;
        bool fullscreen;
        bool vSync;
        std::string iconFilename;

        WindowProperties(const char* title = "Aalforreca window", WindowResolution resolution = {800, 600}, bool fullscreen = false, bool vSync = true,
                         std::string iconFilename = "")
            : title(title)
            , resolution(resolution)
            , fullscreen(fullscreen)
            , vSync(vSync)
            , iconFilename(iconFilename)
        {}
    };


    class Window
    {
        using EventCallback = std::function<void(Event&)>;

    public:
        Window(WindowManager* manager);
        ~Window();

        ExitCode initialize(const WindowProperties& props);
        void onUpdate();

        uint32_t width() const;
        uint32_t height() const;

        void setEventCallback(const EventCallback& callback);

        void setVSync(bool enabled);
        bool vSync() const;

    private:
        struct WindowUserData
        {
            const char* title;
            WindowResolution resolution;
            bool vSync;
            EventCallback eventCallback;
        };

    private:
        void initCallbacks();
        void loadIcon(const char* filename);

    private:
        WindowManager* const _manager;
        GLFWwindow* _window;
        WindowUserData _userData;
        Unique<IGraphicsContext> _context;
    };
}
