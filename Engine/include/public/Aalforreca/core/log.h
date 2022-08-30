#pragma once

#include "Aalforreca/core/pointers.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Aalforreca
{
    class Log
    {
    public:
        static void init();
        static Shared<spdlog::logger> & coreLogger();
        static Shared<spdlog::logger> & clientLogger();

    private:
        static Shared<spdlog::logger> _coreLogger;
        static Shared<spdlog::logger> _clientLogger;
    };
}

#ifdef ALRC_USE_CORE_LOGGER
#define ALRC_CORE_TRACE(...)    ::Aalforreca::Log::coreLogger()->trace(__VA_ARGS__)
#define ALRC_CORE_INFO(...)     ::Aalforreca::Log::coreLogger()->info(__VA_ARGS__)
#define ALRC_CORE_WARN(...)     ::Aalforreca::Log::coreLogger()->warn(__VA_ARGS__)
#define ALRC_CORE_ERROR(...)    ::Aalforreca::Log::coreLogger()->error(__VA_ARGS__)
#define ALRC_CORE_CRITICAL(...) ::Aalforreca::Log::coreLogger()->critical(__VA_ARGS__)
#else
#define ALRC_TRACE(...)         ::Aalforreca::Log::clientLogger()->trace(__VA_ARGS__)
#define ALRC_INFO(...)          ::Aalforreca::Log::clientLogger()->info(__VA_ARGS__)
#define ALRC_WARN(...)          ::Aalforreca::Log::clientLogger()->warn(__VA_ARGS__)
#define ALRC_ERROR(...)         ::Aalforreca::Log::clientLogger()->error(__VA_ARGS__)
#define ALRC_CRITICAL(...)      ::Aalforreca::Log::clientLogger()->critical(__VA_ARGS__)
#endif
