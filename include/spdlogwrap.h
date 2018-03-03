#ifndef _SPDLOGWRAP_H_
#define _SPDLOGWRAP_H_

#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>

class LogWrap
{
public:
    static void Initialize(const char* name = nullptr, spdlog::level::level_enum lvl = spdlog::level::info);
    static void Shutdown();
    static std::shared_ptr<spdlog::logger> MakeLog(const char* src);
    static std::shared_ptr<spdlog::logger> GetLog(const char* src);
    static void SetLevel(spdlog::level::level_enum lvl);

private:
    static std::string logName_;
    static std::shared_ptr<spdlog::logger> log_;
    static spdlog::level::level_enum level_;

    LogWrap() = delete;
    LogWrap(const LogWrap&) = delete;
    LogWrap(LogWrap&&) = delete;
    ~LogWrap() = delete;
    LogWrap& operator=(const LogWrap&) = delete;
    LogWrap& operator=(LogWrap&&) = delete;
};

#endif // _SPDLOGWRAP_H_