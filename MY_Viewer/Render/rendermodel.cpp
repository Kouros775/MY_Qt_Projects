#include "rendermodel.h"

RenderModel::RenderModel()
{
    /////////////////
    // >> 앞
    vertices << QVector3D(1, -1, -1) << QVector3D(1, 1, -1) << QVector3D(-1, 1, -1);
    vertices << QVector3D(-1, 1, -1) << QVector3D(-1, -1, -1) << QVector3D(1, -1, -1);

    // 뒤
    vertices << QVector3D(1, -1, 1) << QVector3D(1, 1, 1) << QVector3D(-1, 1, 1);
    vertices << QVector3D(-1, 1, 1) << QVector3D(-1, -1, 1) << QVector3D(1, -1, 1);

    // 오른쪽
    vertices << QVector3D(1, -1, -1) << QVector3D(1, 1, -1) << QVector3D(1, 1, 1);
    vertices << QVector3D(1, 1, 1) << QVector3D(1, -1, -1) << QVector3D(1, -1, -1);

    // 왼쪽
    vertices << QVector3D(-1, -1, -1) << QVector3D(-1, 1, -1) << QVector3D(-1, 1, 1);
    vertices << QVector3D(-1, 1, 1) << QVector3D(-1, -1, -1) << QVector3D(-1, -1, -1);

    // 위
    vertices << QVector3D(1, 1, 1) << QVector3D(1, 1, -1) << QVector3D(-1, 1, -1);
    vertices << QVector3D(-1, 1, -1) << QVector3D(-1, 1, 1) << QVector3D(1, 1, 1);

    // 아래
    vertices << QVector3D(1, -1, 1) << QVector3D(1, -1, -1) << QVector3D(-1, -1, -1);
    vertices << QVector3D(-1, -1, -1) << QVector3D(-1, -1, 1) << QVector3D(1, -1, 1);
}

RenderModel::~RenderModel()
{

}

void RenderModel::DeepCopy(const RenderModel &paramModel)
{
    vertices = paramModel.GetVertices();
}

void RenderModel::TempFunction()
{
    /////////////////
    // >> 앞
    vertices.clear();

    vertices << QVector3D(1+3, -1+3, -1+3) << QVector3D(1+3, 1+3, -1+3) << QVector3D(-1+3, 1+3, -1+3);
    vertices << QVector3D(-1+3, 1+3, -1+3) << QVector3D(-1+3, -1+3, -1+3) << QVector3D(1+3, -1+3, -1+3);
}
