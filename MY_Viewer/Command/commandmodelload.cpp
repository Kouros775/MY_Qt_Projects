#include "commandmodelload.h"

#include "Render/rendermodel.h"
#include "Loader/modelloader.h"


CommandModelLoad::CommandModelLoad(QObject *parent)
    : QObject(parent)
    , ICommand()
{

}

void CommandModelLoad::Execute()
{
    QString path;
    RenderModel* model;

    if(ModelLoader::LoadModel(path, model))
    {
        emit AddModel(model);
    }
    else
    {

    }
}
