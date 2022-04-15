#include "commandremovemodel.h"
#include <QListWidgetItem>
#include "Widget/modellistwidgetitem.h"


CommandRemoveModel::CommandRemoveModel(QObject *parent)
    : ICommand(parent)
    , listWidget(nullptr)
{

}


CommandRemoveModel::~CommandRemoveModel()
{

}

void CommandRemoveModel::Execute()
{
    QListWidgetItem* removeItem = listWidget->takeItem(listWidget->currentRow());

    if(removeItem)
    {
        ModelListWidgetItem* modelItem = dynamic_cast<ModelListWidgetItem*>(removeItem);
        emit RemoveModel(modelItem->GetIndex());
        delete modelItem;
    }
}
