#include "rendercamera.h"
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DExtras/QOrbitCameraController>


RenderCamera::RenderCamera(QObject *parent)
    : QObject(parent)
    , camPos(0.0f, 0.0f, 100.0f)
    , camUpVector(0.0f, 1.0f, 0.0f)
    , camLookAt(0.0f, 0.0f, 0.0f)
    , camera(nullptr)
{
}

RenderCamera::~RenderCamera()
{
}

void RenderCamera::Initialize(Qt3DRender::QCamera* paramCamera, Qt3DCore::QEntity* paramRootEntity)
{
    if(nullptr != paramCamera && nullptr != paramRootEntity)
    {
        camera = paramCamera;

        camera->lens()->setPerspectiveProjection(60.0f, 2.0f, 0.1f, 2000.0f);


        // For camera controls
        Qt3DExtras::QOrbitCameraController *camController
                    = new Qt3DExtras::QOrbitCameraController(paramRootEntity);
        camController->setLinearSpeed( 50.0f );
        camController->setLookSpeed( 180.0f );
        camController->setCamera(camera);


        QVector3D m_camPos3D        = QVector3D(0, 0, 40.0);
        QVector3D m_camUpVector3D   = QVector3D(0, 1, 0);
        QVector3D m_camViewCenter3D = QVector3D(0, 0, 0);

        // Camera
        SetPos(m_camPos3D);
        SetUpVector(m_camUpVector3D);
        SetLookAt(m_camViewCenter3D);
    }
    else
    {
        assert(0);
    }
}

void RenderCamera::SetPos(const QVector3D &paramPos)
{
    camPos = paramPos;

    if(camera != nullptr)
    {
        camera->setPosition(camPos);
    }
}

void RenderCamera::SetUpVector(const QVector3D &paramUpVector)
{
    camUpVector = paramUpVector;

    if(camera != nullptr)
    {
        camera->setUpVector(camUpVector);
    }
}

void RenderCamera::SetLookAt(const QVector3D &paramLookAt)
{
    camLookAt = paramLookAt;

    if(camera != nullptr)
    {
        camera->setViewCenter(camLookAt);
    }
}
