#include "message.h"


void message::setAuthor(const QString &a)
{
    m_author = QString("%1 world.").arg(a);
    emit authorChanged();
}

QString message::author() const
{
    return m_author;
}
