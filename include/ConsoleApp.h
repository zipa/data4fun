#ifndef _CONSOLE_APP_H_
#define _CONSOLE_APP_H_

#include <iostream>
#include <memory>
#include <ncurses.h>

#include <presentation.h>
#include <spdlogwrap.h>

namespace ConsoleBase
{

class Window;

class Console : public Presentation::IPresentation
{
public:
    void Initialize() override;
    void Shutdown() override;
    int Run() override;
    std::string Description() override;

    Console();
    Console(const Console&) = delete;
    Console(Console&&) = delete;
    Console& operator=(const Console&) = delete;
    Console& operator=(Console&&) = delete;
    ~Console();

    std::shared_ptr<Window> MakeWindow(int x, int y, int w, int h);

    void Test();

protected:
    std::shared_ptr<spdlog::logger> log_;

};

class Window : public Presentation::IPrintable
{
public:
    Window();
    Window(const std::string name);
    Window(const Window& obj);
    Window(Window&& obj);
    ~Window();
    Window& operator=(const Window& obj);
    Window& operator=(Window&& obj);

    std::string Description() override;

private:
    WINDOW* window_;                                                        // ncurses window
    std::string name_;
};

}

#endif // _CONSOLE_APP_H_