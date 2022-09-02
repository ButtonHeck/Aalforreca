#pragma once

#define ALRC_UNUSED(x) (void)x

#define ALRC_BIND_EVENT_FUNCTION(func) [this](auto&& ... args) { return this->func(std::forward<decltype(args)>(args)...); }
