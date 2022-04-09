#include "commandtransformrotate.h"

CommandTransformRotate::CommandTransformRotate()
{

}

void CommandTransformRotate::Execute()
{
    rotate();
}

void CommandTransformRotate::rotate()
{
    QPoint startPoint = GetStartPoint();
    QPoint endPoint= GetEndPoint();

    QVector3D worldStart = convertWorldToScreen(startPoint);
    QVector3D worldEnd = convertWorldToScreen(endPoint);

    QVector3D zeroPoint{0.0f, 0.0f, 0.0f};
    QVector3D lineA = worldStart - zeroPoint;
    lineA.normalize();
    QVector3D lineB = worldEnd - zeroPoint;
    lineB.normalize();

    QVector3D axis = QVector3D::crossProduct(lineA, lineB);
    axis.normalize();

    QMatrix4x4 updateMatrix;
    updateMatrix.rotate(5.0f, axis);
    setUpdateMatrix(updateMatrix);
}
