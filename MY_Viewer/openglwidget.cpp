#include "openglwidget.h"
#include <QDebug>
#include <QMouseEvent>

#include "Render/renderer.h"
#include "Render/rendermodel.h"


OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , renderer(nullptr)
{
    renderer = std::make_shared<Renderer>();

    RenderModel* model = new RenderModel();
    renderer->AddModel(1, *model);
}


OpenGLWidget::~OpenGLWidget()
{
}


QSize OpenGLWidget::sizeHint() const
{
    return QSize(640, 480);
}


void OpenGLWidget::paintGL()
{
    renderer->Paint();
}


void OpenGLWidget::resizeGL(int width, int height)
{
    if (height == 0)
    {
        height = 1;
    }

    renderer->Resize(width, height);
}

void OpenGLWidget::initializeGL()
{
    renderer->Init();
}


// Down
void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    this->prePoint = event->pos();
}


// Up
void OpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}


// Move
void OpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::MouseButton::LeftButton)
    {
        renderer->Translate(this->prePoint, event->pos(), 1);
    }
    else if(event->buttons() & Qt::MouseButton::RightButton)
    {
        renderer->Rotate(this->prePoint, event->pos(), 1);
    }

    this->prePoint = event->pos();

    update();
}
