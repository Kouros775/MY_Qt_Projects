#include "renderwidget.h"
#include <QLayout>
#include <QDebug>
#include "Render/rendercamera.h"
#include "Widget/renderwindow.h"


RenderWidget::RenderWidget(QWidget *parent)
    : QWidget(parent)
    , renderWindow(nullptr)
{
    renderWindow = make_shared<RenderWindow>();

    QWidget *container = QWidget::createWindowContainer(renderWindow.get());

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(container);

    setLayout(layout);
}

RenderWidget::~RenderWidget()
{
    qDebug() <<__FUNCTION__;
}

QSize RenderWidget::sizeHint() const
{
    return QSize(800,600);
}

void RenderWidget::AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh)
{
    renderWindow->AddModel(paramIndex, paramMesh);
}

void RenderWidget::RemoveModel(const int &paramIndex)
{
    renderWindow->RemoveModel(paramIndex);
}
