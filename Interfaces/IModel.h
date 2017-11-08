#ifndef IMODEL_H
#define IMODEL_H

#include "../Global/GlobalVariables.h"
#include "LogFileWrite.h"
#include <memory>

class IModel
{
public:
    virtual ~IModel() {}
    virtual void queueAddDevice(uint8_t, const std::string&) = 0;
    virtual IdDevice getIdDevice(uint16_t num)const = 0;
    virtual size_t getQueueSize()const = 0;
    virtual void saveConfiguration() = 0;
    virtual void loadConfiguration() = 0;

};

#endif // IMODEL_H
