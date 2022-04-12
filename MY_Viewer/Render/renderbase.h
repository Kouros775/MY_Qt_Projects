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
}
struct RenderModelInfo
{
    Qt3DCore::QTransform* transform;
    Qt3DRender::QMaterial* material;
    Qt3DRender::QMesh* mesh;
};


class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    Qt3DCore::QEntity* Initialize();

    bool AddModel(const int& paramIndex, const RenderModelInfo* paramModel);
    bool DeleteModel(const int& paramIndex);
    bool IsEmptyIndex(const int& paramIndex) const;

private:
    Qt3DCore::QEntity*                  rootEntity;
    QMap<int, Qt3DCore::QEntity*>       modelMap;
};

#endif // RENDERBASE_H
