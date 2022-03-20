#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int val = 100;

    qDebug() << "Hello World.";
    qDebug("QT MY First Project. Val is %d", val);

    return a.exec();
}
