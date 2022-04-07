#ifndef RENDERER_H
#define RENDERER_H

#include <QMatrix4x4>
#include <memory>

class CommandTransform;


class RenderModel;
class RenderBase;


class Renderer
{
public:
    explicit Renderer();
    ~Renderer();

    void Init();
    void Paint();
    void Resize(const int& width, const int& height);

    bool AddModel(const int& paramIndex, const RenderModel& paramModel);

    bool SetTransformMatrix(const int& paramIndex, const QMatrix4x4& paramMatrix);
    bool GetTransformMatrix(const int& paramIndex, QMatrix4x4& outMatrix) const;
    bool ApplyTransformMatrix(const int& paramIndex, const QMatrix4x4& paramMatrix);

    bool IsEmptyModelIndex(const int& paramIndex) const;

    void GetViewMatrix(QMatrix4x4& outViewMatrix) const ;
    void GetProjectionMatrix(QMatrix4x4& outProjectionMatrix) const;

    bool Translate(const QPoint& startPoint, const QPoint& endPoint, const int& index);
    bool Rotate(const QPoint& startPoint, const QPoint& endPoint, const int& index);
    bool Scale(const QPoint& startPoint, const QPoint& endPoint, const int& index);

private:
    std::shared_ptr<RenderBase> renderBase;

    std::shared_ptr<CommandTransform> commandTranslate;
    std::shared_ptr<CommandTransform> commandRotate;
    std::shared_ptr<CommandTransform> commandScale;
};

#endif // RENDERER_H
