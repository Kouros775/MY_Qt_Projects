#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>


class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ GetName WRITE SetName NOTIFY _changeName)

public:
    explicit Person(QObject *parent = nullptr);
    void SetName(const QString& name)
    {
        m_name = name;
        emit _changeName(name);
    }
    QString GetName() const
    {
        return m_name;
    }

signals:
    void _changeName(const QString& name);
private:
    QString m_name;
};

#endif // PERSON_H
