#include "widget.h"
#include <QPainter>
#include <QPaintEvent>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
}

Widget::~Widget()
{

}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;

    painter.begin(this);

    painter.setPen(Qt::blue);
    painter.drawLine(10, 10, 100, 40);
    painter.drawRect(120, 10, 80, 80);

    QRectF rect(230.0, 10.0 ,80.0, 80.0);
    painter.drawRoundedRect(rect, 20, 20);

    QPointF p1[3]
    {
        QPointF(10.0, 110.0),
        QPointF(110.0, 110.0),
        QPointF(110.0, 190.0)
    };
    painter.drawPolyline(p1, 3);

    QPointF p2[3] =
    {
        QPointF(120.0, 110.0),
        QPointF(220.0, 110.0),
        QPointF(220.0, 190.0)
    };
    painter.drawPolygon(p2, 3);

    painter.setFont(QFont("Arial", 20));
    painter.setPen(Qt::black);
    QRect fontRect(10, 150, 300, 200);
    painter.drawText(fontRect, Qt::AlignCenter, "JMY Painter Test.");

    painter.end();
}
