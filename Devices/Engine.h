#ifndef ENGINE_H
#define ENGINE_H

#include "BDevice.h"
#define ENGINE_MACRO 2
#include <memory>


class Engine : public BDevice
{
public:
    Engine(const std::string& name);
    virtual ~Engine();
    uint32_t doDeviceJob()override;
    void fillMessage()override;

protected:
    void doActionInThread()override;


};

#endif // ENGINE_H
