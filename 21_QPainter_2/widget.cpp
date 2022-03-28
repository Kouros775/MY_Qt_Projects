#include "widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);


    QPainter painter;

    painter.begin(this);
    painter.setBrush(QBrush(Qt::red, Qt::Dense3Pattern));
    QPen pen(Qt::blue);
    pen.setWidth(4);
    painter.setPen(pen);

    QRect rect1(10.0, 20.0, 80.0, 50.0);
    painter.drawEllipse(rect1);


    painter.setBrush(QBrush(Qt::NoBrush));
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);

    QRect rect2(110.0, 20.0, 80.0, 50.0);
    painter.drawEllipse(rect2);

    QLinearGradient ling(QPointF(300, 300), QPointF(500, 500));
    ling.setColorAt(0, Qt::blue);
    ling.setColorAt(1, Qt::green);

    ling.setSpread(QGradient::PadSpread);

    QBrush brush(ling);
    painter.setBrush(brush);
    painter.drawRect(300, 300, 500, 500);


    painter.end();
}
