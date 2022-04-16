#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QVector3D>


namespace Qt3DCore
{
    class QEntity;
}
namespace Qt3DRender
{
    class QCamera;
    class QMesh;
    class QPickEvent;
    class QGeometryRenderer;
}


class RenderCamera;
class RenderBase;
class MeshModel;
class CommandTransformTranslate;

enum class eMaterialType
{
    PhongMaterial,
    GoochMaterial
};


class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr);
    ~Renderer() override;

    Qt3DCore::QEntity *Initialize(Qt3DRender::QCamera* paramCamera);

    bool AddModel(const int& paramIndex, const QString& paramName, Qt3DRender::QGeometryRenderer* paramMesh);
    bool RemoveModel(const int& paramIndex);
    bool SelectModel(const int& paramIndex);
    bool SetMaterial(const int& paramIndex, const eMaterialType& paramMaterialType);
    bool SetColor(const int& paramIndex, const QColor& paramColor);

    bool Translate(const int& paramIndex, const QVector3D& startPos, const QVector3D& endPos) const;
    bool Rotate(const MeshModel* paramModel, const QVector3D& startPos, const QVector3D& endPos) const;
    bool Scale(const MeshModel* paramModel, const float& paramDelta);



    MeshModel* GetModel(const int& paramIndex) const;

    void AddCube(const int& paramIndex, const QVector3D paramExtents = QVector3D(40.0f, 40.0f, 40.0f));
private slots:
    void pressed(Qt3DRender::QPickEvent *pick);
    void moved(Qt3DRender::QPickEvent *pick);

private:
    Qt3DCore::QEntity*      rootEntity;
    RenderCamera*           camera;
    RenderBase*             renderBase;

    CommandTransformTranslate*      commandTranslate;

    QVector3D           startWorldPosition;
};

#endif // RENDERER_H
