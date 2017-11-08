#ifndef IVIEW_H
#define IVIEW_H

#include "BThread.h"
#include "../Global/GlobalVariables.h"
#include "IModel.h"
class IView
{
public:
    IView() {}
    virtual ~IView() {}
    virtual void start() = 0;
    virtual uint32_t userInteraction(uint16_t range) = 0;
    virtual void menuOption(uint32_t) = 0;
    virtual void menu() = 0;

};

#endif // IVIEW_H
