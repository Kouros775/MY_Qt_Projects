#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLineEdit>
#include <QFile>
#include <QDebug>
#include <QDataStream>

#define FILE_PATH   "c:/price.data"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->ButtonSave, SIGNAL(pressed()), this, SLOT(_savePriceInformation()));
    connect(ui->ButtonRead, SIGNAL(pressed()), this, SLOT(_readPriceInformation()));

    _pFile = new QFile();

    QString path(FILE_PATH);
    _pFile->setFileName(path);
}


Widget::~Widget()
{
    delete ui;
    _pFile->close();
    delete _pFile;
}

void Widget::_savePriceInformation()
{
    _pFile->open(QIODevice::WriteOnly | QIODevice::Truncate);

    if(_pFile->isOpen())
    {
       qint32 keyboardPrice = ui->LineEdit_Keyboard->text().toInt();
       qint32 monitorPrice = ui->LineEdit_Monitor->text().toInt();

       QDataStream fileStream(_pFile);

       fileStream << keyboardPrice;
       fileStream << monitorPrice;
    }
    else
    {
        qDebug() << Q_FUNC_INFO;
    }

    return;
}


void Widget::_readPriceInformation()
{
    _pFile->open(QIODevice::ReadOnly);

    if(_pFile->isOpen())
    {
        QDataStream fileStream(_pFile);

        qint32 keyboardPrice;
        fileStream >> keyboardPrice;
        qint32 monitorPrice;
        fileStream >> monitorPrice;

        qDebug() <<"Keyboard Price : " << keyboardPrice;
        qDebug() <<"Monitor Price : " << monitorPrice;
    }
    else
    {
        qDebug() << Q_FUNC_INFO;
    }

    return;
}
