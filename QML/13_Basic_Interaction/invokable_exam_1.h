#ifndef INVOKABLE_EXAM_1_H
#define INVOKABLE_EXAM_1_H

#include <QObject>

class invokable_exam_1 : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author
               READ author
               WRITE setAuthor
               NOTIFY authorChanged)
public:
    invokable_exam_1();
    Q_INVOKABLE bool postMessage(const QString& msg);

    void setAuthor(const QString& a);
    QString author() const
    {
        return m_author;
    }

signals:
    void authorChanged();
public slots:
    void refresh();
private:
    QString m_author;
};

#endif // INVOKABLE_EXAM_1_H
