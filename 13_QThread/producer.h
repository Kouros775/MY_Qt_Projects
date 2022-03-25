#ifndef PRODUCER_H
#define PRODUCER_H
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

static QMutex mutex;
static QWaitCondition incNumber;
static int numUsed;


class Producer : public QThread
{
    Q_OBJECT

    void run() override
    {
        for(int i = 0 ; i < 10 ; i++)
        {
            sleep(1);
            numUsed++;
            qDebug("[Producer] numUsed %d", numUsed);

            mutex.lock();
            incNumber.wakeAll();
            mutex.unlock();
        }
    }

public:
    Producer() = default;
};


class Consumer : public QThread
{
    Q_OBJECT
    void run() override
    {
        for(int i = 0 ; i < 10 ; i++)
        {
            mutex.lock();
            incNumber.wait(&mutex);
            mutex.unlock();

            qDebug("[Consumer] numUsed %d", numUsed);
        }
    }
public:
    Consumer() = default;
};



#endif // PRODUCER_H
