#include "widget.h"
#include <QStandardItemModel>
#include <QDateTime>
#include <QTableView>
#include <QVBoxLayout>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStandardItemModel* model = new QStandardItemModel(0,3);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Subject"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Data"));

    model->setVerticalHeaderItem(0, new QStandardItem("Col 1"));
    model->setVerticalHeaderItem(1, new QStandardItem("Col 2"));

    model->setData(model->index(0, 0), "Monitor");
    model->setData(model->index(0, 1), "LCD");
    model->setData(model->index(0, 2), QDateTime(QDate(2030, 10, 4)));

    model->setData(model->index(1, 0), "CPU");
    model->setData(model->index(1,1), "Samsung");
    model->setData(model->index(1,2), QDateTime(QDate(2030, 12 , 5)));

    QTableView* table = new QTableView();
    table->setModel(model);

    QVBoxLayout* lay = new QVBoxLayout();
    lay->addWidget(table);

    setLayout(lay);
}

Widget::~Widget()
{

}
