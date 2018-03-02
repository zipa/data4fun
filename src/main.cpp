#include <iostream>
#include <spdlog/spdlog.h>

using wrapped_daily_sink = 
        spdlog::sinks::daily_file_sink<spdlog::details::null_mutex, spdlog::sinks::dateonly_daily_file_name_calculator>;

int main(int, char**)
{
    spdlog::set_pattern("%Y%m%d-%H:%M:%S.%f%z|%i|%L|%t|%n|%v");
    auto dailySink = std::make_shared<wrapped_daily_sink>("log", 23, 59);
    auto log = std::make_shared<spdlog::logger>(__FUNCTION__, dailySink);
    log->critical("Testing {}", "What?");
    log->info("Logging stopped.");
    spdlog::drop_all();

    std::cout << "Game over.\n";
    return 0;
}