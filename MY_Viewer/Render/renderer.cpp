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
{
    renderBase = std::make_shared<RenderBase>();

    commandScale = std::make_shared<CommandTransformScale>();
    commandRotate = std::make_shared<CommandTransformRotate>();
    commandTranslate = std::make_shared<CommandTransformTranslate>();
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
    renderBase->Paint();
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Resize
/// \param width
/// \param height
///
void Renderer::Resize(const int &width, const int &height)
{
    renderBase->Resize(width, height);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::AddModel
/// \param paramIndex
/// \param paramModel
/// \return
///
bool Renderer::AddModel(const int& paramIndex, const RenderModel& paramModel)
{
    return renderBase->AddModel(paramModel, paramIndex);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::SetTransformMatrix
/// \param paramIndex
/// \param paramMatrix
/// \return
///
bool Renderer::SetTransformMatrix(const int& paramIndex, const QMatrix4x4& paramMatrix)
{
    return renderBase->SetTransformMatrix(paramMatrix, paramIndex);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::GetTransformMatrix
/// \param paramIndex
/// \param outMatrix
/// \return
///
bool Renderer::GetTransformMatrix(const int& paramIndex, QMatrix4x4& outMatrix) const
{
    return renderBase->GetTransformMatrix(paramIndex, outMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::ApplyTransformMatrix
/// \param paramIndex
/// \param paramMatrix
/// \return
///
bool Renderer::ApplyTransformMatrix(const int& paramIndex, const QMatrix4x4 &paramMatrix)
{
    return renderBase->ApplyTransformMatrix(paramIndex, paramMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::IsEmptyModelIndex
/// \param paramIndex
/// \return
///
bool Renderer::IsEmptyModelIndex(const int &paramIndex) const
{
    return renderBase->IsEmptyModelIndex(paramIndex);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::GetViewMatrix
/// \param outViewMatrix
///
void Renderer::GetViewMatrix(QMatrix4x4 &outViewMatrix) const
{
    renderBase->GetViewMatrix(outViewMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::GetProjectionMatrix
/// \param outProjectionMatrix
///
void Renderer::GetProjectionMatrix(QMatrix4x4 &outProjectionMatrix) const
{
    renderBase->GetProjectionMatrix(outProjectionMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Translate - Model을 이동하는 함수.
/// \param startPoint - Point 시작점
/// \param endPoint - Point 끝점
/// \param index - 적용하고자 하는 Model index
/// \return - 성공했는지 여부
///
bool Renderer::Translate(const QPoint &startPoint, const QPoint &endPoint, const int &index)
{
    bool bRes = false;

    if(!IsEmptyModelIndex(index))
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
bool Renderer::Rotate(const QPoint &startPoint, const QPoint &endPoint, const int &index)
{
    bool bRes = false;

    if(!IsEmptyModelIndex(index))
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
bool Renderer::Scale(const QPoint &startPoint, const QPoint &endPoint, const int &index)
{
    bool bRes = false;

    if(!IsEmptyModelIndex(index))
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



