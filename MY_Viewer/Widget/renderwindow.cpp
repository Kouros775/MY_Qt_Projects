#include "renderwindow.h"
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QForwardRenderer>
#include <QMouseEvent>
#include <Qt3DRender/QMesh>

#include "Render/renderer.h"



RenderWindow::RenderWindow(QScreen *screen)
    : Qt3DExtras::Qt3DWindow(screen)
{
    defaultFrameGraph()->setClearColor(QColor(200, 200, 200));
    Initialize();
}


RenderWindow::~RenderWindow()
{
    qDebug() <<__FUNCTION__;
}


void RenderWindow::Initialize()
{
    renderer = new Renderer(this);
    Qt3DCore::QEntity* rootEntity = renderer->Initialize(this->camera());

    setRootEntity(rootEntity);
}


void RenderWindow::AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh)
{
    renderer->AddModel(paramIndex, paramMesh);
}

void RenderWindow::RemoveModel(const int &paramIndex)
{
    renderer->RemoveModel(paramIndex);
}

void RenderWindow::SelectModel(const int &paramIndex)
{
    renderer->SelectModel(paramIndex);
}


void RenderWindow::mousePressEvent(QMouseEvent *event)
{
    qDebug() <<__FUNCTION__;
}


void RenderWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}

void RenderWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() <<__FUNCTION__;
}
