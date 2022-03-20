#ifndef SIGNALSLOT_H
#define SIGNALSLOT_H

#include <QObject>

class SignalSlot : public QObject
{
    Q_OBJECT
public:
    void SetValue(int val);


signals:
    void valueChanged(int newValue);

private:
    int m_Value;
};

#endif // SIGNALSLOT_H
