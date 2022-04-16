#include "renderwindow.h"
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QForwardRenderer>
#include <QMouseEvent>
#include <Qt3DRender/QMesh>

#include "Document/document.h"
#include "Render/renderer.h"



RenderWindow::RenderWindow(QScreen *screen)
    : Qt3DExtras::Qt3DWindow(screen)
{
    defaultFrameGraph()->setClearColor(QColor(200, 200, 200));
    Initialize();
}


RenderWindow::~RenderWindow()
{
}


void RenderWindow::Initialize()
{
    renderer = new Renderer(this);
    Qt3DCore::QEntity* rootEntity = renderer->Initialize(this->camera());

    setRootEntity(rootEntity);
}


void RenderWindow::AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh)
{
    renderer->AddModel(paramIndex, paramMesh->meshName(), paramMesh);
}

void RenderWindow::RemoveModel(const int &paramIndex)
{
    renderer->RemoveModel(paramIndex);
}

void RenderWindow::SelectModel(const int &paramIndex)
{
    renderer->SelectModel(paramIndex);
}

void RenderWindow::EditModelColor(const int &paramIndex, const QColor &paramColor)
{
    renderer->SetColor(paramIndex, paramColor);
}
void RenderWindow::wheelEvent(QWheelEvent *evt)
{
    //MeshModel* meshModel = renderer->GetModel(1);
    //
    //if(nullptr != meshModel)
    //{
    //    //renderer->Scale(meshModel, evt->delta());
    //}
}
