#include "renderwidget.h"
#include <QLayout>

#include "Render/rendercamera.h"
#include "Widget/renderwindow.h"


RenderWidget::RenderWidget(QWidget *parent)
    : QWidget(parent)
    , renderWindow(nullptr)
{
    renderWindow = new RenderWindow();

    QWidget *container = QWidget::createWindowContainer(renderWindow);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(container);

    setLayout(layout);
}

RenderWidget::~RenderWidget()
{

}



QSize RenderWidget::sizeHint() const
{
    return QSize(1024,800);
}

void RenderWidget::AddModel(Qt3DRender::QMesh *paramMesh)
{
    renderWindow->AddModel(paramMesh);
}
