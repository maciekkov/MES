#include "Switch.h"

Switch::Switch(const std::string& name)
:BDevice(SWITCH_MACRO, name)
{
    BThread::start();
}

Switch::~Switch()
{

}

uint32_t Switch::doDeviceJob()
{
    return rand() % 2;
}

void Switch::fillMessage()
{
    BDevice::_message->setValue(doDeviceJob());
    BDevice::_message->setDeviceName(_deviceName);
    BDevice::_message->setTimeStamp(time(nullptr));
    BDevice::_message->setIdDevice(_idDevice);
}

void Switch::doActionInThread()
{
    fillMessage();
    _log->writeMessage(_message);
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
