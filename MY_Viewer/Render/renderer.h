#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>


namespace Qt3DCore
{
    class QEntity;
}
namespace Qt3DRender
{
    class QCamera;
    class QMesh;
}
class RenderCamera;
class RenderBase;


class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr);
    ~Renderer() override;

    Qt3DCore::QEntity *Initialize(Qt3DRender::QCamera* paramCamera);

    bool AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    bool DeleteModel(const int& paramIndex);

private:
    RenderCamera*           camera;
    RenderBase*             renderBase;
};

#endif // RENDERER_H
