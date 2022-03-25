#include <QCoreApplication>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <QtConcurrent/QtConcurrentRun>


void Hello(QString str)
{
    qDebug() << "Hello" << str << "from " << QThread::currentThread();

    for(int i = 0 ; i < 10 ; i++)
    {
        QThread::sleep(1);
        qDebug("[%s] i = %d", str.toLocal8Bit().data(), i);
    }
}

void World(QString str)
{
    qDebug() <<"World" << str << "from " << QThread::currentThread();

    for(int i = 0 ; i < 3; i++)
    {
        QThread::sleep(1);
        qDebug("[%s] i = %d", str.toLocal8Bit().data(), i);
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFuture<void> f1 = QtConcurrent::run(Hello, QString("Alice"));
    QFuture<void> f2 = QtConcurrent::run(Hello, QString("Dude"));
    QFuture<void> f3 = QtConcurrent::run(Hello, QString("MY"));

    f1.waitForFinished();
    f2.waitForFinished();
    f3.waitForFinished();

    return a.exec();
}
