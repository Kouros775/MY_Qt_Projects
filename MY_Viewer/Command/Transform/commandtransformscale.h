#ifndef COMMANDTRANSFORMSCALE_H
#define COMMANDTRANSFORMSCALE_H

#include "Command/Transform/commandtransform.h"


class CommandTransformScale : public CommandTransform
{
public:
    explicit CommandTransformScale();


    // ICommand interface
public:
    void Execute() final;
};

#endif // COMMANDTRANSFORMSCALE_H
