#ifndef IRECIVER_H
#define IRECIVER_H

#include <fstream>
#include "GlobalVariables.h"
#include "IMessage.h"

class IReciver
{
public:
    virtual ~IReciver() {}

protected:
    virtual std::shared_ptr<IMessage> readMessage() = 0;
};

#endif // IRECIVER_H
