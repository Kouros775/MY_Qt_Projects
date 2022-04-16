#ifndef COMMANDEDITMODELCOLOR_H
#define COMMANDEDITMODELCOLOR_H

#include "Command/icommand.h"


class QColor;


class CommandEditModelColor : public ICommand
{
    Q_OBJECT
public:
    explicit CommandEditModelColor(QObject *parent=nullptr);
    ~CommandEditModelColor() override;
    void Execute() override;

signals:
    void EditModelColor(const int& paramindex, const QColor& paramColor);
};

#endif // COMMANDEDITMODELCOLOR_H
