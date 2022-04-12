#ifndef COMMANDMODELLOAD_H
#define COMMANDMODELLOAD_H

#include <QObject>
#include "Command/icommand.h"


class RenderModel;

class CommandModelLoad : public QObject, ICommand
{
    Q_OBJECT
public:
    explicit CommandModelLoad(QObject *parent = nullptr);

    void Execute();
signals:
    void AddModel(const RenderModel* paramModel);
public slots:
};

#endif // COMMANDMODELLOAD_H
