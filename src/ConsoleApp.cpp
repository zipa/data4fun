#include <ConsoleApp.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ncurses.h>

Console::Console()
{
    const char* LOGSRC {__func__};
    log_ = LogWrap::GetLog("Console");
    log_->debug("{}|Initializing {}...", LOGSRC, Description());
    Initialize();
}

Console::~Console()
{
    Shutdown();
}

void Console::Initialize()
{
    const char* LOGSRC {__func__};
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);
    start_color();
    log_->debug("{}|Initialized {}.", LOGSRC, Description());
}

void Console::Shutdown()
{
    const char* LOGSRC {__func__};
    endwin();
    log_->debug("{}|Terminated {}.", LOGSRC, Description());
}

std::string Console::Description()
{
    return "Console";
}

int Console::Run()
{
    init_pair(1,2,0);
    wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
    wmove(stdscr, 0, 1);
    waddstr(stdscr, "[=] Console ");
    wmove(stdscr, 1, 1);
    waddstr(stdscr, "Test line.");
    wrefresh(stdscr);
    std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(3000));
    return 0;
}