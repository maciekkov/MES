#ifndef ITRANSMITER_H
#define ITRANSMITER_H

#include "IMessage.h"
#include <fstream>
#include <memory>

class ITransmiter
{
public:
    virtual ~ITransmiter() {}

protected:
    virtual void writeMessage(std::shared_ptr<IMessage>) = 0;

};

#endif // ITRANSMITER_H
