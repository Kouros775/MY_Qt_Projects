#include "openglwidget.h"
#include <QDebug>

#include "Render/camera.h"


OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
    , camera(nullptr)
{
    camera = std::make_shared<Camera>();
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
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

     f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     shaderProgram.bind();
     shaderProgram.setUniformValue("mvpMatrix", projectionMatrix * viewMatrix * transformMatrix);
     shaderProgram.setUniformValue("color", QColor(Qt::black));
     shaderProgram.setAttributeArray("vertex",vertices.constData());
     shaderProgram.enableAttributeArray("vertex");
     f->glDrawArrays(GL_TRIANGLES, 0, vertices.size());
     shaderProgram.disableAttributeArray("vertex");
     shaderProgram.release();
}


void OpenGLWidget::resizeGL(int width, int height)
{
    if (height == 0)
    {
        height = 1;
    }

     projectionMatrix.setToIdentity();
     //projectionMatrix.ortho((float)-width / 2, (float)width / 2, (float)-height / 2, (float)height / 2, 0.001, 1000);
     projectionMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);
     QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
     f->glViewport(0, 0, width, height);
}

void OpenGLWidget::initializeGL()
{
    viewMatrix = camera->GetViewMatrix();

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
     f->glEnable(GL_DEPTH_TEST);
     f->glEnable(GL_CULL_FACE);
     f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

     shaderProgram.addShaderFromSourceFile(QGLShader::Vertex,
    "://vertexshader.vert");
     shaderProgram.addShaderFromSourceFile(QGLShader::Fragment,
    "://fragmentshader.frag");
     shaderProgram.link();


     //vertices << QVector3D(1, 0, -2) << QVector3D(0, 1, -2)
     //         << QVector3D(-1, 0, -2);
     vertices << QVector3D(1, -1, -2) << QVector3D(1, 1, -2) << QVector3D(-1, 1, -2) << QVector3D(-1, -1, -2);
}


// Down
void OpenGLWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug(__FUNCTION__);

    prePoint.setX(event->x());
    prePoint.setY(event->y());
}


// Up
void OpenGLWidget::mouseReleaseEvent(QMouseEvent *event)
{
    qDebug(__FUNCTION__);
}


// Move
void OpenGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug(__FUNCTION__);
}
