#include "BControl.h"

BControl::BControl()
{
    //ctor
}

BControl::~BControl()
{
    //dtor
}

void BControl::startReadingThreads(std::shared_ptr<IDevice> dev)
{
   _readProces.push_back(std::make_shared<TReadDevice>(dev));
    std::cout << " New Device added" << std::endl;
}

void BControl::showStatistics(uint16_t num )
{
     //_readProces[num]->printStatictic();
     _readProces[num]->howLongIsWorking();

}
