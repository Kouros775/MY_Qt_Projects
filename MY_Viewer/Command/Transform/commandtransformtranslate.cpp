#include "commandtransformtranslate.h"

CommandTransformTranslate::CommandTransformTranslate()
{

}

void CommandTransformTranslate::Execute()
{
    translate();
}

void CommandTransformTranslate::translate()
{
    QPoint startPoint = GetStartPoint();
    QPoint endPoint= GetEndPoint();

    QVector3D worldStart = convertWorldToScreen(startPoint);
    QVector3D worldEnd = convertWorldToScreen(endPoint);

    QVector3D moveAmount = worldEnd - worldStart;
    moveAmount.setY(moveAmount.y() * -1.0f);

    QMatrix4x4 updateMatrix;
    updateMatrix.translate(moveAmount);
    setUpdateMatrix(updateMatrix);
}
