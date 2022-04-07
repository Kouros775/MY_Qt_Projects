#include "renderbase.h"

RenderBase::RenderBase()
{

}

void RenderBase::Init()
{

}

void RenderBase::Paint()
{

}

void RenderBase::Resize(const int &width, const int &height)
{

}

bool RenderBase::AddModel(const RenderModel &paramModel, const int &paramIndex)
{

}

bool RenderBase::SetTransformMatrix(const QMatrix4x4 &paramMatrix, const int &paramIndex)
{

}

void RenderBase::GetTransformMatrix(QMatrix4x4 &outMatrix)
{

}

bool RenderBase::ApplyTransformMatrix(const QMatrix4x4 &paramMatrix, const int &paramIndex)
{

}

bool RenderBase::IsEmptyModelIndex(const int &paramIndex)
{

}

void RenderBase::GetViewMatrix(QMatrix4x4 &outViewMatrix) const
{

}

void RenderBase::GetProjectionMatrix(QMatrix4x4 &outProjectionMatrix) const
{

}
