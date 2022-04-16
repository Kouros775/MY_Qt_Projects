#ifndef MESHMODEL_H
#define MESHMODEL_H

#include <Qt3DCore/QEntity>
#include <QObject>


namespace Qt3DCore
{
    class QTransform;
}
namespace Qt3DRender
{
    class QMaterial;
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
    Qt3DRender::QMaterial* GetMaterial() const;

private:
    int index;
};

#endif // MESHMODEL_H
