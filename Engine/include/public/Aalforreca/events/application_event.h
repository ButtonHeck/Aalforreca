#pragma once

#include "Aalforreca/events/event.h"

namespace Aalforreca
{
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
