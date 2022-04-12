#include "modeldocument.h"


ModelDocument::ModelDocument(QObject *parent)
    : QObject(parent)
    , currentIndex(1)
{
}


int ModelDocument::AddModel(Qt3DRender::QMesh *paramMesh)
{
    int index = currentIndex;

    if(true == isEmptyIndex(index))
    {
        mapMesh[index] = paramMesh;
        currentIndex++;
    }
    else
    {
        assert(0);
    }

    return index;
}


Qt3DRender::QMesh *ModelDocument::GetModel(const int &paramIndex) const
{
    Qt3DRender::QMesh* model = nullptr;

    if(false == isEmptyIndex(paramIndex))
    {
        model = mapMesh[paramIndex];
    }
    else
    {
        // nothing.
    }

    return model;
}


bool ModelDocument::isEmptyIndex(const int &paramIndex) const
{
    bool bRes = false;

    auto findIndex = mapMesh.find(paramIndex);

    if(findIndex != mapMesh.end())
    {
        bRes = false;
    }
    else
    {
        bRes = true;
    }

    return bRes;
}


