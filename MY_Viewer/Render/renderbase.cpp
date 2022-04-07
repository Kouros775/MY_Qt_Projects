#include "renderbase.h"
#include <QGLShaderProgram>
#include <QOpenGLFunctions>

#include "Render/camera.h"
#include "Render/rendermodel.h"


#define VERTEX_SHADER       "://vertexshader.vert"
#define FRAGMENT_SHADER     "://fragmentshader.frag"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::RenderBase
///
RenderBase::RenderBase()
    : shaderProgram(nullptr)
    , camera(nullptr)
{
    shaderProgram = std::make_shared<QGLShaderProgram>();
    camera = std::make_shared<Camera>();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::~RenderBase
///
RenderBase::~RenderBase()
{

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::Init
///
void RenderBase::Init()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
     f->glEnable(GL_DEPTH_TEST);
     f->glEnable(GL_CULL_FACE);
     f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

     shaderProgram->addShaderFromSourceFile(QGLShader::Vertex, VERTEX_SHADER);
     shaderProgram->addShaderFromSourceFile(QGLShader::Fragment, FRAGMENT_SHADER);
     shaderProgram->link();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::Paint
///
void RenderBase::Paint()
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

     f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     QMapIterator<int, RenderObjectInfo> mapIter(renderMap);
     while(mapIter.hasNext())
     {
        mapIter.next();

        QMatrix4x4 viewMatrix = camera->GetViewMatrix();
        QMatrix4x4 transformMatrix = mapIter.value().transformMatrix;

        shaderProgram->bind();

        shaderProgram->setUniformValue("mvpMatrix", projectionMatrix * viewMatrix * transformMatrix);
        shaderProgram->setUniformValue("color", QColor(Qt::black));
        shaderProgram->setAttributeArray("vertex",mapIter.value().renderModel->GetVertices().constData());

        shaderProgram->enableAttributeArray("vertex");
        f->glDrawArrays(GL_TRIANGLES, 0, mapIter.value().renderModel->GetVertices().size());
        shaderProgram->disableAttributeArray("vertex");

        shaderProgram->release();
     }
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::Resize
/// \param width
/// \param height
///
void RenderBase::Resize(const int &width, const int &height)
{
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(60.0, (float)width / (float)height, 0.001, 1000);
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, width, height);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::AddModel
/// \param paramModel
/// \param paramIndex
/// \return
///
bool RenderBase::AddModel(const RenderModel &paramModel, const int &paramIndex)
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex))
    {
        std::shared_ptr<RenderModel> renderModel = std::make_shared<RenderModel>();
        renderModel->DeepCopy(paramModel);
        QMatrix4x4 mTransform;
        mTransform.setToIdentity();

        RenderObjectInfo renderObjectInfo;
        renderObjectInfo.renderModel = renderModel;
        renderObjectInfo.transformMatrix = mTransform;

        renderMap[paramIndex] = renderObjectInfo;

        bRes = true;
    }
    else
    {
        bRes = false;
    }

    return bRes;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::SetTransformMatrix
/// \param paramMatrix
/// \param paramIndex
/// \return
///
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::GetTransformMatrix
/// \param paramIndex
/// \param outMatrix
/// \return
///
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::ApplyTransformMatrix
/// \param paramIndex
/// \param paramMatrix
/// \return
///
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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::GetViewMatrix
/// \param outViewMatrix
///
void RenderBase::GetViewMatrix(QMatrix4x4 &outViewMatrix) const
{
    outViewMatrix = camera->GetViewMatrix();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::GetProjectionMatrix
/// \param outProjectionMatrix
///
void RenderBase::GetProjectionMatrix(QMatrix4x4 &outProjectionMatrix) const
{
    outProjectionMatrix = projectionMatrix;
}
