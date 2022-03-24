#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QLineEdit>
#include <person.h>
#include <QDebug>
#include <QVariant>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    person = new Person();

    connect(ui->pushButton_Change, &QPushButton::pressed, this, &Widget::pushButtonChange);
    connect(person, &Person::_changeName, this, &Widget::_changeName);
}

Widget::~Widget()
{
    delete ui;
    delete person;
}

void Widget::pushButtonChange()
{
    QString name = ui->lineEdit_Name->text();
    person->setProperty("name", name);
}

void Widget::_changeName(const QString &name)
{
    qDebug() << "param : " << name;

    QVariant var = person->property("name");
    qDebug() << "property : " << var.toString();
}
