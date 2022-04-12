#ifndef RENDERCAMERA_H
#define RENDERCAMERA_H

#include <QObject>
#include <QVector3D>


namespace Qt3DRender
{
    class QCamera;
}

namespace Qt3DCore
{
    class QEntity;
}


class RenderCamera : public QObject
{
    Q_OBJECT
public:
    explicit RenderCamera(QObject *parent = nullptr);
    ~RenderCamera() override;

    void Initialize(Qt3DRender::QCamera* paramCamera, Qt3DCore::QEntity* paramRootEntity);

    QVector3D GetPos() const {return camPos;}
    QVector3D GetUpVector() const {return camUpVector;}
    QVector3D GetLookAt() const {return camLookAt;}

    void SetPos(const QVector3D& paramPos);
    void SetUpVector(const QVector3D& paramUpVector);
    void SetLookAt(const QVector3D& paramLookAt);

private:
    QVector3D camPos;
    QVector3D camUpVector;
    QVector3D camLookAt;

    Qt3DRender::QCamera* camera;
};

#endif // RENDERCAMERA_H
