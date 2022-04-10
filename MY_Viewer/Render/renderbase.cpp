#include "renderbase.h"
#include <QGLShaderProgram>
#include <QOpenGLFunctions>

#include "Render/rendermodel.h"


#define VERTEX_SHADER       "://vertexshader.vert"
#define FRAGMENT_SHADER     "://fragmentshader.frag"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::RenderBase
///
RenderBase::RenderBase()
    : shaderProgram(nullptr)
{
    shaderProgram = std::make_shared<QGLShaderProgram>();
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
void RenderBase::Paint(const QMatrix4x4& viewMatrix, const QMatrix4x4& projMatrix) const
{
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();

     f->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     QMapIterator<uint, RenderObjectInfo> mapIter(renderMap);
     while(mapIter.hasNext())
     {
        mapIter.next();

        QMatrix4x4 transformMatrix = mapIter.value().transformMatrix;
        QVector<QVector3D> vertex = mapIter.value().renderModel->GetVertices();

        shaderProgram->bind();

        shaderProgram->setUniformValue("viewMatrix", viewMatrix);
        shaderProgram->setUniformValue("projectionMatrix", projMatrix);
        shaderProgram->setUniformValue("transformMatrix", transformMatrix);

        shaderProgram->setUniformValue("color", QColor(Qt::black));
        shaderProgram->setAttributeArray("vertex",vertex.constData());

        shaderProgram->enableAttributeArray("vertex");
        f->glDrawArrays(GL_TRIANGLES, 0, vertex.size());
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
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glViewport(0, 0, width, height);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::AddModel
/// \param paramModel
/// \param paramIndex
/// \return
///
bool RenderBase::AddModel(const uint& paramIndex, const RenderModel& paramModel)
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex) == true)
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
bool RenderBase::SetTransformMatrix(const uint& paramIndex, const QMatrix4x4& paramMatrix)
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex) == false)
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
bool RenderBase::GetTransformMatrix(const uint& paramIndex, QMatrix4x4& outMatrix) const
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex) == false)
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
bool RenderBase::ApplyTransformMatrix(const uint& paramIndex, const QMatrix4x4& paramMatrix)
{
    bool bRes = false;

    if(IsEmptyModelIndex(paramIndex) == false)
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
bool RenderBase::IsEmptyModelIndex(const uint &paramIndex) const
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
/// \brief RenderBase::RayPicking
/// \param point
/// \param outPickedIndex
/// \return
///
bool RenderBase::RayPicking(const QPoint &point, uint &outPickedIndex) const
{
    bool bRes = false;

    QMapIterator<uint, RenderObjectInfo> mapIter(renderMap);
    while(mapIter.hasNext())
    {
        mapIter.next();

        QMatrix4x4 transformMatrix = mapIter.value().transformMatrix;
        QVector<QVector3D> vertex = mapIter.value().renderModel->GetVertices();
    }


    return bRes;
}
