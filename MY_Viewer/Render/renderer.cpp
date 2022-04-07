#include "renderer.h"


#include "Command/Transform/commandtransformtranslate.h"
#include "Render/camera.h"
#include "Render/rendermodel.h"
#include "Render/renderbase.h"


Renderer::Renderer()
    : renderBase(nullptr)
    , commandTranslate(nullptr)
{
    renderBase = std::make_shared<RenderBase>();
    transformMatrix.setToIdentity();
}

Renderer::~Renderer()
{

}


void Renderer::Init()
{
    renderBase->Init();
}


void Renderer::Paint()
{
    renderBase->Paint();
}


void Renderer::Resize(const int &width, const int &height)
{
    renderBase->Resize(width, height);
}


bool Renderer::SetTransformMatrix(const QMatrix4x4& paramMatrix, const int &paramIndex)
{
    return renderBase->SetTransformMatrix(paramMatrix, paramIndex);
}


bool Renderer::GetTransformMatrix(const int& paramIndex, QMatrix4x4& outMatrix)
{
    return renderBase->GetTransformMatrix(paramIndex, outMatrix);
}


bool Renderer::ApplyTransformMatrix(const int& paramIndex, const QMatrix4x4 &paramMatrix)
{
    return renderBase->ApplyTransformMatrix(paramIndex, paramMatrix);
}


bool Renderer::IsEmptyModelIndex(const int &paramIndex)
{
    return renderBase->IsEmptyModelIndex(paramIndex);
}


void Renderer::GetViewMatrix(QMatrix4x4 &outViewMatrix) const
{
    renderBase->GetViewMatrix(outViewMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::GetProjectionMatrix
/// \param outProjectionMatrix
///
void Renderer::GetProjectionMatrix(QMatrix4x4 &outProjectionMatrix) const
{
    renderBase->GetProjectionMatrix(outProjectionMatrix);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
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
