#include "commandtransformtranslate.h"


CommandTransformTranslate::CommandTransformTranslate(QObject *parent)
    : ICommand(parent)
{
}


CommandTransformTranslate::~CommandTransformTranslate()
{
}


void CommandTransformTranslate::Execute()
{
    translate();
}


void CommandTransformTranslate::translate()
{
    QVector3D moveAmount = endWorldPosition - startWorldPosition;
    moveAmount.setY(moveAmount.y() * -1.0f);

    QMatrix4x4 translateMatrix;
    translateMatrix.translate(moveAmount);

    updateMatrix = translateMatrix;
}
