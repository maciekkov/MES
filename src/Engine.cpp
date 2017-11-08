#include "Engine.h"
#include <ctime>
#include <cstdlib>

Engine::Engine(const std::string& name)
:BDevice(ENGINE_MACRO,name)
{
    BThread::start();
}

Engine::~Engine()
{

}

uint32_t Engine::doDeviceJob()
{
    return rand() % 11;
}

void Engine::fillMessage()
{
    _message->setValue(doDeviceJob());
    _message->setDeviceName(_deviceName);
    _message->setTimeStamp(time(nullptr));
}

void Engine::doActionInThread()
{
    fillMessage();
    _log->writeMessage(_message);
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
