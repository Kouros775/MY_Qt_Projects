#ifndef ICOMMAND_H
#define ICOMMAND_H


#include <QObject>


class ICommand : public QObject
{
    Q_OBJECT

public:
    ICommand() = default;
    virtual ~ICommand() = default;


public:
    virtual void Execute() = 0;
};

#endif // ICOMMAND_H
