#ifndef COMMANDTRANSFORMROTATE_H
#define COMMANDTRANSFORMROTATE_H

#include "Command/Transform/commandtransform.h"


class CommandTransformRotate : public CommandTransform
{
public:
    explicit CommandTransformRotate();

    // ICommand interface
public:
    void Execute() final;

private:
    void rotate();
};

#endif // COMMANDTRANSFORMROTATE_H
