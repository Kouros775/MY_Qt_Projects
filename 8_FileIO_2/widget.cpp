#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDir>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->OpenButton, SIGNAL(pressed()), this, SLOT(_fileOpen()));
    connect(ui->WriteButton, SIGNAL(pressed()), this, SLOT(_fileWrite()));
    connect(ui->CloseButton, SIGNAL(pressed()), this, SLOT(_fileClose()));

    _pFile = new QFile();

    connect(_pFile, SIGNAL(aboutToClose()), this, SLOT(_aboutToClose()));
}

Widget::~Widget()
{
    delete ui;
    delete _pFile;
}


void Widget::_fileOpen()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "Files (*.*)");

    _pFile->setFileName(fileName);

    if(!_pFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug("Open Failed.");
        return;
    }

    QTextStream in(_pFile);

    while(in.atEnd())
    {
        qDebug() << in.readLine();
    }
}


void Widget::_fileWrite()
{
    QTextStream out(_pFile);

    _pFile->seek(_pFile->size());
    out << "Add End Line.\n";
}


void Widget::_fileClose()
{
    if(_pFile->isOpen())
        _pFile->close();
}


void Widget::_aboutToClose()
{
    qDebug() << Q_FUNC_INFO;
}
