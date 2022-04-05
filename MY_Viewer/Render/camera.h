#ifndef CAMERA_H
#define CAMERA_H

#include <QMatrix4x4>


class Camera
{
public:
    explicit Camera();

    QMatrix4x4 GetViewMatrix() const;

    void SetEyePos(const QVector3D& param){eyePos = param;}
    void SetTargetPos(const QVector3D& param){targetPos = param;}

    void SetUpDirection(const QVector3D& param);

private:
    QVector3D eyePos;
    QVector3D upDirection;
    QVector3D targetPos;
};

#endif // CAMERA_H
