#ifndef IMESSAGE_H
#define IMESSAGE_H

#include "../Global/GlobalVariables.h"
#include <string>

class IMessage
{
public:

    virtual ~IMessage() {}
    virtual void setValue(value) = 0;
    virtual void setDeviceName(const std::string&) = 0;
    virtual void setTimeStamp(time_t) = 0;
    virtual void setIdDevice(IdDevice id) = 0;
    virtual void setDeviceType(DEVICE_TYPE type) = 0;

    virtual value getValue()const = 0;
    virtual std::string getName()const = 0;
    virtual uint64_t getTimeStamp()const = 0;
    virtual IdDevice getIdDevice()const = 0;
    virtual DEVICE_TYPE getDeviceType()const = 0;
    virtual void resetMessage() = 0;
};

#endif // IMESSAGE_H
