#include "commandselectlistwidgetitem.h"
#include "Widget/modellistwidgetitem.h"


CommandSelectListWidgetItem::CommandSelectListWidgetItem(QObject *parent)
    : ICommand(parent)
{

}

CommandSelectListWidgetItem::~CommandSelectListWidgetItem()
{

}


void CommandSelectListWidgetItem::Execute()
{

}

void CommandSelectListWidgetItem::ItemPressed(QListWidgetItem *item)
{
    ModelListWidgetItem* modelItem = dynamic_cast<ModelListWidgetItem*>(item);
    emit SelectModel(modelItem->GetIndex());
}
