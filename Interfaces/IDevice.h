#ifndef IDEVICE_H
#define IDEVICE_H

#include "../Global/GlobalVariables.h"
#include "LogRW.h"
#include <memory>
#include <string>

class IDevice
{
public:
    virtual ~IDevice() {}
    virtual IdDevice getIdDevice()const = 0;
    virtual std::string getNameDevice()const = 0;
    virtual uint32_t doDeviceJob() = 0;
    virtual void fillMessage() = 0;
    virtual std::shared_ptr<LogRW> getLoger() = 0;
    virtual DEVICE_TYPE getDeviceType() = 0;

protected:
    virtual void setDeviceType(uint8_t) = 0;

};

#endif // IDEVICE_H
