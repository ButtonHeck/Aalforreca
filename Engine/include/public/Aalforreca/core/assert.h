#pragma once

#ifndef NDEBUG
    #include "Aalforreca/core/log.h"
    #include "Aalforreca/core/platform_detection.h"

    #include <filesystem>

    #ifdef ALRC_PLATFORM_LINUX
        #include <signal.h>
        #define ALRC_DEBUGBREAK() raise(SIGTRAP)
    #elif defined (ALRC_PLATFORM_WINDOWS)
        #define ALRC_DEBUGBREAK() __debugbreak()
    #endif

    #define ALRC_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { ALRC##type##ERROR(msg, __VA_ARGS__); ALRC_DEBUGBREAK(); } }
    #define ALRC_INTERNAL_ASSERT_MSG(type, check, ...) ALRC_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {}", __VA_ARGS__)
    #define ALRC_INTERNAL_ASSERT_NO_MSG(type, check) ALRC_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{}' failed at {}:{}", #check, std::filesystem::path(__FILE__).filename().string(), __LINE__)

    #define ALRC_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
    #define ALRC_INTERNAL_ASSERT_GET_MACRO(...) ALRC_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, ALRC_INTERNAL_ASSERT_MSG, ALRC_INTERNAL_ASSERT_NO_MSG)

    #ifdef ALRC_MACRO_USE_CORE_PREFIX
        #define ALRC_CORE_ASSERT(...) ALRC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__)
    #else
        #define ALRC_ASSERT(...) ALRC_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__)
    #endif
#else
    #ifdef ALRC_MACRO_USE_CORE_PREFIX
        #define ALRC_CORE_ASSERT(...)
    #else
        #define ALRC_ASSERT(...)
    #endif
#endif
