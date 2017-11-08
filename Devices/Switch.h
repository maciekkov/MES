#ifndef SWITCH_H
#define SWITCH_H

#include "BDevice.h"
#include "DeviceStatus.h"
#include <cstdlib>
#include <iostream>

#define SWITCH_MACRO 1

class Switch : public BDevice
{
public:
    Switch(const std::string& name);
    virtual ~Switch();
    uint32_t doDeviceJob()override;
    void fillMessage()override;

    void doActionInThread()override;

};

#endif // SWITCH_H
