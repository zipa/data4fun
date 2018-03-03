#include <iostream>
#include <memory>
#include <spdlog/spdlog.h>

class LogWrap
{
public:
    static void Initialize(const char* name = nullptr);
    static void Shutdown();
    static std::shared_ptr<spdlog::logger> MakeLog(const char* src);
    static std::shared_ptr<spdlog::logger> GetLog(const char* src);

private:
    static std::string logName_;
    static std::shared_ptr<spdlog::logger> log_;

    LogWrap() = delete;
    LogWrap(const LogWrap&) = delete;
    LogWrap(LogWrap&&) = delete;
    ~LogWrap() = delete;
    LogWrap& operator=(const LogWrap&) = delete;
    LogWrap& operator=(LogWrap&&) = delete;
};
