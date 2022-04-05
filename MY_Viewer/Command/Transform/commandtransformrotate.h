#ifndef COMMANDTRANSFORMROTATE_H
#define COMMANDTRANSFORMROTATE_H

#include "Command/Transform/commandtransform.h"


class CommandTransformRotate : public CommandTransform
{
public:
    CommandTransformRotate();

    // ICommand interface
public:
    void Execute() final;
};

#endif // COMMANDTRANSFORMROTATE_H
