#include <console/ConsoleApp.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <ncurses.h>
#include <vector>

namespace ConsoleBase
{

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
    Test();
    std::this_thread::sleep_for(std::chrono::duration<double, std::milli>(3000));
    return 0;
}

const std::vector<std::string> choices
{
    "Choice 1",
    "Choice 2",
    "Choice 3",
    "Choice 4",
    "Exit",
};

void print_menu(WINDOW* win, int highlight)
{
    int x{ 2 }, y{ 2 };

	box(win, 0, 0);
	for(int i = 0; i < choices.size(); ++i)
	{
        if(highlight == i + 1)
		{
            wattron(win, A_REVERSE); 
			mvwprintw(win, y, x, "%s", choices[i].c_str());
			wattroff(win, A_REVERSE);
		}
		else
        {
			mvwprintw(win, y, x, "%s", choices[i].c_str());
        }
		++y;
	}
	wrefresh(win);
}

void report_choice(int mouse_x, int mouse_y, int& p_choice)
{
    int i,j, choice;

	i = 25 + 2;
	j = 10 + 3;
	
	for (choice = 0; choice < choices.size(); ++choice)
    {
		if (mouse_y == j + choice && mouse_x >= i && mouse_x <= i + choices[choice].length())
		{
            if (choice == choices.size() - 1)
            {
				p_choice = -1;		
            }
			else
            {
				p_choice = choice + 1;	
            }
			break;
		}
    }
}

void Console::Test()
{
    WINDOW* menu;
    MEVENT event;

	menu = newwin(10, 30, 10, 25);
    print_menu(menu, 1);
	mousemask(ALL_MOUSE_EVENTS, NULL);
    int choice{ 0 };
    bool running{ true };

    while (running)
	{
        int c = wgetch(menu);
		switch (c)
		{
            case KEY_MOUSE:
                if (getmouse(&event) == OK)
                {
                    if (event.bstate & BUTTON1_PRESSED)
                    {
                        mvprintw(20, 1, "Mouse event OK: %d, %d", event.x, event.y);
                        refresh();
                        report_choice(event.x + 1, event.y + 1, choice);
                        if (choice == -1)
                        {
                            running = false;
                        }
                        mvprintw(22, 1, "Choice made is : %d String Chosen is \"%10s\"", choice, choices[choice - 1].c_str());
                        refresh(); 
                    }
                }
                print_menu(menu, choice);
			    break;
            default:
                mvprintw(20, 1, "Some other event: %08x", c);
                refresh();
                break;
		}
	}
}

}