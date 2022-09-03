#pragma once

#include <string>

namespace Aalforreca
{
    enum class EventType
    {
        None = 0,

        WindowCloseEventType,
        WindowResizeEventType,
        WindowMovedEventType,
        WindowFocusEventType,
        WindowIconifyEventType,
        WindowFramebufferResizeEventType,

        ApplicaionTickEventType,
        ApplicaionUpdateEventType,
        ApplicaionRenderEventType,

        KeyPressedEventType,
        KeyReleasedEventType,
        KeyTypedEventType,

        MouseButtonPressedEventType,
        MouseButtonReleasedEventType,
        MouseMovedEventType,
        MouseScrolledEventType
    };


    enum EventCategory
    {
        None = 0,
        ApplicationEventCategory = 1 << 0,
        WindowEventCategory      = 1 << 1,
        InputEventCategory       = 1 << 2,
        KeyboardEventCategory    = 1 << 3,
        MouseEventCategory       = 1 << 4,
        MouseButtonEventCategory = 1 << 5
    };

#define EVENT_CLASS_TYPE(eventType) \
    static EventType staticType() { return EventType::eventType; } \
    virtual EventType type() const override { return staticType(); } \
    virtual const char* name() const override { return #eventType; }

#define EVENT_CLASS_CATEGORY(category) \
    virtual int categoryFlags() const override { return category; }


    struct Event
    {
        virtual ~Event() = default;

        virtual EventType type() const = 0;
        virtual const char* name() const = 0;
        virtual int categoryFlags() const = 0;
        virtual std::string toString() const
        {
            return name();
        }

        bool isInCategory(EventCategory category)
        {
            return categoryFlags() & category;
        }

        bool handled = false;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& event)
    {
        return os << event.toString();
    }


    class EventDispatcher
    {
    public:
        EventDispatcher(Event& event)
            : _event(event)
        {}

        template<typename E, typename F>
        bool dispatch(const F& func)
        {
            if (_event.type() == E::staticType())
            {
                _event.handled |= func(static_cast<E&>(_event));
                return true;
            }
            return false;
        }

    private:
        Event& _event;
    };
}
