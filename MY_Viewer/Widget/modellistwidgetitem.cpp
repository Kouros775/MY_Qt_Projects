#include "modellistwidgetitem.h"
#include <QDebug>


ModelListWidgetItem::ModelListWidgetItem(const QIcon &icon, const QString &text, QListWidget *view, int type)
    : QListWidgetItem(icon, text, view ,type)
    , index(0)
{

}

ModelListWidgetItem::~ModelListWidgetItem()
{
}
