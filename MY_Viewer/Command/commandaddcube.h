#ifndef COMMANDADDCUBE_H
#define COMMANDADDCUBE_H

#include "Command/icommand.h"


class QListWidget;


class CommandAddCube : public ICommand
{
    Q_OBJECT
public:
    explicit CommandAddCube(QObject *parent = nullptr);
    ~CommandAddCube() override;
    void Execute() override;

    void SetListWidget(QListWidget* param){this->listWidget = param;}


signals:
    void AddCube(const int& paramIndex);

private:
    QListWidget*    listWidget;
};

#endif // COMMANDADDCUBE_H
