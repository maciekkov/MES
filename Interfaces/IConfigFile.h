#ifndef ICONFIGFILE_H
#define ICONFIGFILE_H

#include "LogRW.h"
#include <vector>
#include <memory>

class IConfigFile
{
public:
    virtual ~IConfigFile() {}
    virtual void saveConfiguration(std::vector<std::shared_ptr<IMessage> >) = 0;
    virtual std::vector<std::shared_ptr<IMessage> > readConfiguration() = 0;

};

#endif // ICONFIGFILE_H
