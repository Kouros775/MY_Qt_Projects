#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H


#include <QWidget>
#include <Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QCameraLens>
#include <Qt3DCore/QTransform>
#include <Qt3DCore/QAspectEngine>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/QPhongMaterial>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DExtras/QExtrudedTextMesh>


class RenderCamera;


class RenderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = nullptr);
    ~RenderWidget() override;

    void createRootEntry();


private:
    Qt3DExtras::Qt3DWindow *m_view;

    Qt3DCore::QEntity *m_rootEntity;

    // Camera
    RenderCamera* camera;
    Qt3DCore::QEntity *m_textEntity;


    // QWidget interface
public:
    QSize sizeHint() const override;

};

#endif // RENDERWIDGET_H
