#ifndef IRECIVER_H
#define IRECIVER_H

#include <memory>
#include <IMessage.h>

class IReciver
{
public:
    virtual ~IReciver() {}

protected:
    virtual std::shared_ptr<IMessage> readMessage() = 0;

};

#endif // IRECIVER_H
