#include <QCoreApplication>
#include <person.h>
#include <QDebug>
#include <QVariant>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Person person;
    person.setProperty("name", "JMY");
    qDebug() << person.GetName();

    QVariant myName = person.property("name");
    qDebug() <<"person name : " << myName.toString();


    return a.exec();
}
