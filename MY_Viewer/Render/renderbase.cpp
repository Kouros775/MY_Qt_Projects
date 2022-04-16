#include "renderbase.h"
#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DCore/QEntity>

#include "Render/meshmodel.h"


RenderBase::RenderBase(QObject *parent)
    : QObject(parent)
    , rootEntity(nullptr)
{

}

RenderBase::~RenderBase()
{
    qDebug() <<__FUNCTION__;
}

Qt3DCore::QEntity* RenderBase::Initialize()
{
    rootEntity = new Qt3DCore::QEntity();

    return rootEntity;
}

bool RenderBase::AddModel(const int &paramIndex, MeshModel *paramModel)
{
    bool bRes = false;

    if(true == IsEmptyIndex(paramIndex))
    {
        modelMap[paramIndex] = paramModel;

        bRes = true;
    }
    else
    {
    }

    return bRes;
}

bool RenderBase::RemoveModel(const int &paramIndex)
{
    bool bRes = false;

    if(false == IsEmptyIndex(paramIndex))
    {
        auto findIndex = modelMap.find(paramIndex);

        modelMap[paramIndex]->~MeshModel();
        modelMap.erase(findIndex);

        bRes = true;
    }
    else
    {
    }

    return bRes;
}

bool RenderBase::RemoveAllModel()
{
    QMap<int, MeshModel*>::iterator iter = modelMap.begin();

    for(iter ; iter != modelMap.end() ; iter++)
    {
        iter.value()->~MeshModel();
        modelMap.erase(iter);
    }
}


bool RenderBase::IsEmptyIndex(const int &paramIndex) const
{
    bool bRes = false;

    auto findIndex = modelMap.find(paramIndex);

    if(findIndex != modelMap.end())
    {
        bRes = false;
    }
    else
    {
        bRes = true;
    }


    return bRes;
}


MeshModel *RenderBase::GetModel(const int &paramIndex) const
{
    MeshModel* model = nullptr;

    if(false == IsEmptyIndex(paramIndex))
    {
        auto findIndex = modelMap.find(paramIndex);

        model = findIndex.value();
    }
    else
    {
    }

    return model;
}

QMap<int, MeshModel *> *RenderBase::GetModelMap()
{
    return &modelMap;
}
