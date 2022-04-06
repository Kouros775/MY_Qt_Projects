#include "renderer.h"
#include <QGLShaderProgram>
#include <QOpenGLFunctions>


#include "Render/camera.h"


Renderer::Renderer()
    : shaderProgram(nullptr)
    , camera(nullptr)
{
    shaderProgram = std::make_shared<QGLShaderProgram>();
    camera = std::make_shared<Camera>();

    transformMatrix.setToIdentity();
}

void Renderer::Init()
{
    viewMatrix = camera->GetViewMatrix();

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
     f->glEnable(GL_DEPTH_TEST);
     f->glEnable(GL_CULL_FACE);
     f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

     shaderProgram->addShaderFromSourceFile(QGLShader::Vertex,
    "://vertexshader.vert");
     shaderProgram->addShaderFromSourceFile(QGLShader::Fragment,
    "://fragmentshader.frag");
     shaderProgram->link();




     /////////////////
     // >> 앞
     vertices << QVector3D(1, -1, -1) << QVector3D(1, 1, -1) << QVector3D(-1, 1, -1);
     vertices << QVector3D(-1, 1, -1) << QVector3D(-1, -1, -1) << QVector3D(1, -1, -1);

     // 뒤
     vertices << QVector3D(1, -1, 1) << QVector3D(1, 1, 1) << QVector3D(-1, 1, 1);
     vertices << QVector3D(-1, 1, 1) << QVector3D(-1, -1, 1) << QVector3D(1, -1, 1);

     // 오른쪽
     vertices << QVector3D(1, -1, -1) << QVector3D(1, 1, -1) << QVector3D(1, 1, 1);
     vertices << QVector3D(1, 1, 1) << QVector3D(1, -1, -1) << QVector3D(1, -1, -1);

     // 왼쪽
     vertices << QVector3D(-1, -1, -1) << QVector3D(-1, 1, -1) << QVector3D(-1, 1, 1);
     vertices << QVector3D(-1, 1, 1) << QVector3D(-1, -1, -1) << QVector3D(-1, -1, -1);

     // 위
     vertices << QVector3D(1, 1, 1) << QVector3D(1, 1, -1) << QVector3D(-1, 1, -1);
     vertices << QVector3D(-1, 1, -1) << QVector3D(-1, 1, 1) << QVector3D(1, 1, 1);

     // 아래
     vertices << QVector3D(1, -1, 1) << QVector3D(1, -1, -1) << QVector3D(-1, -1, -1);
     vertices << QVector3D(-1, -1, -1) << QVector3D(-1, -1, 1) << QVector3D(1, -1, 1);
}

void Renderer::Paint()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

     f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     shaderProgram->bind();
     shaderProgram->setUniformValue("mvpMatrix", projectionMatrix * viewMatrix * transformMatrix);
     shaderProgram->setUniformValue("color", QColor(Qt::black));
     shaderProgram->setAttributeArray("vertex",vertices.constData());
     shaderProgram->enableAttributeArray("vertex");
     f->glDrawArrays(GL_TRIANGLES, 0, vertices.size());
     shaderProgram->disableAttributeArray("vertex");
     shaderProgram->release();
}

void Renderer::Resize(const int &width, const int &height)
{
    projectionMatrix.setToIdentity();
    //projectionMatrix.ortho((float)-width / 2, (float)width / 2, (float)-height / 2, (float)height / 2, 0.001, 1000);
    projectionMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, width, height);
}
