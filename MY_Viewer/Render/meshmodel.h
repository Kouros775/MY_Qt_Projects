#ifndef MESHMODEL_H
#define MESHMODEL_H

#include <Qt3DCore/QEntity>
#include <QObject>
#include <QColor>


namespace Qt3DCore
{
    class QTransform;
}
namespace Qt3DRender
{
    class QMaterial;
    class QGeometryRenderer;
}


class MeshModel : public Qt3DCore::QEntity
{
    Q_OBJECT
public:
    explicit MeshModel(Qt3DCore::QEntity* parent = nullptr);
    ~MeshModel() override;

    void SetIndex(const int& paramIndex){this->index = paramIndex;}
    int GetIndex() const {return index;}

    void SetColor(const QColor& paramColor){this->color = paramColor;}
    QColor GetColor() const {return this->color;}

    Qt3DCore::QTransform* GetTransform() const;
    Qt3DRender::QMaterial* GetMaterial() const;
    Qt3DRender::QGeometryRenderer* GetGeometryRenderer() const;
private:
    int index;
    QColor color;
};

#endif // MESHMODEL_H
