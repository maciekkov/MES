#ifndef ITHREAD_H
#define ITHREAD_H

#include <thread>
#include <atomic>

class IThread
{
public:
    virtual ~IThread(){}
    virtual void start() = 0;
    virtual void stop() = 0;

protected:
    virtual void doActionInThread() = 0;

};

#endif // ITHREAD_H
