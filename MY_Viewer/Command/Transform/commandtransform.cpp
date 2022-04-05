#include "commandtransform.h"

CommandTransform::CommandTransform()
    : startPoint(0,0)
    , endPoint(0,0)
{

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
