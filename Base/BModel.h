#ifndef BMODEL_H
#define BMODEL_H

#include <vector>
#include "IDevice.h"
#include "IModel.h"
#include "Switch.h"
#include "Engine.h"
#include "BControl.h"
#include "BConfigFile.h"
#include "ConfigMessage.h"
#include "../Global/GlobalVariables.h"

class BControl;
class BModel : public IModel
{
public:
    BModel(BControl* control);
    virtual ~BModel();
    virtual void queueAddDevice(uint8_t type, const std::string& name) override;
    virtual IdDevice getIdDevice(uint16_t num)const override;
    virtual size_t getQueueSize()const override;
    virtual std::shared_ptr<IDevice> getPointerOnDevice();
    virtual void printDeviceName();
    virtual void printDeviceStatistics(uint16_t num);
    uint16_t getVectorSize();
    virtual void saveConfiguration()override;
    virtual void loadConfiguration()override;

protected:
    std::vector<std::shared_ptr<IDevice> > _devices;
    std::shared_ptr<BConfigFile> _config;
    std::vector<std::shared_ptr<IMessage> > _configVec;
    BControl* _control;
    bool _isNew;
    time_t _startTime;

};

#endif // BMODEL_H
