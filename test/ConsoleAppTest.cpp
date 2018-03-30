#include <gmock/gmock.h>

#include <iostream>
#include <memory>
#include <spdlogwrap.h>

#include <console/ConsoleApp.h>

using namespace testing;
using namespace std;

namespace
{

class ConsoleAppTestFixture : public Test
{
public:
    ConsoleAppTestFixture()
    {
        const char* LOGSRC {__func__};
        log_ = LogWrap::GetLog("ConsoleAppTestFixture");
        Log()->info("{}|TEST STARTED", LOGSRC);
        console_ = std::make_shared<ConsoleBase::Console>();
    }

    ~ConsoleAppTestFixture()
    {
        const char* LOGSRC {__func__};
        Log()->info("{}|TEST FINISHED", LOGSRC);
    }

    std::shared_ptr<spdlog::logger> Log() { return log_; }
    std::shared_ptr<Presentation::IPresentation> Console() { return console_; }

private:
    std::shared_ptr<spdlog::logger> log_;
    std::shared_ptr<Presentation::IPresentation> console_;
};

TEST_F(ConsoleAppTestFixture, LoggerAndConsoleCreated)
{
    EXPECT_NE(Log(), nullptr);
    EXPECT_NE(Console(), nullptr);
}

}