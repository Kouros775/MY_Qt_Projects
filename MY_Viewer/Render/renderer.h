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
}


class RenderCamera;
class RenderBase;
class MeshModel;
class CommandTransformTranslate;


class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr);
    ~Renderer() override;

    Qt3DCore::QEntity *Initialize(Qt3DRender::QCamera* paramCamera);

    bool AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    bool RemoveModel(const int& paramIndex);
    bool SelectModel(const int& paramIndex);

    bool Translate(const int& paramIndex, const QVector3D& startPos, const QVector3D& endPos) const;
    bool Rotate(const MeshModel* paramModel, const QVector3D& startPos, const QVector3D& endPos) const;
    bool Scale(const int& paramIndex, const QPoint& startPoint, const QPoint& endPoint);

    MeshModel* GetModel(const int& paramIndex) const;

private slots:
    void pressed(Qt3DRender::QPickEvent *pick);
    void moved(Qt3DRender::QPickEvent *pick);
private:
    void initializeLight();

private:
    Qt3DCore::QEntity*      rootEntity;
    RenderCamera*           camera;
    RenderBase*             renderBase;

    CommandTransformTranslate*      commandTranslate;

    QVector3D           startWorldPosition;
};

#endif // RENDERER_H
