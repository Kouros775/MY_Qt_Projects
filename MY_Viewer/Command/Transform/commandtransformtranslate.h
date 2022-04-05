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

private:
    void translate();

};

#endif // COMMANDTRANSFORMTRANSLATE_H
