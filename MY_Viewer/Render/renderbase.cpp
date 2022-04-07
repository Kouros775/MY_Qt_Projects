#include "renderbase.h"
#include "Render/rendermodel.h"
#include <QGLShaderProgram>
#include <QOpenGLFunctions>

#include "Render/camera.h"


RenderBase::RenderBase()
    : shaderProgram(nullptr)
    , camera(nullptr)
{
    shaderProgram = std::make_shared<QGLShaderProgram>();
    camera = std::make_shared<Camera>();
}

RenderBase::~RenderBase()
{

}

void RenderBase::Init()
{
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

void RenderBase::Paint()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

     f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     //shaderProgram->bind();
     //shaderProgram->setUniformValue("mvpMatrix", projectionMatrix * viewMatrix * transformMatrix);
     //shaderProgram->setUniformValue("color", QColor(Qt::black));
     //shaderProgram->setAttributeArray("vertex",renderModel->GetVertices().constData());
     //shaderProgram->enableAttributeArray("vertex");
     //f->glDrawArrays(GL_TRIANGLES, 0, renderModel->GetVertices().size());
     //shaderProgram->disableAttributeArray("vertex");
     //shaderProgram->release();


     QMapIterator<int, RenderObjectInfo> mapIter(renderMap);
     while(mapIter.hasNext())
     {
        mapIter.next();

        shaderProgram->bind();
        shaderProgram->setUniformValue("mvpMatrix", projectionMatrix * viewMatrix * mapIter.value().transformMatrix);
        shaderProgram->setUniformValue("color", QColor(Qt::black));
        shaderProgram->setAttributeArray("vertex",mapIter.value().renderModel->GetVertices().constData());
        shaderProgram->enableAttributeArray("vertex");
        f->glDrawArrays(GL_TRIANGLES, 0, mapIter.value().renderModel->GetVertices().size());
        shaderProgram->disableAttributeArray("vertex");
        shaderProgram->release();
     }
}

void RenderBase::Resize(const int &width, const int &height)
{
    projectionMatrix.setToIdentity();
    //projectionMatrix.ortho((float)-width / 2, (float)width / 2, (float)-height / 2, (float)height / 2, 0.001, 1000);
    projectionMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, width, height);
}

bool RenderBase::AddModel(const RenderModel &paramModel, const int &paramIndex)
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex))
    {
        RenderModel* renderModel = new RenderModel();
        renderModel->DeepCopy(paramModel);
        QMatrix4x4 mTransform;
        mTransform.setToIdentity();

        renderMap[paramIndex] = RenderObjectInfo(mTransform, renderModel);

        bRes = true;
    }
    else
    {
        bRes = false;
    }

    return bRes;
}

bool RenderBase::SetTransformMatrix(const QMatrix4x4 &paramMatrix, const int &paramIndex)
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex))
    {
        renderMap[paramIndex].transformMatrix = paramMatrix;
        bRes = true;
    }
    else
    {
        assert(0);
    }

    return bRes;
}


bool RenderBase::GetTransformMatrix(const int& paramIndex, QMatrix4x4& outMatrix) const
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex))
    {
        outMatrix = renderMap[paramIndex].transformMatrix;
        bRes = true;
    }
    else
    {
        assert(0);
    }

    return bRes;
}


bool RenderBase::ApplyTransformMatrix(const int& paramIndex, const QMatrix4x4& paramMatrix)
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex))
    {
        renderMap[paramIndex].transformMatrix = paramMatrix * renderMap[paramIndex].transformMatrix;
        bRes = true;
    }
    else
    {
        assert(0);
    }

    return bRes;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::IsEmptyModelIndex - 해당 index가 비었는지 확인하는 함수.
/// \param paramIndex - modelIndex
/// \return - true 비었다, false 사용중이다.
///
bool RenderBase::IsEmptyModelIndex(const int &paramIndex) const
{
    bool bRes = false;

    auto findIndex = renderMap.find(paramIndex);

    if(findIndex != renderMap.end())
    {
        bRes = false;
    }
    else
    {
        bRes = true;
    }

    return bRes;
}


void RenderBase::GetViewMatrix(QMatrix4x4 &outViewMatrix) const
{
    outViewMatrix = camera->GetViewMatrix();
}


void RenderBase::GetProjectionMatrix(QMatrix4x4 &outProjectionMatrix) const
{
    outProjectionMatrix = projectionMatrix;
}
