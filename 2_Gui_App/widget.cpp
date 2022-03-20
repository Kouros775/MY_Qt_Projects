#include "widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300,200);

    str = QString("Hello World.");
    btn = new QPushButton(str, this);
    btn->setGeometry(10, 10, 100, 30);

    connect(btn, &QPushButton::clicked, this, &Widget::slot_btn);
}

Widget::~Widget()
{

}

void Widget::slot_btn()
{
    qDebug() <<"button clicked.";
}
