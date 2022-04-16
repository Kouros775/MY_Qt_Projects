#include "rendercamera.h"
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DExtras/QOrbitCameraController>


RenderCamera::RenderCamera(QObject *parent)
    : QObject(parent)
    , camPos(0.0f, 0.0f, 200.0f)
    , camUpVector(0.0f, 1.0f, 0.0f)
    , camLookAt(0.0f, 0.0f, 0.0f)
    , camera(nullptr)
{
}

RenderCamera::~RenderCamera()
{
    qDebug() <<__FUNCTION__;
}

void RenderCamera::Initialize(Qt3DRender::QCamera* paramCamera, Qt3DCore::QEntity* paramRootEntity)
{
    if(nullptr != paramCamera && nullptr != paramRootEntity)
    {
        camera = paramCamera;
        //camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
        //camera->lens()->setOrthographicProjection()
        camera->lens()->setPerspectiveProjection(45.0f, 2.0f, 0.1f, 1000.0f);


        //// For camera controls
        //Qt3DExtras::QOrbitCameraController *camController
        //            = new Qt3DExtras::QOrbitCameraController(paramRootEntity);
        //camController->setLinearSpeed( 50.0f );
        //camController->setLookSpeed( 180.0f );
        //camController->setCamera(camera);



        // Camera
        SetPos(camPos);
        SetUpVector(camUpVector);
        SetLookAt(camLookAt);
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
