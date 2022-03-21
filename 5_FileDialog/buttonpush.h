#ifndef BUTTONPUSH_H
#define BUTTONPUSH_H

#include <QObject>

class ButtonPush : public QObject
{
    Q_OBJECT
public:
    explicit ButtonPush(QObject *parent = nullptr);

signals:
    void PushButton();

public slots:
};

#endif // BUTTONPUSH_H
