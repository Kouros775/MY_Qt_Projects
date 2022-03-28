#include "widget.h"
#include <QPainter>
#include <QImage>
#include <QTransform>


#define FILE_PATH  ":/JMY.jpg"


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

    QImage image(FILE_PATH);

    QPainter painter;

    painter.begin(this);

    QTransform transform;
    transform.translate(100, 100);
    transform.rotate(45, Qt::YAxis);
    transform.scale(1.5, 1.0);

    painter.setTransform(transform);
    painter.drawImage(0, 0, image);


    painter.end();
}
