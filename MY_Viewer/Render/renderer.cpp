#include "renderer.h"
#include <QGLShaderProgram>
#include <QOpenGLFunctions>


#include "Render/camera.h"
#include "Render/rendermodel.h"
#include "Render/renderbase.h"


Renderer::Renderer()
    : shaderProgram(nullptr)
    , camera(nullptr)
    , renderBase(nullptr)
{
    renderBase = std::make_shared<RenderBase>();


    shaderProgram = std::make_shared<QGLShaderProgram>();
    camera = std::make_shared<Camera>();

    transformMatrix.setToIdentity();
}

Renderer::~Renderer()
{

}


void Renderer::Init()
{
    renderBase->Init();

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
}


void Renderer::Paint()
{
    renderBase->Paint();

    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

     f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     shaderProgram->bind();
     shaderProgram->setUniformValue("mvpMatrix", projectionMatrix * viewMatrix * transformMatrix);
     shaderProgram->setUniformValue("color", QColor(Qt::black));
     shaderProgram->setAttributeArray("vertex",renderModel->GetVertices().constData());
     shaderProgram->enableAttributeArray("vertex");
     f->glDrawArrays(GL_TRIANGLES, 0, renderModel->GetVertices().size());
     shaderProgram->disableAttributeArray("vertex");
     shaderProgram->release();
}


void Renderer::Resize(const int &width, const int &height)
{
    renderBase->Resize(width, height);

    projectionMatrix.setToIdentity();
    //projectionMatrix.ortho((float)-width / 2, (float)width / 2, (float)-height / 2, (float)height / 2, 0.001, 1000);
    projectionMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, width, height);
}


bool Renderer::SetTransformMatrix(const QMatrix4x4& paramMatrix, const int &paramIndex)
{
    renderBase->SetTransformMatrix(paramMatrix, paramIndex);

    bool bRes = false;
    Q_UNUSED(paramIndex);

    transformMatrix = paramMatrix;

    return bRes;
}

void Renderer::GetTransformMatrix(QMatrix4x4 &outMatrix)
{
    renderBase->GetTransformMatrix(outMatrix);

    outMatrix = transformMatrix;
}


bool Renderer::ApplyTransformMatrix(const QMatrix4x4 &paramMatrix, const int &paramIndex)
{
    renderBase->ApplyTransformMatrix(paramMatrix, paramIndex);

    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex) == false)
    {
        transformMatrix = paramMatrix * transformMatrix;
    }

    return bRes;
}


bool Renderer::IsEmptyModelIndex(const int &paramIndex)
{
    renderBase->IsEmptyModelIndex(paramIndex);

    bool bRes = false;

    return bRes;
}

void Renderer::GetViewMatrix(QMatrix4x4 &outViewMatrix) const
{
    renderBase->GetViewMatrix(outViewMatrix);
}


void Renderer::GetProjectionMatrix(QMatrix4x4 &outProjectionMatrix) const
{
    renderBase->GetProjectionMatrix(outProjectionMatrix);
}


bool Renderer::Translate(const QPoint &startPoint, const QPoint &endPoint, const int &index)
{

}

bool Renderer::Rotate(const QPoint &startPoint, const QPoint &endPoint, const int &index)
{

}

bool Renderer::Scale(const QPoint &startPoint, const QPoint &endPoint, const int &index)
{

}


bool Renderer::AddModel(const RenderModel& paramModel, const int& paramIndex)
{
    renderBase->AddModel(paramModel, paramIndex);

    bool bRes = false;
    Q_UNUSED(paramIndex);
    renderModel = &paramModel;

    return bRes;
}
