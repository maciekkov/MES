#include "BDevice.h"

#include <sstream>

IdDevice BDevice::numOfInstance = 0;

BDevice::~BDevice()
{
    BThread::stop();
}

BDevice::BDevice(uint8_t type, const std::string& name)
    :_idDevice(numOfInstance++), _log(std::make_shared<LogRW>(toString(_idDevice)))
{
    setDeviceType(type);
    _deviceName = name;
    _message = std::make_shared<DeviceStatus>();
}

IdDevice BDevice::getIdDevice()const
{
    return _idDevice;
}

std::string BDevice::getNameDevice()const
{
    return _deviceName;
}

std::shared_ptr<LogRW> BDevice::getLoger()
{
    return _log;
}

DEVICE_TYPE BDevice::getDeviceType()
{
    return _deviceType;
}

std::string BDevice::toString(IdDevice id)
{
    std::stringstream ss;
    ss << id;
    std::string bufor = ss.str();
    return bufor;
}

void BDevice::setDeviceType(uint8_t type)
{
    switch(type)
    {
    case 1:
        _deviceType = DEVICE_TYPE::SWITCH;
        break;
    case 2:
        _deviceType = DEVICE_TYPE::ENGINE;
        break;
    }
}
