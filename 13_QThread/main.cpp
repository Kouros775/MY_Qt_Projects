#include <QCoreApplication>
#include <producer.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Consumer consumer;
    Producer producer;


    producer.start();
    consumer.start();


    return a.exec();
}
