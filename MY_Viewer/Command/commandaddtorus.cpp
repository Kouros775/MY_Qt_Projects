#include "commandaddtorus.h"
#include "Document/document.h"
#include <QListWidget>

#include "Widget/modellistwidgetitem.h"


#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"


CommandAddTorus::CommandAddTorus(QObject *parent)
    : ICommand(parent)
    , listWidget(nullptr)
{

}

CommandAddTorus::~CommandAddTorus()
{

}

void CommandAddTorus::Execute()
{
    int addIndex = Document::Instance().GetAddIndex();
    QString itemText = QString::number(addIndex) + " : " + "Torus";

    ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
    item->SetIndex(addIndex);
    item->SetName("Torus");

    listWidget->addItem(item);
    listWidget->setCurrentItem(item);


    emit AddTorus(addIndex);
    Document::Instance().SetAddIndex(addIndex + 1);
    Document::Instance().SetSelectedIndex(addIndex);
}
