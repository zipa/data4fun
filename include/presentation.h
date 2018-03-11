#ifndef _PRESENTATION_H_
#define _PRESENTATION_H_

#include <iostream>

class IPrintable
{
public:
    virtual std::string Description() = 0;
};

class IPresentation : public IPrintable
{
public:
    virtual void Initialize() = 0;
    virtual void Shutdown() = 0;
    virtual int Run() = 0;
};

#endif // _PRESENTATION_H_