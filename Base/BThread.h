#ifndef BTHREAD_H
#define BTHREAD_H

#include "IThread.h"

class BThread : public IThread
{
public:

    virtual ~BThread();
    void start()override;
    void stop()override;

protected:
    std::thread _thread;
    std::atomic_bool _stopThread;

};

#endif // BTHREAD_H
