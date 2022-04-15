#ifndef COMMANDLOADMODEL_H
#define COMMANDLOADMODEL_H

#include "Command/icommand.h"


namespace Qt3DRender
{
    class QMesh;
}
class QListWidget;


class CommandLoadModel : public ICommand
{
    Q_OBJECT
public:
    explicit CommandLoadModel(QObject *parent=nullptr);
    ~CommandLoadModel() override;
    void Execute() override;

    void SetListWidget(QListWidget* param){this->listWidget = param;}

signals:
    void AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);

private:
    QListWidget*    listWidget;
    int             currentIndex;
};

#endif // COMMANDLOADMODEL_H
