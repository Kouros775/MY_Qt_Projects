#ifndef COMMANDLOADMODEL_H
#define COMMANDLOADMODEL_H

#include "Command/icommand.h"

namespace Qt3DRender
{
    class QMesh;
}


class CommandLoadModel : public ICommand
{
    Q_OBJECT
public:
    explicit CommandLoadModel(QObject *parent=nullptr);
    ~CommandLoadModel() override;

public:
    void Execute() override;


signals:
    void SignalLoadModel(Qt3DRender::QMesh* paramMesh);
};

#endif // COMMANDLOADMODEL_H
