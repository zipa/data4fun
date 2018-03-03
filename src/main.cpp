#include <iostream>
#include <memory>
#include <exception>
#include <spdlogwrap.h>

#include <GLhelper.h>

using namespace std;

class Test
{
public:
    Test()
    {
        log_ = LogWrap::GetLog("Test");
        log_->info("Test constructor.");
    }

    int DoSomething()
    {
        log_->info("::{}| Doing something... {}", __func__, "no context here");
    }
private:
    std::shared_ptr<spdlog::logger> log_;
};

int main(int, char**)
{
    LogWrap::Initialize("log", spdlog::level::trace);
    auto log = LogWrap::GetLog("MAIN");

    Test t;
    t.DoSomething();

    try
    {
        GLhelper glh;
        glh.Run();
    }
    catch(std::runtime_error& ex)
    {
        log->critical("Something's wrong: {}", ex.what());
    }


    log->info("I'm done here.");
    std::cout << "Game over.\n";
    LogWrap::Shutdown();
    return 0;
}