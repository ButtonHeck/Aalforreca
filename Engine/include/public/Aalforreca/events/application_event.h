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
        EVENT_CLASS_CATEGORY(ApplicationEventCategory)

    private:
        unsigned int _width;
        unsigned int _height;
    };


    struct WindowCloseEvent : public Event
    {
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowCloseEventType)
        EVENT_CLASS_CATEGORY(ApplicationEventCategory)
    };


    struct ApplicaionTickEvent : public Event
    {
        ApplicaionTickEvent() = default;

        EVENT_CLASS_TYPE(ApplicaionTickEventType)
        EVENT_CLASS_CATEGORY(ApplicationEventCategory)
    };


    struct ApplicationUpdateEvent : public Event
    {
        ApplicationUpdateEvent() = default;

        EVENT_CLASS_TYPE(ApplicaionUpdateEventType)
        EVENT_CLASS_CATEGORY(ApplicationEventCategory)
    };


    struct ApplicationRenderEvent : public Event
    {
        ApplicationRenderEvent() = default;

        EVENT_CLASS_TYPE(ApplicaionRenderEventType)
        EVENT_CLASS_CATEGORY(ApplicationEventCategory)
    };
}
