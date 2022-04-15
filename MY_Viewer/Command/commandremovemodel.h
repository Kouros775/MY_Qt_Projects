#ifndef COMMANDREMOVEMODEL_H
#define COMMANDREMOVEMODEL_H

#include "Command/icommand.h"


class QListWidget;


class CommandRemoveModel : public ICommand
{
    Q_OBJECT
public:
    explicit CommandRemoveModel(QObject *parent=nullptr);
    virtual ~CommandRemoveModel();
    virtual void Execute();

    void SetListWidget(QListWidget* param){this->listWidget = param;}

signals:
    void RemoveModel(const int& paramIndex);

private:
    QListWidget*    listWidget;
};


#endif // COMMANDREMOVEMODEL_H
