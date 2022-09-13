#include "Aalforreca/alrcpch.h"
#include "Aalforreca/core/log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Aalforreca
{
    Shared<spdlog::logger> Log::_coreLogger;
    Shared<spdlog::logger> Log::_clientLogger;

    void Log::initialize()
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.emplace_back(createShared<spdlog::sinks::stdout_color_sink_mt>(spdlog::color_mode::automatic));
        logSinks.emplace_back(createShared<spdlog::sinks::basic_file_sink_mt>("Aalforreca.log", true));

        logSinks[0]->set_pattern("%^[%T.%e] %n: %v%$");
        logSinks[1]->set_pattern("[%T.%e] [%l] %n: %v");

        _coreLogger = createShared<spdlog::logger>("CORE", begin(logSinks), end(logSinks));
        spdlog::register_logger(_coreLogger);
        _coreLogger->set_level(spdlog::level::trace);
        _coreLogger->flush_on(spdlog::level::trace);

        _clientLogger = createShared<spdlog::logger>("CLIENT", begin(logSinks), end(logSinks));
        spdlog::register_logger(_clientLogger);
        _clientLogger->set_level(spdlog::level::trace);
        _clientLogger->flush_on(spdlog::level::trace);
    }

    Shared<spdlog::logger>& Log::coreLogger()
    {
        return _coreLogger;
    }

    Shared<spdlog::logger>& Log::clientLogger()
    {
        return _clientLogger;
    }

}
