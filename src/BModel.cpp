#include "BModel.h"
#include <iomanip>

BModel::BModel(BControl* control)
:_control(control)
{
    _isNew = false;
    _devices.reserve(50);
    _config = std::make_shared<BConfigFile>();
    _startTime = time(nullptr);
}

BModel::~BModel()
{
 // ????
}

void BModel::queueAddDevice(uint8_t type, const std::string& name)
{
    switch(type)
    {
    case 1:
        _devices.push_back(std::make_shared<Switch>(name));
        break;
    case 2:
        _devices.push_back(std::make_shared<Engine>(name));
        break;
    default:
        std::cout << "Wrong option in BModel::queueAddDevice()" << std::endl;
    }
    _control->startReadingThreads(_devices.back());
}

IdDevice BModel::getIdDevice(uint16_t num)const
{
    return _devices[num]->getIdDevice();
}

size_t BModel::getQueueSize()const
{
    return _devices.size();
}

std::shared_ptr<IDevice> BModel::getPointerOnDevice()
{
    return _devices.back();
}

void BModel::printDeviceName()
{
    std::cout << std::setw(4) << "Id: " << std::setw(10) << "   Device name: " << std::endl;
    for(const auto& elem : _devices)
    {
        std::cout << std::setw(20) << std::setfill('-') << "-" << std::endl;
        std::cout  << std::setfill(' ');
        std::cout << " " << std::left << std::setw(4) << elem->getIdDevice() << std::right << std::setw(10) << elem->getNameDevice() << std::endl;
    }
}

void BModel::printDeviceStatistics(uint16_t num)
{
    time_t stop = time(nullptr);
    uint32_t timeNow = stop - _startTime;
    uint32_t seconds = timeNow % 60;
    uint32_t minuts = (timeNow / 60) % 60;
    uint32_t hours = (timeNow / 3600) % 24;
    std::cout << "System is working since: " << hours << ":" << minuts <<":"<< seconds << std::endl;
    _control->showStatistics(num);
}

uint16_t BModel::getVectorSize()
{
    return _devices.size();
}

void BModel::saveConfiguration()
{
    std::vector<std::shared_ptr<IMessage> > configVec;
    for(const auto& element : _devices)
    {
        std::shared_ptr<ConfigMessage> msg(new ConfigMessage);
        msg->setDeviceType(element->getDeviceType());
        msg->setDeviceName(element->getNameDevice());
        configVec.push_back(msg);
    }
    _config->saveConfiguration(configVec);
}

void BModel::loadConfiguration()
{
    auto vec = _config->readConfiguration();
    std::string name;
    for(const auto& element : vec)
    {
        uint32_t type = 0;
        if(element->getDeviceType() == DEVICE_TYPE::SWITCH)
            type = 1;
        if(element->getDeviceType() == DEVICE_TYPE::ENGINE)
            type = 2;
        name = element->getName();
        this->queueAddDevice(type, name);
    }
}
