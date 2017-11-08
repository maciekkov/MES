#ifndef BCONFIGFILE_H
#define BCONFIGFILE_H

#include "LogRW.h"
#include "IConfigFile.h"
#include <vector>
#include "ConfigMessage.h"
#include "../Global/GlobalVariables.h"

class BConfigFile :public IConfigFile, public LogRW
{
public:
    BConfigFile();
    virtual ~BConfigFile();
    virtual void saveConfiguration(std::vector<std::shared_ptr<IMessage> >  msg)override;
    std::vector<std::shared_ptr<IMessage> >readConfiguration()override;
    void writeMessageConfig(std::shared_ptr<IMessage> msg);
    void resetConfigFile();

private:
    static constexpr const char* _fileName= "ConfigFile.txt";
};

#endif // BCONFIGFILE_H
