#include "commandeditmodelcolor.h"
#include <QColorDialog>
#include "Document/document.h"


CommandEditModelColor::CommandEditModelColor(QObject *parent)
    : ICommand(parent)
{
}

CommandEditModelColor::~CommandEditModelColor()
{
}

void CommandEditModelColor::Execute()
{
    QColor color;
    color = QColorDialog::getColor(Qt::green, nullptr, "컬러선택" ,
     QColorDialog::DontUseNativeDialog);
    if (color.isValid())
    {
        emit EditModelColor(Document::Instance().GetSelectedIndex(), color);
    }

}
