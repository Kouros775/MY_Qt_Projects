#ifndef PERSON_H
#define PERSON_H


#include <QObject>
#include <QString>


class Person : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ GetName WRITE SetName)

public:
    explicit Person(QObject *parent = nullptr);

    QString GetName() const
    {
        return m_name;
    }
    void SetName(const QString& name)
    {
        m_name = name;
    }

private:
    QString m_name;
};

#endif // PERSON_H
