#include "rendermodel.h"
#include <Qt3DRender>
#include <Qt3DExtras>


RenderModel::RenderModel()
{
}

RenderModel::~RenderModel()
{

}


void RenderModel::MakeTorus(const float &paramRadius, const float &paramMinorRadius, const int &paramRing, const int &paramSlice)
{
    mesh = std::make_shared<Qt3DExtras::QTorusMesh>();

    Qt3DExtras::QTorusMesh* torusMesh = dynamic_cast<Qt3DExtras::QTorusMesh*>(mesh.get());
    torusMesh->setRadius(5);
    torusMesh->setMinorRadius(1);
    torusMesh->setRings(100);
    torusMesh->setSlices(20);
}
