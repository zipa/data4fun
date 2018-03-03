#include <spdlogwrap.h>

std::string LogWrap::logName_{ "log" };
std::shared_ptr<spdlog::logger> LogWrap::log_;
spdlog::level::level_enum LogWrap::level_{ spdlog::level::info };

using wrapped_daily_sink = 
    spdlog::sinks::daily_file_sink<spdlog::details::null_mutex, spdlog::sinks::dateonly_daily_file_name_calculator>;

std::shared_ptr<spdlog::logger> LogWrap::MakeLog(const char* src)
{
    static auto dailySink = std::make_shared<wrapped_daily_sink>(logName_.c_str(), 23, 59);
    auto log = std::make_shared<spdlog::logger>(src, dailySink);
    log->set_level(level_);
    log->set_pattern("%Y%m%d-%H:%M:%S.%f%z|%i|%L|%t|%n|%v");
    spdlog::register_logger(log);
    return log;
}

std::shared_ptr<spdlog::logger> LogWrap::GetLog(const char* src)
{
    auto log = spdlog::get(src);
    if (!log)
    {
        log = MakeLog(src);
    }
    return log;
}

void LogWrap::Initialize(const char* name, spdlog::level::level_enum lvl)
{
    if (name != nullptr)
    {
        logName_ = name;
    }
    SetLevel(lvl);
    log_ = MakeLog("LOGGER");
    log_->info("Logging started.");
}

void LogWrap::Shutdown()
{
    log_->info("Logging stopped.");
    spdlog::drop_all();
} 

void LogWrap::SetLevel(spdlog::level::level_enum lvl)
{
    level_ = lvl;
    spdlog::set_level(level_);
}