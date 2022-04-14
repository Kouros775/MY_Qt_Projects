#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>

#define SAFE_DELETE(x)			if(x){delete x;x=nullptr;}
#define SAFE_DELETE_ARRAY(x)	if(x){delete[] x;x=nullptr;}


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

class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr);
    ~Renderer() override;

    Qt3DCore::QEntity *Initialize(Qt3DRender::QCamera* paramCamera);

    bool AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    bool RemoveModel(const int& paramIndex);

    bool Translate(const int& paramIndex, const QPoint& startPoint, const QPoint& endPoint);
    bool Rotate(const int& paramIndex, const QPoint& startPoint, const QPoint& endPoint);
    bool Scale(const int& paramIndex, const QPoint& startPoint, const QPoint& endPoint);

    MeshModel* GetModel(const int& paramIndex) const;

private:
    void initializeLight();


private slots:
    void pressed(Qt3DRender::QPickEvent *pick);
    void moved(Qt3DRender::QPickEvent *pick);

private:
    Qt3DCore::QEntity*      rootEntity;
    RenderCamera*           camera;
    RenderBase*             renderBase;
};

#endif // RENDERER_H
