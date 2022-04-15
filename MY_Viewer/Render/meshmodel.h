#ifndef MESHMODEL_H
#define MESHMODEL_H

#include <Qt3DCore/QEntity>
#include <QObject>


namespace Qt3DCore
{
    class QComponent;
    class QEntity;
    class QTransform;
}
namespace Qt3DRender
{
    class QPickEvent;
}
namespace Qt3DExtras
{
    class QPhongMaterial;
}

class MeshModel : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit MeshModel(Qt3DCore::QEntity* parent = nullptr);
    ~MeshModel() override;

    void SetIndex(const int& paramIndex){this->index = paramIndex;}
    int GetIndex() const {return index;}

    Qt3DCore::QTransform* GetTransform() const;
    Qt3DExtras::QPhongMaterial* GetMaterial() const;

private:
    int index;
};

#endif // MESHMODEL_H
