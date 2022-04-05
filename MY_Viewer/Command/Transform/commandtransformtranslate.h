#ifndef COMMANDTRANSFORMTRANSLATE_H
#define COMMANDTRANSFORMTRANSLATE_H

#include "Command/Transform/commandtransform.h"


class CommandTransformTranslate : public CommandTransform
{
public:
    explicit CommandTransformTranslate();



    // ICommand interface
public:
    void Execute() final;
};

#endif // COMMANDTRANSFORMTRANSLATE_H
