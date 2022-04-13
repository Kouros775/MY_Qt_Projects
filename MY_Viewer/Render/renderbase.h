#ifndef RENDERBASE_H
#define RENDERBASE_H

#include <QObject>
#include <QMap>


namespace Qt3DCore
{
    class QTransform;
    class QEntity;
}
namespace Qt3DRender
{
    class QMesh;
    class QMaterial;
    class QObjectPicker;
}

class MeshModel;


class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    Qt3DCore::QEntity* Initialize();

    bool AddModel(const int& paramIndex, MeshModel* paramModel);
    bool DeleteModel(const int& paramIndex);
    bool IsEmptyIndex(const int& paramIndex) const;
    bool PickModel(const QPoint& point) const;

private:
    Qt3DCore::QEntity*                  rootEntity;
    QMap<int, MeshModel*>       modelMap;
};

#endif // RENDERBASE_H
