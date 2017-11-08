#include "BConfigFile.h"

BConfigFile::BConfigFile()
    :LogRW(_fileName)
{
    //ctor
}

BConfigFile::~BConfigFile()
{
    //dtor
}

void BConfigFile::saveConfiguration(std::vector<std::shared_ptr<IMessage> >  msg)
{
    resetConfigFile();
    for(const auto& element : msg)
    {
        writeMessageConfig(element);
    }

    std::cout << "configuration file created successfully" << std::endl;
}


void BConfigFile::writeMessageConfig(std::shared_ptr<IMessage> msg)
{
    _of.open(LogRW::_fileName.c_str(),std::fstream::app);
    if(_of.good())
    {
        uint32_t type = 0;
        if(msg->getDeviceType() == DEVICE_TYPE::SWITCH)
            type = 1;
        if(msg->getDeviceType() == DEVICE_TYPE::ENGINE)
            type = 2;

        _of << type << " " << msg->getName() << std::endl;
        _of.close();
    }
    else
        std::cout << "Something goes wrong could not open config file." << std::endl;

}

std::vector<std::shared_ptr<IMessage> >BConfigFile::readConfiguration()
{
    std::vector<std::shared_ptr<IMessage> > vec;
    _if.open(LogRW::_fileName.c_str(), std::fstream::in);
    if(_if.good())
    {
        std::string bufor = "";

        while(getline(_if,bufor))
        {
            std::shared_ptr<IMessage> msg(new ConfigMessage);
            std::string ID(bufor,0,1);
            std::string name(bufor,2,bufor.size());

            if(ID == "1")
                msg->setDeviceType(DEVICE_TYPE::SWITCH);
            if(ID == "2")
                msg->setDeviceType(DEVICE_TYPE::ENGINE);

            msg->setDeviceName(name);
            vec.push_back(msg);
        }
        _if.close();
        return vec;
    }
    else
        _if.close();
        std::cout << "Something goes wrong could not open config file." << std::endl;
}

void BConfigFile::resetConfigFile()
{
    _of.open(LogRW::_fileName.c_str(), std::fstream::out);
    if(_of.good())
    {
        _of.close();
    }
    else
        std::cout << "Something goes wrong could not open config file." << std::endl;
}
