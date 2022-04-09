#include "renderer.h"
#include "Command/Transform/commandtransformscale.h"
#include "Command/Transform/commandtransformrotate.h"
#include "Command/Transform/commandtransformtranslate.h"
#include "Render/camera.h"
#include "Render/rendermodel.h"
#include "Render/renderbase.h"


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Renderer
///
Renderer::Renderer()
    : renderBase(nullptr)
    , commandTranslate(nullptr)
    , commandRotate(nullptr)
    , commandScale(nullptr)
    , camera(nullptr)
{
    renderBase = std::make_shared<RenderBase>();

    commandScale = std::make_shared<CommandTransformScale>();
    commandRotate = std::make_shared<CommandTransformRotate>();
    commandTranslate = std::make_shared<CommandTransformTranslate>();

    camera = std::make_shared<Camera>();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::~Renderer
///
Renderer::~Renderer()
{

}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Init
///
void Renderer::Init()
{
    renderBase->Init();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Paint
///
void Renderer::Paint()
{
    renderBase->Paint(camera->GetViewMatrix(), projectionMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Resize
/// \param width
/// \param height
///
void Renderer::Resize(const int &width, const int &height)
{
    projectionMatrix.setToIdentity();
    projectionMatrix.perspective(60.0, (float)width / (float)height, 0.001f, 1000.0f);

    renderBase->Resize(width, height);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::AddModel
/// \param paramIndex
/// \param paramModel
/// \return
///
bool Renderer::AddModel(const uint& paramIndex, const RenderModel& paramModel)
{
    return renderBase->AddModel(paramIndex, paramModel);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::SetTransformMatrix
/// \param paramIndex
/// \param paramMatrix
/// \return
///
bool Renderer::SetTransformMatrix(const uint& paramIndex, const QMatrix4x4& paramMatrix)
{
    return renderBase->SetTransformMatrix(paramIndex, paramMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::GetTransformMatrix
/// \param paramIndex
/// \param outMatrix
/// \return
///
bool Renderer::GetTransformMatrix(const uint& paramIndex, QMatrix4x4& outMatrix) const
{
    return renderBase->GetTransformMatrix(paramIndex, outMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::ApplyTransformMatrix
/// \param paramIndex
/// \param paramMatrix
/// \return
///
bool Renderer::ApplyTransformMatrix(const uint& paramIndex, const QMatrix4x4 &paramMatrix)
{
    return renderBase->ApplyTransformMatrix(paramIndex, paramMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::IsEmptyModelIndex
/// \param paramIndex
/// \return
///
bool Renderer::IsEmptyModelIndex(const uint &paramIndex) const
{
    return renderBase->IsEmptyModelIndex(paramIndex);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Translate - Model을 이동하는 함수.
/// \param startPoint - Point 시작점
/// \param endPoint - Point 끝점
/// \param index - 적용하고자 하는 Model index
/// \return - 성공했는지 여부
///
bool Renderer::Translate(const QPoint &startPoint, const QPoint &endPoint, const uint &index)
{
    bool bRes = false;

    if(IsEmptyModelIndex(index) == false)
    {
        commandTranslate->SetStartPoint(startPoint);
        commandTranslate->SetEndPoint(endPoint);

        QMatrix4x4 viewMatrix;
        GetViewMatrix(viewMatrix);
        QMatrix4x4 projectionMatrix;
        GetProjectionMatrix(projectionMatrix);

        commandTranslate->SetViewMatrix(viewMatrix);
        commandTranslate->SetProjectionMatrix(projectionMatrix);

        commandTranslate->Execute();
        QMatrix4x4 updateMatrix = commandTranslate->GetUpdateMatrix();

        bRes = ApplyTransformMatrix(index, updateMatrix);
    }
    else
    {
        assert(0);
    }

    return bRes;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Rotate
/// \param startPoint
/// \param endPoint
/// \param index
/// \return
///
bool Renderer::Rotate(const QPoint &startPoint, const QPoint &endPoint, const uint &index)
{
    bool bRes = false;

    if(IsEmptyModelIndex(index) == false)
    {
        commandRotate->SetStartPoint(startPoint);
        commandRotate->SetEndPoint(endPoint);

        QMatrix4x4 viewMatrix;
        GetViewMatrix(viewMatrix);
        QMatrix4x4 projectionMatrix;
        GetProjectionMatrix(projectionMatrix);

        commandRotate->SetViewMatrix(viewMatrix);
        commandRotate->SetProjectionMatrix(projectionMatrix);

        commandRotate->Execute();
        QMatrix4x4 updateMatrix = commandRotate->GetUpdateMatrix();

        bRes = ApplyTransformMatrix(index, updateMatrix);
    }
    else
    {
        assert(0);
    }

    return bRes;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Scale
/// \param startPoint
/// \param endPoint
/// \param index
/// \return
///
bool Renderer::Scale(const QPoint &startPoint, const QPoint &endPoint, const uint &index)
{
    bool bRes = false;

    if(IsEmptyModelIndex(index) == false)
    {
        commandScale->SetStartPoint(startPoint);
        commandScale->SetEndPoint(endPoint);

        QMatrix4x4 viewMatrix;
        GetViewMatrix(viewMatrix);
        QMatrix4x4 projectionMatrix;
        GetProjectionMatrix(projectionMatrix);

        commandScale->SetViewMatrix(viewMatrix);
        commandScale->SetProjectionMatrix(projectionMatrix);

        commandScale->Execute();
        QMatrix4x4 updateMatrix = commandScale->GetUpdateMatrix();

        bRes = ApplyTransformMatrix(index, updateMatrix);
    }
    else
    {
        assert(0);
    }

    return bRes;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::GetViewMatrix
/// \param outViewMatrix
///
void Renderer::GetViewMatrix(QMatrix4x4 &outViewMatrix) const
{
    outViewMatrix = camera->GetViewMatrix();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief RenderBase::GetProjectionMatrix
/// \param outProjectionMatrix
///
void Renderer::GetProjectionMatrix(QMatrix4x4 &outProjectionMatrix) const
{
    outProjectionMatrix = projectionMatrix;
}

