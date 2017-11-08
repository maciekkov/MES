#include "BMessage.h"

BMessage::BMessage()
{
    //ctor
}

BMessage::~BMessage()
{
    //dtor
}

void BMessage::setValue(value val)
{
    _value = val;
}

void BMessage::setDeviceName(const std::string& name)
{
    _deviceName = name;
}

void BMessage::setTimeStamp(time_t time)
{
    _time = time;
}

void BMessage::setIdDevice(IdDevice id)
{
    _idDevice = id;
}

value BMessage::getValue()const
{
    return _value;
}

std::string BMessage::getName()const
{
    return _deviceName;
}

uint64_t BMessage::getTimeStamp()const
{
    return (uint64_t)_time;
}

IdDevice BMessage::getIdDevice()const
{
    return _idDevice;
}
void BMessage::setDeviceType(DEVICE_TYPE type)
{
    _deviceType = type;
}

DEVICE_TYPE BMessage::getDeviceType()const
{
    return _deviceType;
}

void BMessage::resetMessage()
{
    _value = 0;
    _deviceName = "";
    _time = 0;
    _idDevice = 0;
}
