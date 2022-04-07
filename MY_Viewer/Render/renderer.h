#ifndef RENDERER_H
#define RENDERER_H

#include <QMatrix4x4>
#include <memory>


class Camera;
class QGLShaderProgram;
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
    bool AddModel(const RenderModel& paramModel, const int& paramIndex);
    bool SetTransformMatrix(const QMatrix4x4& paramMatrix, const int& paramIndex);
    void GetTransformMatrix(QMatrix4x4& outMatrix);
    bool ApplyTransformMatrix(const QMatrix4x4& paramMatrix, const int& paramIndex);
    bool IsEmptyModelIndex(const int& paramIndex);

    void GetViewMatrix(QMatrix4x4& outViewMatrix) const ;
    void GetProjectionMatrix(QMatrix4x4& outProjectionMatrix) const;

    bool Translate(const QPoint& startPoint, const QPoint& endPoint, const int& index);
    bool Rotate(const QPoint& startPoint, const QPoint& endPoint, const int& index);
    bool Scale(const QPoint& startPoint, const QPoint& endPoint, const int& index);

private:
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 transformMatrix;

    std::shared_ptr<QGLShaderProgram> shaderProgram;
    std::shared_ptr<Camera> camera;

    //QVector<QVector3D> vertices;
    const RenderModel* renderModel;

    std::shared_ptr<RenderBase> renderBase;
};

#endif // RENDERER_H
