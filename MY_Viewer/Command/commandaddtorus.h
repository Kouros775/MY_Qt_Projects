#ifndef COMMANDADDTORUS_H
#define COMMANDADDTORUS_H

#include "Command/icommand.h"


class QListWidget;


class CommandAddTorus : public ICommand
{
    Q_OBJECT
public:
    explicit CommandAddTorus(QObject *parent = nullptr);
    ~CommandAddTorus() override;
    void Execute() override;

    void SetListWidget(QListWidget* param){this->listWidget = param;}


signals:
    void AddTorus(const int& paramIndex);

private:
    QListWidget*    listWidget;
};

#endif // COMMANDADDTORUS_H
