#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <memory>


namespace Qt3DCore
{
    class QEntity;
}
namespace Qt3DRender
{
    class QCamera;
}

class RenderCamera;
class RenderModel;
class RenderBase;

class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr);
    ~Renderer() override;

    std::shared_ptr<Qt3DCore::QEntity> Initialize(Qt3DRender::QCamera* paramCamera);

    bool AddModel(const int& paramIndex, const RenderModel& paramModel);
    bool DeleteModel(const int& paramIndex);

private:
    std::shared_ptr<RenderCamera>           camera;
    std::shared_ptr<RenderBase>             renderBase;
};

#endif // RENDERER_H
