#ifndef MESHMODEL_H
#define MESHMODEL_H

#include <Qt3DCore/QEntity>
#include <QObject>


namespace Qt3DCore
{
    class QComponent;
    class QEntity;
}
namespace Qt3DRender
{
    class QPickEvent;
}


class MeshModel : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit MeshModel(Qt3DCore::QEntity* parent = nullptr);
    ~MeshModel() override;

    void SetIndex(const int& paramIndex){this->index = paramIndex;}
    int GetIndex() const {return index;}

    void SetName(const QString& paramName){this->name = paramName;}
    QString GetName() const {return name;}

private slots:
    void entered();
    void clicked(Qt3DRender::QPickEvent *pick);
private:
    int index;
    QString name;
};

#endif // MESHMODEL_H
