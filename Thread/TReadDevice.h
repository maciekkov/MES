#ifndef TREADDEVICE_H
#define TREADDEVICE_H

#include "BThread.h"
#include "IDevice.h"
#include "IMessage.h"
#include "LogFileRead.h"
#include <memory>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>

#define NUM_OF_SPEED_OPTION 11

class TReadDevice : public BThread
{
public:
    TReadDevice(std::shared_ptr<IDevice> ptr);
    virtual ~TReadDevice();
    void doActionInThread()override;
    void printStatictic();
    void howLongIsWorking();

private:
    std::vector<std::shared_ptr<IMessage> > _message;
    std::shared_ptr<IDevice> _device;
    std::shared_ptr<LogRW> _log;
    std::string toString(uint32_t num);

};

#endif // TREADDEVICE_H
