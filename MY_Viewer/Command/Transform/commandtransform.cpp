#include "commandtransform.h"

CommandTransform::CommandTransform()
    : startPoint(0,0)
    , endPoint(0,0)
{
    updateMatrix.setToIdentity();
}

void CommandTransform::Execute()
{

}

void CommandTransform::SetStartPoint(const QPoint &paramPoint)
{
    startPoint = paramPoint;
}

void CommandTransform::SetEndPoint(const QPoint &paramPoint)
{
    endPoint = paramPoint;
}


QVector3D CommandTransform::convertWorldToScreen(const QPoint& point) const
{
    QVector3D world;


    QMatrix4x4 invP = projectionMatrix.inverted();
    QMatrix4x4 invV = viewMatrix.inverted();
    QMatrix4x4 invW = transformMatrix.inverted();


    QMatrix4x4 WVP = projectionMatrix * viewMatrix * transformMatrix;
    QMatrix4x4 inverseWVP = WVP.inverted();

    QVector3D screenPoint;
    screenPoint.setX(point.x());
    screenPoint.setY(point.y());

    world = invW * invV * invP * screenPoint;


    return world;
}
