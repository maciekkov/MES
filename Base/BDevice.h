#ifndef BDEVICE_H
#define BDEVICE_H

#include "IDevice.h"
#include "BThread.h"
#include "IMessage.h"
#include <string>
#include <DeviceStatus.h>

class BDevice : public IDevice, public BThread
{
public:
    virtual ~BDevice();
    virtual IdDevice getIdDevice()const override;
    virtual std::string getNameDevice()const override;
    virtual std::shared_ptr<LogRW> getLoger()override;
    virtual DEVICE_TYPE getDeviceType()override;

protected:
    BDevice(uint8_t type, const std::string& name);
    static IdDevice numOfInstance;
    IdDevice _idDevice;
    std::string _deviceName;
    DEVICE_TYPE _deviceType;
    std::shared_ptr<LogRW> _log;
    std::shared_ptr<IMessage> _message;

private:
    std::string toString(IdDevice id);
    virtual void setDeviceType(uint8_t type)override;

};

#endif // BDEVICE_H
