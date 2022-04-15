#include "renderwidget.h"
#include <QLayout>
#include <QDebug>
#include "Render/rendercamera.h"
#include "Widget/renderwindow.h"


RenderWidget::RenderWidget(QWidget *parent)
    : QWidget(parent)
    , renderWindow(nullptr)
{
    renderWindow = new RenderWindow();

    QWidget *container = QWidget::createWindowContainer(renderWindow);

    QVBoxLayout *layout = new QVBoxLayout(this);
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
