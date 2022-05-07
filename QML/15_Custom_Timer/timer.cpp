#include "timer.h"
#include <QDebug>
#include <QTimer>


Timer::Timer(QObject *parent)
    : QObject(parent)
    , m_timer(new QTimer(this))
{
    connect(m_timer, &QTimer::timeout, this, &Timer::timeout);
}


void Timer::setInterval(const int &msec)
{
    if(m_timer->interval() == msec)
    {
        return;
    }
    else
    {
        m_timer->setInterval(msec);
        emit intervalChanged();
    }
}


int Timer::interval() const
{
    return m_timer->interval();
}


bool Timer::isActive() const
{
    return m_timer->isActive();
}


void Timer::start()
{
    if(true == m_timer->isActive())
    {
        return;
    }
    else
    {
        m_timer->start();
        emit activeChanged();
    }
}


void Timer::stop()
{
    if(false == m_timer->isActive())
    {
        return;
    }
    else
    {
        m_timer->stop();
        emit activeChanged();
    }
}
