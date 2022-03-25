#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QPushButton>
#include <QDebug>
#include <QDateTime>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_timer = new QTimer();

    ui->PushButton_TimerStart->setEnabled(true);
    ui->pushButton_TimerStop->setEnabled(false);

    connect(ui->PushButton_TimerStart, &QPushButton::pressed, this, &Widget::_startTimer);
    connect(ui->pushButton_TimerStop, &QPushButton::pressed, this, &Widget::_stopTimer);

    connect(m_timer, &QTimer::timeout, this, &Widget::_elapsedTimer);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::_startTimer()
{
    ui->PushButton_TimerStart->setEnabled(false);
    ui->pushButton_TimerStop->setEnabled(true);

    m_timer->start(1000);
}

void Widget::_stopTimer()
{
    ui->PushButton_TimerStart->setEnabled(true);
    ui->pushButton_TimerStop->setEnabled(false);

    m_timer->stop();
}

void Widget::_elapsedTimer()
{
    QDateTime curTime = QDateTime::currentDateTime();
    QString strTime = curTime.toString("현재시간 yyyy-MM-dd hh:mm:ss");
    ui->label_Time->setText(strTime);
}
