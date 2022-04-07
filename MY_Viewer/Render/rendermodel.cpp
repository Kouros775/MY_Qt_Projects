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
