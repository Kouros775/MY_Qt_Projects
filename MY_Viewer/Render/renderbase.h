#ifndef RENDERBASE_H
#define RENDERBASE_H

#include <QObject>
#include <QMap>
#include <memory>


namespace Qt3DCore
{
    class QTransform;
    class QEntity;
}
namespace Qt3DRender
{
    class QMaterial;
    class QGeometryRenderer;
}
struct RenderModelInfo
{
    std::shared_ptr<Qt3DCore::QTransform> transform;
    std::shared_ptr<Qt3DRender::QMaterial> material;
    std::shared_ptr<Qt3DRender::QGeometryRenderer> mesh;
};


class RenderBase : public QObject
{
    Q_OBJECT
public:
    explicit RenderBase(QObject *parent = nullptr);
    std::shared_ptr<Qt3DCore::QEntity> Initialize();

    bool AddModel(const int& paramIndex, const RenderModelInfo* paramModel);
    bool DeleteModel(const int& paramIndex);
    bool IsEmptyIndex(const int& paramIndex) const;

private:
    std::shared_ptr<Qt3DCore::QEntity> rootEntity;
    QMap<int, std::shared_ptr<Qt3DCore::QEntity>> modelMap;
};

#endif // RENDERBASE_H
