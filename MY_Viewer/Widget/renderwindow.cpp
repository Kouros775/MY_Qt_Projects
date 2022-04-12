#include "renderwindow.h"
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QForwardRenderer>

#include "Render/renderer.h"
#include <Qt3DRender/QMesh>

RenderWindow::RenderWindow(QScreen *screen)
    : Qt3DExtras::Qt3DWindow(screen)
{
    defaultFrameGraph()->setClearColor(QColor(77, 77, 77));

    Initialize();
}


RenderWindow::~RenderWindow()
{
}


void RenderWindow::Initialize()
{
    renderer = std::make_shared<Renderer>();
    Qt3DCore::QEntity* rootEntity = renderer->Initialize(this->camera());
    setRootEntity(rootEntity);
}


void RenderWindow::AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh)
{
    renderer->AddModel(paramIndex, paramMesh);
}


void RenderWindow::mousePressEvent(QMouseEvent *event)
{
}

void RenderWindow::mouseReleaseEvent(QMouseEvent *event)
{
}

void RenderWindow::mouseMoveEvent(QMouseEvent *event)
{
}
