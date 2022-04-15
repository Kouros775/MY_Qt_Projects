#ifndef COMMANDTORUSADD_H
#define COMMANDTORUSADD_H

#include "Command/icommand.h"


namespace Qt3DRender
{
    class QGeometryRenderer;
}
class QListWidget;


class CommandTorusAdd : public ICommand
{
    Q_OBJECT
public:
    explicit CommandTorusAdd(QObject *parent=nullptr);
    ~CommandTorusAdd() override;
    void Execute() override;

    void SetListWidget(QListWidget* param){this->listWidget = param;}

signals:
    void AddModel(const int& paramIndex, Qt3DRender::QGeometryRenderer* paramMesh);

private:
    QListWidget*    listWidget;
    int             currentIndex;
};

#endif // COMMANDTORUSADD_H
