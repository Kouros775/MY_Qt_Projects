#include "meshmodel.h"
#include "meshmodel.h"
#include <Qt3DCore/QEntity>
#include <QDebug>
#include <Qt3DRender/QObjectPicker>


MeshModel::MeshModel(Qt3DCore::QEntity* parent)
    : QEntity(parent)
{
}


MeshModel::~MeshModel()
{

}


void MeshModel::clicked(Qt3DRender::QPickEvent *pick)
{
    Q_UNUSED(pick);

    qDebug()<<"clicked : " <<name;
}

void MeshModel::entered()
{
    qDebug()<<"entered : " <<name;

}
