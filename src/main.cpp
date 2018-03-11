#include <iostream>
#include <memory>
#include <exception>
#include <spdlogwrap.h>

#include <GLhelper.h>
#include <ConsoleApp.h>
#include <data/common.h>

using namespace std;

void StartGL();
void StartConsole();
void TestCommon();

int main(int, char**)
{
    LogWrap::Initialize("log", spdlog::level::trace);
    auto log = LogWrap::GetLog("MAIN");
    log->info("Data4Fun started.");

    // begin test code
    StartConsole();
    // end test code

    log->info("I'm done here.");
    std::cout << "Game over.\n";
    LogWrap::Shutdown();
    return 0;
}

void TestCommon()
{
    auto log = LogWrap::GetLog(__func__);
    DataModel::Point<int> P1;
    DataModel::Point<double> P2;
    log->info("P1({}, {}, {})", P1.x(), P1.y(), P1.z());
    log->info("P2({}, {}, {})", P2.x(), P2.y(), P2.z());
    P1.x(100);
    P1.y(120);
    P1.z(140);
    P2.x(1.23);
    P2.y(2.3);;
    P2.z(3.45);
    log->info("P1({}, {}, {})", P1.x(), P1.y(), P1.z());
    log->info("P2({}, {}, {})", P2.x(), P2.y(), P2.z());
}

void StartGL()
{
    auto log = LogWrap::GetLog(__func__);
    try
    {
        GLhelper glh;
        glh.Run();
    }
    catch(std::runtime_error& ex)
    {
        log->critical("Something's wrong: {}", ex.what());
    }
}

void StartConsole()
{
    shared_ptr<Presentation::IPresentation> con = make_shared<ConsoleBase::Console>();
    con->Run();
}