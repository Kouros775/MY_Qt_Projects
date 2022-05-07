#include "message.h"
#include <QDebug>
#include <QTimer>


Message::Message()
{
    qDebug() << "Message() Construction";
}


void Message::setAuthor(const QString &param)
{
    m_author = param;
    emit authorChanged();
}

QString Message::author() const
{
    return m_author;
}

bool Message::postMessage(const QString &msg)
{
    qDebug() <<"[C++ Layer] call postMessage method : " <<msg;
    return true;
}

void Message::refresh()
{
    qDebug() <<"Caleed the C++ slot.";
}

void Message::timerTimeout()
{
    emit newMessagePosted("I'm a boy.");
}
