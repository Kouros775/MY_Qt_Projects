#include "meshmodel.h"
#include <QDebug>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>
#include <Qt3DRender/QMaterial>
#include <Qt3DRender/QGeometryRenderer>


MeshModel::MeshModel(Qt3DCore::QEntity* parent)
    : QEntity(parent)
    , index(0)
    , color(200, 200, 200)
{
}


MeshModel::~MeshModel()
{
    qDebug() <<__FUNCTION__;
}

Qt3DCore::QTransform *MeshModel::GetTransform() const
{
    Qt3DCore::QTransform* transform = nullptr;

    //QComponents
    Qt3DCore::QComponentVector components = this->components();

    for(int i = 0 ; i < components.size() ; i++)
    {
        Qt3DCore::QTransform* component = dynamic_cast<Qt3DCore::QTransform*>(components[i]);

        if(nullptr != component)
        {
            transform = component;
            break;
        }
        else
        {
            continue;
        }
    }

    return transform;
}

Qt3DRender::QMaterial *MeshModel::GetMaterial() const
{
    Qt3DRender::QMaterial* material = nullptr;

    //QComponents
    Qt3DCore::QComponentVector components = this->components();

    for(int i = 0 ; i < components.size() ; i++)
    {
        Qt3DRender::QMaterial* component = dynamic_cast<Qt3DRender::QMaterial*>(components[i]);

        if(nullptr != component)
        {
            material = component;
            break;
        }
        else
        {
            continue;
        }
    }

    return material;
}


Qt3DRender::QGeometryRenderer *MeshModel::GetGeometryRenderer() const
{
    Qt3DRender::QGeometryRenderer* geometryRenderer = nullptr;

    //QComponents
    Qt3DCore::QComponentVector components = this->components();

    for(int i = 0 ; i < components.size() ; i++)
    {
        Qt3DRender::QGeometryRenderer* component = dynamic_cast<Qt3DRender::QGeometryRenderer*>(components[i]);

        if(nullptr != component)
        {
            geometryRenderer = component;
            break;
        }
        else
        {
            continue;
        }
    }

    return geometryRenderer;
}


