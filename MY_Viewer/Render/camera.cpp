#include "camera.h"

Camera::Camera()
    : eyePos(0.0f, 0.0f, 5.0f)
    , upDirection(0.0f, 1.0f, 0.0f)
    , targetPos(0.0f, 0.0f, 0.0f)
{
}

QMatrix4x4 Camera::GetViewMatrix() const
{
    QMatrix4x4 viewMatrix;

    QVector3D viewDirection = targetPos - eyePos;
    viewDirection.normalize();

    QVector3D rightDirection;
    rightDirection = QVector3D::crossProduct(viewDirection, upDirection);

    QVector3D upDirection = QVector3D::crossProduct(rightDirection, viewDirection);

    viewMatrix.lookAt(eyePos, targetPos, upDirection);

    return viewMatrix;
}


void Camera::SetUpDirection(const QVector3D &param)
{
    upDirection = param;
    upDirection.normalize();
}
