#include "openglwidget.h"
#include <QDebug>


OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    transformMatrix.scale()
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
     shaderProgram.setUniformValue("color", QColor(Qt::white));
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
     projectionMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);
     QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
     f->glViewport(0, 0, width, height);
}

void OpenGLWidget::initializeGL()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
     f->glEnable(GL_DEPTH_TEST);
     f->glEnable(GL_CULL_FACE);
     f->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

     shaderProgram.addShaderFromSourceFile(QGLShader::Vertex,
    "://vertexshader.vert");
     shaderProgram.addShaderFromSourceFile(QGLShader::Fragment,
    "://fragmentshader.frag");
     shaderProgram.link();


     vertices << QVector3D(1, 0, -2) << QVector3D(0, 1, -2)
     << QVector3D(-1, 0, -2);
}
