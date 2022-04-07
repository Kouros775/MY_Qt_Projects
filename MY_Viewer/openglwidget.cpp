#include "openglwidget.h"
#include <QDebug>
#include <QMouseEvent>

#include "Command/Transform/commandtransformtranslate.h"
#include "Render/renderer.h"
#include "Render/rendermodel.h"


OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , commandTranslate(nullptr)
    , renderer(nullptr)
{
    commandTranslate = std::make_shared<CommandTransformTranslate>();


    renderer = std::make_shared<Renderer>();
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

    int tempIndex = 0;
    RenderModel* model = new RenderModel();
    renderer->AddModel(*model, tempIndex);
}


// Down
void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    this->prePoint = event->pos();
}


// Up
void OpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
}


// Move
void OpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    translate(this->prePoint, event->pos());

    this->prePoint = event->pos();

    update();
}

void OpenGLWidget::translate(const QPoint& startPoint, const QPoint& endPoint)
{
    commandTranslate->SetStartPoint(startPoint);
    commandTranslate->SetEndPoint(endPoint);

    QMatrix4x4 viewMatrix;
    renderer->GetViewMatrix(viewMatrix);
    QMatrix4x4 projectionMatrix;
    renderer->GetProjectionMatrix(projectionMatrix);

    commandTranslate->SetViewMatrix(viewMatrix);
    commandTranslate->SetProjectionMatrix(projectionMatrix);

    commandTranslate->Execute();
    QMatrix4x4 updateMatrix = commandTranslate->GetUpdateMatrix();
    renderer->ApplyTransformMatrix(updateMatrix, 1);
}
