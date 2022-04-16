#include "commandaddcube.h"
#include "Document/document.h"
#include <QListWidget>

#include "Widget/modellistwidgetitem.h"


#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"


CommandAddCube::CommandAddCube(QObject *parent)
    : ICommand(parent)
    , listWidget(nullptr)
{

}

CommandAddCube::~CommandAddCube()
{

}

void CommandAddCube::Execute()
{
    int addIndex = Document::Instance().GetAddIndex();
    QString itemText = QString::number(addIndex) + " : " + "Cube";

    ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
    item->SetIndex(addIndex);
    item->SetName("Cube");

    listWidget->addItem(item);
    listWidget->setCurrentItem(item);


    emit AddCube(addIndex);
    Document::Instance().SetAddIndex(addIndex + 1);
    Document::Instance().SetSelectedIndex(addIndex);
}
