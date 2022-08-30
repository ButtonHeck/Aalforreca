#pragma once

#include "Aalforreca/events/event.h"
#include "Aalforreca/core/mouse_codes.h"

namespace Aalforreca
{
    struct MouseMovedEvent : public Event
    {
        MouseMovedEvent(float x, float y)
            : _x(x)
            , _y(y)
        {}

        float x() const
        {
            return _x;
        }

        float y() const
        {
            return _y;
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << _x << ", " << _y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMovedEventType)
        EVENT_CLASS_CATEGORY(MouseEventCategory | InputEventCategory)

    private:
        float _x;
        float _y;
    };


    struct MouseScrolledEvent : public Event
    {
        MouseScrolledEvent(float xOffset, float yOffset)
            : _xOffset(xOffset)
            , _yOffset(yOffset)
        {}

        float xOffset() const
        {
            return _xOffset;
        }

        float yOffset() const
        {
            return _yOffset;
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << _xOffset << ", " << _yOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolledEventType)
        EVENT_CLASS_CATEGORY(MouseEventCategory | InputEventCategory)

    private:
        float _xOffset;
        float _yOffset;
    };


    struct MouseButtonEvent : public Event
    {
        MouseCode mouseButton() const
        {
            return _button;
        }

        EVENT_CLASS_CATEGORY(MouseEventCategory | InputEventCategory | MouseButtonEventCategory)

    protected:
        MouseButtonEvent(const MouseCode button)
            : _button(button)
        {}

        MouseCode _button;
    };


    struct MouseButtonPressedEvent : public MouseButtonEvent
    {
        MouseButtonPressedEvent(const MouseCode button)
            : MouseButtonEvent(button)
        {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressedEventType)
    };


    struct MouseButtonReleasedEvent : public MouseButtonEvent
    {
        MouseButtonReleasedEvent(const MouseCode button)
            : MouseButtonEvent(button)
        {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleasedEventType)
    };
}
