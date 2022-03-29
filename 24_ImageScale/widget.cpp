#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>


#define IMAGE_PATH "://images/picture.png"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter;

    painter.begin(this);

    int w = this->window()->width();
    int h = this->window()->height();

    painter.setPen(QColor(0, 0, 0));
    painter.fillRect(0, 0, w, h, Qt::black);

    QPixmap imgPixmap = QPixmap(IMAGE_PATH).scaled(w, h, Qt::IgnoreAspectRatio);

    int imgWidth = imgPixmap.width();
    int imgHeight = imgPixmap.height();

    int xPos = 0;
    int yPos = 0;

    if(w > imgWidth)
    {
        xPos = (w - imgWidth) / 2;
    }
    else if(h > imgHeight)
    {
        yPos = (h - imgHeight) / 2;
    }

    painter.drawPixmap(xPos, yPos, imgPixmap);

    //QImage image(IMAGE_PATH);
    //painter.drawImage(0, 0, image);

    painter.end();
}
