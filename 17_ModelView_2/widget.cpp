#include "widget.h"
#include <QStringList>
#include <QAbstractItemModel>
#include <QListView>
#include <QModelIndex>
#include <QVBoxLayout>
#include <QLabel>
#include <QStringListModel>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(600, 300);

    QStringList strList;
    strList << "Monday" << "Tuesdat" << "Wednesday" << "Thursday" << "Friday";
    QAbstractItemModel *model = new QStringListModel(strList);

    QListView* view = new QListView();
    view->setModel(model);

    QModelIndex index = model->index(3,0);
    QString text = model->data(index, Qt::DisplayRole).toString();

    QLabel* label = new QLabel("");
    label->setText(text);

    QVBoxLayout* lay = new QVBoxLayout();
    lay->addWidget(view);
    lay->addWidget(label);

    setLayout(lay);
}

Widget::~Widget()
{

}
