#ifndef COMMANDTRANSFORM_H
#define COMMANDTRANSFORM_H

#include "Command/icommand.h"
#include <QPoint>
#include <QMatrix4x4>


class CommandTransform : public ICommand
{
public:
    explicit CommandTransform();

    // ICommand interface
public:
    virtual void Execute() override;

    void SetStartPoint(const QPoint& paramPoint);
    void SetEndPoint(const QPoint& paramPoint);

    QPoint GetStartPoint() const {return startPoint;}
    QPoint GetEndPoint() const {return endPoint;}

    void SetTransformMatrix(const QMatrix4x4& param){transformMatrix = param;}
    void SetViewMatrix(const QMatrix4x4& param){viewMatrix = param;}
    void SetProjectionMatrix(const QMatrix4x4& param){projectionMatrix = param;}

    QMatrix4x4 GetUpdateMatrix() const {return updateMatrix;}
protected:
    QVector3D convertWorldToScreen(const QPoint& point) const;
    void setUpdateMatrix(const QMatrix4x4& param) {updateMatrix = param;}


private:
    QPoint startPoint;
    QPoint endPoint;

    QMatrix4x4 transformMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 projectionMatrix;

    QMatrix4x4 updateMatrix;
};

#endif // COMMANDTRANSFORM_H
