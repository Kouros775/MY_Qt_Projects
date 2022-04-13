#include "meshmodel.h"
#include <QDebug>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QTransform>


MeshModel::MeshModel(Qt3DCore::QEntity* parent)
    : QEntity(parent)
    , index(0)
{
}


MeshModel::~MeshModel()
{

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


