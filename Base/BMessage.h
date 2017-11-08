#ifndef BMESSAGE_H
#define BMESSAGE_H

#include "IMessage.h"

class BMessage : public IMessage
{
public:
    BMessage();
    virtual ~BMessage();
    virtual void setValue(value val)override;
    virtual void setDeviceName(const std::string& name)override;
    virtual void setTimeStamp(time_t time)override;
    virtual void setIdDevice(IdDevice id)override;
    virtual void setDeviceType(DEVICE_TYPE type)override;

    virtual value getValue()const override;
    virtual std::string getName()const override;
    virtual uint64_t getTimeStamp()const override;
    virtual IdDevice getIdDevice()const override;
    virtual DEVICE_TYPE getDeviceType()const override;
    virtual void resetMessage()override;

private:
    value _value;
    std::string _deviceName;
    time_t _time;
    IdDevice _idDevice;
    DEVICE_TYPE _deviceType;


};

#endif // BMESSAGE_H
