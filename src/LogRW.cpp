#include "LogRW.h"

LogRW::LogRW(const std::string& fileName)
{
    std::string name = fileName + ".txt";
    _fileName = name;
}

LogRW::~LogRW()
{

}

std::shared_ptr<IMessage> LogRW::readMessage()
{
    std::unique_lock<std::mutex>locker(LogRW::_mu);
    _con.wait(locker);
    std::shared_ptr<IMessage> msg = std::make_shared<DeviceStatus>();
    _if.open(_fileName.c_str(), std::ifstream::in);
    std::string bufor;
    uint8_t counter = 0;
    if(_if.good())
    {
        while(getline(_if, bufor, ' ' ))
        {
            if(counter == 0)
                msg->setIdDevice(stringToInt(bufor));
            else if(counter == 1)
                msg->setValue(stringToInt(bufor));
            else if(counter == 2)
                msg->setDeviceName(bufor);
            else if(counter == 3)
                msg->setTimeStamp(stringToInt(bufor));
            bufor.clear();
            counter++;
        }
        _if.close();
        locker.unlock();
        return msg;
    }
    else std::cout << "Something goes wrong with file " << _fileName << std::endl;
    return nullptr;
}

void LogRW::writeMessage(std::shared_ptr<IMessage> msg)
{
    std::unique_lock<std::mutex> locker(LogRW::_mu);
    _of.open(_fileName.c_str(),std::ios_base::out);
    if(_of.good())
    {
        _of << msg->getIdDevice() << " " << msg->getValue() << " " << msg->getName() << " " << msg->getTimeStamp() << std::endl;
        _of.close();
        locker.unlock();
        _con.notify_one();
    }
    else std::cout << "somethin goes wrong" << std::endl;
}

uint32_t LogRW::stringToInt(const std::string& text)
{
    std::stringstream ss(text);
    uint32_t num;
    ss >> num;
    return num;
}
