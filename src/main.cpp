#include <iostream>
#include <memory>
#include <exception>
#include <spdlogwrap.h>

//#include <gl/GLhelper.h>
//#include <console/ConsoleApp.h>
#include <data/common.h>

using namespace std;

//void StartGL();
//void StartConsole();
void TestCommon();

int main(int, char**)
{
    LogWrap::Initialize("log", spdlog::level::trace);
    auto log = LogWrap::GetLog("MAIN");
    log->info("Data4Fun started.");

    // begin test code
    TestCommon();
    // end test code

    log->info("I'm done here.");
    std::cout << "Game over.\n";
    LogWrap::Shutdown();
    return 0;
}

void TestCommon()
{
    auto log = LogWrap::GetLog(__func__);


}

// void StartGL()
// {
//     auto log = LogWrap::GetLog(__func__);
//     try
//     {
//         GLhelper glh;
//         glh.Run();
//     }
//     catch(std::runtime_error& ex)
//     {
//         log->critical("Something's wrong: {}", ex.what());
//     }
// }

// void StartConsole()
// {
//     shared_ptr<Presentation::IPresentation> con = make_shared<ConsoleBase::Console>();
//     con->Run();
// }