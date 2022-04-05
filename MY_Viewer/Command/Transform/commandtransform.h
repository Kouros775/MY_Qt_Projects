#ifndef COMMANDTRANSFORM_H
#define COMMANDTRANSFORM_H

#include "Command/icommand.h"
#include <QPoint>


class CommandTransform : public ICommand
{
public:
    explicit CommandTransform();

    // ICommand interface
public:
    virtual void Execute() override;

    void SetStartPoint(const QPoint& paramPoint);
    void SetEndPoint(const QPoint& paramPoint);

    QPoint GetStartPoint() const {return startPoint;}
    QPoint GetEndPoint() const {return endPoint;}

private:
    QPoint startPoint;
    QPoint endPoint;
};

#endif // COMMANDTRANSFORM_H
