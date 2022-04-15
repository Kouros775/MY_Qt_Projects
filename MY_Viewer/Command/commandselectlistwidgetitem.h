#ifndef COMMANDSELECTLISTWIDGETITEM_H
#define COMMANDSELECTLISTWIDGETITEM_H

#include "Command/icommand.h"


class QListWidgetItem;


class CommandSelectListWidgetItem : public ICommand
{
    Q_OBJECT
public:
    explicit CommandSelectListWidgetItem(QObject *parent=nullptr);
    virtual ~CommandSelectListWidgetItem() override;
    void Execute() override;

public slots:
    void ItemPressed(QListWidgetItem* item);

signals:
    void SelectModel(const int& paramindex);

};

#endif // COMMANDSELECTLISTWIDGETITEM_H
