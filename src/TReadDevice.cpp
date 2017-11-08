#include "TReadDevice.h"

TReadDevice::TReadDevice(std::shared_ptr<IDevice> ptr)
    :_device(ptr)
{
    std::string name = toString(_device->getIdDevice());
    _log = _device->getLoger();
    BThread::start();
}

TReadDevice::~TReadDevice()
{
    BThread::stop();
}

void TReadDevice::doActionInThread()
{
    _message.push_back(_log->readMessage());
}

void TReadDevice::printStatictic()
{
    std::cout << std::setw(3) << " ID " << std::setw(10) << " Value " << std::setw(10) << " Name " << std::setw(15) << " TimeStamp " << std::setw(3) << " Device_type " << std::endl;
    std::cout << std::setfill('-') << std::setw(50) << "-" << std::endl;
    std::cout << std::setfill((' '));
    uint32_t type;
    for(const auto& elem : _message)
    {
        if(elem->getDeviceType() == DEVICE_TYPE::SWITCH)
            type = 1;
        if(elem->getDeviceType() == DEVICE_TYPE::ENGINE)
            type = 2;
        std::cout << " " << std::left << std::setw(10) << elem->getIdDevice();
        std::cout << std::left << std::setw(7)  << elem->getValue();
        std::cout << std::left << std::setw(10) << elem->getName();
        std::cout << std::left << std::setw(15) << elem->getTimeStamp();
        std::cout << std::left << std::setw(3)  << type << std::endl;
    }
}

std::string TReadDevice::toString(uint32_t num)
{
    std::stringstream  ss;
    ss << num;
    std::string bufor = ss.str();
    return bufor;
}

void TReadDevice::howLongIsWorking()
{
    uint32_t suma = 0;
    for(const auto& element : _message)
    {
        if(element->getValue() != 0)
            suma ++;
    }
    uint32_t seconds = suma % 60;
    uint32_t minuts  = (suma / 60) % 60;
    uint32_t hours   = (suma / 3600) % 24;

    std::cout << "Device Working: " << hours << ":" << minuts << ":" << seconds << std::endl;

    int tab[NUM_OF_SPEED_OPTION] {0};
    if(_device->getDeviceType() == DEVICE_TYPE::ENGINE)
    {
        for(const auto& element : _message)
        {
            tab[element->getValue()] ++;
        }

        std::cout << "How long device works on specifiks speed : " << std::endl;

        for(uint16_t i = 0; i < NUM_OF_SPEED_OPTION; ++i )
        {
            std::cout << "SPEED_" << i << std::left << " : " <<tab[i] << std::endl;
        }
    }
}
