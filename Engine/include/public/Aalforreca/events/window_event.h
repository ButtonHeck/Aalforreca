#pragma once

#include "Aalforreca/events/event.h"

namespace Aalforreca
{
    struct WindowResizeEvent : public Event
    {
        WindowResizeEvent(unsigned int width, unsigned int height)
            : _width(width)
            , _height(height)
        {}

        unsigned int width() const
        {
            return _width;
        }

        unsigned int height() const
        {
            return _height;
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << _width << ", " << _height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResizeEventType)
        EVENT_CLASS_CATEGORY(WindowEventCategory)

    private:
        unsigned int _width;
        unsigned int _height;
    };


    struct WindowMovedEvent : public Event
    {
        WindowMovedEvent(unsigned int x, unsigned int y)
            : _x(x)
            , _y(y)
        {}

        unsigned int x() const
        {
            return _x;
        }

        unsigned int y() const
        {
            return _y;
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowMovedEvent: " << _x << ", " << _y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMovedEventType)
        EVENT_CLASS_CATEGORY(WindowEventCategory)

    private:
        unsigned int _x;
        unsigned int _y;
    };


    struct WindowCloseEvent : public Event
    {
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowCloseEventType)
        EVENT_CLASS_CATEGORY(WindowEventCategory)
    };


    struct WindowFocusEvent : public Event
    {
        WindowFocusEvent(int focused)
            : _focused(focused)
        {}

        bool focused() const
        {
            return bool(_focused);
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowFocusEvent: " << focused();
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowFocusEventType)
        EVENT_CLASS_CATEGORY(WindowEventCategory)

    private:
        int _focused;
    };


    struct WindowIconifyEvent : public Event
    {
        WindowIconifyEvent(int iconified)
            : _iconified(iconified)
        {}

        bool iconified() const
        {
            return bool(_iconified);
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowIconifyEvent: " << iconified();
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowIconifyEventType)
        EVENT_CLASS_CATEGORY(WindowEventCategory)

    private:
        int _iconified;
    };


    struct WindowFramebufferResizeEvent : public Event
    {
        WindowFramebufferResizeEvent(unsigned int width, unsigned int height)
            : _width(width)
            , _height(height)
        {}

        unsigned int width() const
        {
            return _width;
        }

        unsigned int height() const
        {
            return _height;
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "WindowFramebufferResizeEvent: " << _width << ", " << _height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowFramebufferResizeEventType)
        EVENT_CLASS_CATEGORY(WindowEventCategory)

    private:
        unsigned int _width;
        unsigned int _height;
    };
}
