#ifndef LOGFILEWRITE_H
#define LOGFILEWRITE_H

#include "ITransmiter.h"

class LogFileWrite :public ITransmiter
{
public:
    LogFileWrite();
    virtual ~LogFileWrite();

};

#endif // LOGFILEWRITE_H
