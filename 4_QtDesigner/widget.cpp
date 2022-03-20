#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->slider1, SIGNAL(valueChanged(int)), this, SLOT(slider1_valueChanged(int)));
    connect(ui->slider2, SIGNAL(valueChanged(int)), this, SLOT(slider2_valueChanged(int)));
    connect(ui->slider3, SIGNAL(valueChanged(int)), this, SLOT(slider3_valueChanged(int)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slider1_valueChanged(int val)
{
    ui->spinBox1->setValue(val);
}

void Widget::slider2_valueChanged(int val)
{
    ui->spinBox2->setValue(val);
}

void Widget::slider3_valueChanged(int val)
{
    ui->spinBox3->setValue(val);
}
