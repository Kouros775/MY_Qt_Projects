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

    QPoint gap = endPoint - startPoint;

    QVector3D moveAmount = convertWorldToScreen(gap);

    moveAmount.setZ(0.0f);
    moveAmount.setY(moveAmount.y() * -1.0f);


    QMatrix4x4 updateMatrix;
    updateMatrix.translate(moveAmount);
    //updateMatrix.translate(QVector3D(0.1f, 0.0f, 0.0f));
    setUpdateMatrix(updateMatrix);
}
