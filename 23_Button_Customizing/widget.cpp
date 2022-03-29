#include "widget.h"
#include "ui_widget.h"
#include <imagebutton.h>
#include <QHBoxLayout>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ImageButton* imgBtn1 = new ImageButton(this);
    ImageButton* imgBtn2 = new ImageButton(this);

    QHBoxLayout* hlay = new QHBoxLayout(this);
    hlay->addWidget(imgBtn1);
    hlay->addWidget(imgBtn2);

    setLayout(hlay);

    connect(imgBtn1, &ImageButton::clicked, this, &Widget::clicked);
    imgBtn2->setDisabled(false);
}


Widget::~Widget()
{
    delete ui;
}


void Widget::clicked()
{
    qDebug("JMY : Click.");
}
