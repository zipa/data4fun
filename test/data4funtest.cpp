#include <gmock/gmock.h>

#include <iostream>
#include <memory>
#include <spdlogwrap.h>

using namespace testing;
using namespace std;

namespace
{

class TestFixture : public Test
{
public:
    TestFixture()
    {
        LogWrap::Initialize("log", spdlog::level::trace);
        testLog_ = LogWrap::GetLog("TestFixture");
    }

    ~TestFixture()
    {
        LogWrap::Shutdown();
    }

    std::shared_ptr<spdlog::logger> Log() { return testLog_; }
private:
    std::shared_ptr<spdlog::logger> testLog_;
};

TEST_F(TestFixture, LoggerCreated)
{
    EXPECT_NE(Log(), nullptr);
}

}