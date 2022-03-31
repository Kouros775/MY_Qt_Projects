#include "widget.h"
#include <QPushButton>
#include <QPropertyAnimation>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(350, 200);

    QPushButton* btn = new QPushButton("Button", this);
    btn->setGeometry(10, 10, 100, 30);
    connect(btn, &QPushButton::pressed, this, &Widget::btnClicked);

    animation =  new QPropertyAnimation(btn, "geometry", this);

    animation->setDuration(3000);
    animation->setStartValue(QRect(10, 10, 100, 30));
    animation->setEndValue(QRect(200, 150, 100, 30));

    animation->setEasingCurve(QEasingCurve::OutInQuart);
}

Widget::~Widget()
{

}

void Widget::btnClicked()
{
    animation->start();
}
