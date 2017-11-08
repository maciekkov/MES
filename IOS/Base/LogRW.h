#ifndef LOGRW_H
#define LOGRW_H

#include "LogFileRead.h"
#include "LogFileWrite.h"
#include <mutex>
#include <condition_variable>
#include <fstream>
#include <DeviceStatus.h>
#include <sstream>

class LogRW : public LogFileRead, public LogFileWrite
{
public:
    LogRW(const std::string& fileName);
    virtual ~LogRW();
    virtual std::shared_ptr<IMessage> readMessage();
    virtual void writeMessage(std::shared_ptr<IMessage> msg);

    std::fstream _of;
    std::fstream _if;
    std::string _fileName;
    std::mutex  _mu;
    std::condition_variable _con;

private:
        uint32_t stringToInt(const std::string& text);

};

#endif // LOGRW_H
