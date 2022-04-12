#include "renderwindow.h"
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QForwardRenderer>

#include "Render/renderer.h"
#include "Render/rendermodel.h"


RenderWindow::RenderWindow(QScreen *screen)
    : Qt3DExtras::Qt3DWindow(screen)
{
    defaultFrameGraph()->setClearColor(QColor(77, 77, 77));

    Initialize();

    RenderModel* temp = new RenderModel();
    temp->MakeTorus(1.0f, 5.0f, 10,20);

    renderer->AddModel(1, *temp);
}


RenderWindow::~RenderWindow()
{

}

void RenderWindow::Initialize()
{
    renderer = std::make_shared<Renderer>();
    std::shared_ptr<Qt3DCore::QEntity> rootEntity = renderer->Initialize(this->camera());
    setRootEntity(rootEntity.get());
}


void RenderWindow::mousePressEvent(QMouseEvent *event)
{
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
