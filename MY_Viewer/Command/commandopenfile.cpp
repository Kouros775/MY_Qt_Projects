#include "commandopenfile.h"
#include <QDebug>
#include "Render/rendermodel.h"


CommandOpenFile::CommandOpenFile()
{

}

void CommandOpenFile::Execute()
{
    qDebug("Execute CommandOpenFile");

    RenderModel* model = new RenderModel();

    //AddModel(*model);
}
