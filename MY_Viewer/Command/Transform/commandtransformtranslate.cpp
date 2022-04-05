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
    QPoint endPoint= GetStartPoint();


    QPoint gap = endPoint - startPoint;

    QVector3D moveAmount = convertWorldToScreen(gap);


    QMatrix4x4 updateMatrix;
    updateMatrix.translate(moveAmount);

    SetUpdateMatrix(updateMatrix);
}
