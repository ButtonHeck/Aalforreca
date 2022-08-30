#pragma once

#include "Aalforreca/events/event.h"
#include "Aalforreca/core/key_codes.h"

namespace Aalforreca
{
    struct KeyEvent : public Event
    {
        KeyCode keyCode() const
        {
            return _keyCode;
        }

        EVENT_CLASS_CATEGORY(KeyboardEventCategory | InputEventCategory)

    protected:
        KeyEvent(const KeyCode keyCode)
            : _keyCode(keyCode)
        {}

        KeyCode _keyCode;
    };


    struct KeyPressedEvent : public KeyEvent
    {
        KeyPressedEvent(const KeyCode keyCode, bool repeat = false)
            : KeyEvent(keyCode)
            , _repeat(repeat)
        {}

        bool repeat() const
        {
            return _repeat;
        }

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << _keyCode << " (repeat = " << _repeat << ")";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressedEventType)

    private:
        bool _repeat;
    };


    struct KeyReleasedEvent : public KeyEvent
    {
        KeyReleasedEvent(const KeyCode keyCode)
            : KeyEvent(keyCode)
        {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << _keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleasedEventType)
    };


    struct KeyTypedEvent : public KeyEvent
    {
        KeyTypedEvent(const KeyCode keyCode)
            : KeyEvent(keyCode)
        {}

        std::string toString() const override
        {
            std::stringstream ss;
            ss << "KeyTypedEvent: " << _keyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyTypedEventType)
    };
}
