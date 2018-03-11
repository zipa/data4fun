#ifndef _CONSOLE_APP_H_
#define _CONSOLE_APP_H_

#include <iostream>
#include <memory>

#include <presentation.h>
#include <spdlogwrap.h>


class Console : public IPresentation
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

protected:
    std::shared_ptr<spdlog::logger> log_;
};

#endif // _CONSOLE_APP_H_