#include "invokable_exam_1.h"
#include <QDebug>


invokable_exam_1::invokable_exam_1()
{
    qDebug() <<"Message() construction";
}

bool invokable_exam_1::postMessage(const QString &msg)
{
    qDebug() << "[C++] call postMessage Method : " <<msg;
    return true;
}

void invokable_exam_1::setAuthor(const QString &a)
{
    m_author = QString("%1 world.").arg(a);
    emit authorChanged();
}

void invokable_exam_1::refresh()
{
    qDebug() << "Called the C++ slot";
}
