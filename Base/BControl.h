#ifndef BCONTROL_H
#define BCONTROL_H

#include <vector>
#include "TReadDevice.h"
#include "../Global/GlobalVariables.h"
#include "BModel.h"
#include <map>
#include "IControl.h"

class BControl : public IControl
{
public:
    BControl();
    virtual ~BControl();

    void startReadingThreads(std::shared_ptr<IDevice> dev)override;
    void showStatistics(uint16_t num )override;

private:
    size_t sizeOfVectorDevices;
    std::vector<std::shared_ptr<TReadDevice> > _readProces;
    std::map<IdDevice,std::vector<std::shared_ptr<IMessage> > > _statistics;

};

#endif // BCONTROL_H
