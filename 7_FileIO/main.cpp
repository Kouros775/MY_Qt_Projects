#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QTextStream>


void write(QString fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::Text | QFile::WriteOnly))
    {
        qDebug("Write Fail.");
        return;
    }

    QTextStream out(&file);
    out <<"Write Test.";
    file.flush();
    file.close();
}


void read(QString fileName)
{
    QFile file(fileName);

    if(!file.open(QFile::Text | QFile::ReadOnly))
    {
        qDebug("Read Fail.");
        return;
    }

    QTextStream in(&file);
    qDebug() << in.readAll();

    file.close();
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString fileName = "C:/Qt/MyFile.txt";

    write(fileName);
    read(fileName);

    return a.exec();
}
