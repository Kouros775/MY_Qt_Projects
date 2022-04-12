#include "renderbase.h"
#include <Qt3DCore>
#include <Qt3DRender>


RenderBase::RenderBase(QObject *parent)
    : QObject(parent)
{

}

std::shared_ptr<Qt3DCore::QEntity> RenderBase::Initialize()
{
    rootEntity = std::make_shared<Qt3DCore::QEntity>();

    return rootEntity;
}

bool RenderBase::AddModel(const int &paramIndex, const RenderModelInfo *paramModel)
{
    bool bRes = false;

    if(true == IsEmptyIndex(paramIndex))
    {
        // Torus
        std::shared_ptr<Qt3DCore::QEntity> modelEntity = std::make_shared<Qt3DCore::QEntity>(rootEntity.get());

        modelEntity->addComponent(paramModel->mesh.get());
        modelEntity->addComponent(paramModel->material.get());
        modelEntity->addComponent(paramModel->transform.get());

        modelMap[paramIndex] = modelEntity;

        bRes = true;
    }
    else
    {
        assert(0);
    }

    return bRes;
}

bool RenderBase::DeleteModel(const int &paramIndex)
{
    bool bRes = false;

    if(false == IsEmptyIndex(paramIndex))
    {
        auto findIndex = modelMap.find(paramIndex);

        modelMap[paramIndex]->~QEntity();
        modelMap.erase(findIndex);

        bRes = true;
    }
    else
    {
        assert(0);
    }

    return bRes;
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
