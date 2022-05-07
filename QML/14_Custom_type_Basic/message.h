#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString author
               READ author
               WRITE setAuthor
               NOTIFY authorChanged)
public:
    explicit Message();

    void setAuthor(const QString& param);
    QString author() const;

    Q_INVOKABLE bool postMessage(const QString& msg);

signals:
    void authorChanged();
    void newMessagePosted(const QString& subject);

public slots:
    void refresh();
    void timerTimeout();
private:
    QString m_author;
};

#endif // MESSAGE_H
