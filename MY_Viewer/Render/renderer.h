#ifndef RENDERER_H
#define RENDERER_H

#include <QMatrix4x4>
#include <memory>

class CommandTransform;


class Camera;
class RenderBase;
class RenderModel;


class Renderer
{
public:
    explicit Renderer();
    ~Renderer();

    void Init();
    void Paint();
    void Resize(const int& width, const int& height);

    bool AddModel(const uint& paramIndex, const RenderModel& paramModel);

    bool SetTransformMatrix(const uint& paramIndex, const QMatrix4x4& paramMatrix);
    bool GetTransformMatrix(const uint& paramIndex, QMatrix4x4& outMatrix) const;
    bool ApplyTransformMatrix(const uint& paramIndex, const QMatrix4x4& paramMatrix);

    bool IsEmptyModelIndex(const uint& paramIndex) const;

    void GetViewMatrix(QMatrix4x4& outViewMatrix) const ;
    void GetProjectionMatrix(QMatrix4x4& outProjectionMatrix) const;

    bool Translate(const QPoint& startPoint, const QPoint& endPoint, const uint& index);
    bool Rotate(const QPoint& startPoint, const QPoint& endPoint, const uint& index);
    bool Scale(const QPoint& startPoint, const QPoint& endPoint, const uint& index);
    bool RayPicking(const QPoint& point, uint& outPickedIndex) const;

private:
    std::shared_ptr<RenderBase> renderBase;

    std::shared_ptr<CommandTransform> commandTranslate;
    std::shared_ptr<CommandTransform> commandRotate;
    std::shared_ptr<CommandTransform> commandScale;

    QMatrix4x4 projectionMatrix;
    std::shared_ptr<Camera> camera;
};

#endif // RENDERER_H
