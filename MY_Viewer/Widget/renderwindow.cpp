#include "renderwindow.h"
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QTorusMesh>

#include "Render/rendercamera.h"


RenderWindow::RenderWindow(QScreen *screen)
    : Qt3DExtras::Qt3DWindow(screen)
{
    defaultFrameGraph()->setClearColor(QColor(77, 77, 77));

    m_rootEntity = new Qt3DCore::QEntity;
    setRootEntity(m_rootEntity);

    // Camera
    renderCamera = new RenderCamera();
    renderCamera->Initialize(this->camera(), m_rootEntity);

    createRootEntry();
}

RenderWindow::~RenderWindow()
{

}


void RenderWindow::createRootEntry()
{
    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial();

    // Torus
    torusEntity = new Qt3DCore::QEntity(m_rootEntity);
    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
    torusMesh->setRadius(5);
    torusMesh->setMinorRadius(1);
    torusMesh->setRings(100);
    torusMesh->setSlices(20);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
    torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusTransform);
    torusEntity->addComponent(material);
}


void RenderWindow::mousePressEvent(QMouseEvent *event)
{
    if(torusEntity != nullptr)
    {
        delete torusEntity;
        torusEntity = nullptr;
    }
    qDebug(__FUNCTION__);
}

void RenderWindow::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug(__FUNCTION__);
}

void RenderWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug(__FUNCTION__);
}
