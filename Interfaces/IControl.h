#ifndef ICONTROL_H
#define ICONTROL_H

#include <string>
#include <memory>
#include <IDevice.h>

class IControl
{
public:
    virtual ~IControl() {}
    virtual void startReadingThreads(std::shared_ptr<IDevice>) = 0;
    virtual void showStatistics(uint16_t num ) = 0;

};

#endif // ICONTROL_H
