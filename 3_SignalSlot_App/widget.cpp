#include "widget.h"
#include <QLabel>
#include <signalslot.h>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pLabel = new QLabel("", this);
    pLabel->setGeometry(10, 10, 250, 40);

    SignalSlot myObject;

    connect(&myObject, &SignalSlot::valueChanged, this, &Widget::SetValue);

    myObject.SetValue(775);
}

Widget::~Widget()
{

}

void Widget::SetValue(int val)
{
    QString str = QString("Signal. Value is %1").arg(val);
    pLabel->setText(str);
}
