#include "BThread.h"


BThread::~BThread()
{
    if(_thread.joinable())_thread.join();
}

void BThread::start()
{
    _stopThread = false;
    _thread = std::thread([this](){while(!_stopThread)doActionInThread();});
}

void BThread::stop()
{
    _stopThread = true;
}
