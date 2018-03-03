#include <iostream>
#include <memory>
#include <spdlogwrap.h>

// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <glm/glm.hpp>



// using namespace glm;
// GLFWwindow* window;

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
    LogWrap::Initialize("log");
    auto log = LogWrap::GetLog("MAIN");

    Test t;
    t.DoSomething();

    log->info("I'm done here.");
    std::cout << "Game over.\n";
    LogWrap::Shutdown();
    return 0;
}