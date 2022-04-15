#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <QObject>

class ICommand : public QObject
{
    Q_OBJECT
public:
    explicit ICommand(QObject *parent=nullptr);
    virtual ~ICommand() = default;

public:
    virtual void Execute() = 0;

};

#endif // ICOMMAND_H
