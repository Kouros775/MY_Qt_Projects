#ifndef RENDERBASE_H
#define RENDERBASE_H


#include <memory>
#include <QMap>
#include <QMatrix4x4>


class Camera;
class RenderModel;
class QGLShaderProgram;


class RenderBase
{
    struct RenderObjectInfo
    {
        QMatrix4x4 transformMatrix;
        std::shared_ptr<RenderModel> renderModel;
    };

public:
    explicit RenderBase();
    ~RenderBase();

    void Init();
    void Paint();
    void Resize(const int& width, const int& height);
    bool AddModel(const RenderModel& paramModel, const int& paramIndex);
    bool SetTransformMatrix(const QMatrix4x4& paramMatrix, const int& paramIndex);
    bool GetTransformMatrix(const int& paramIndex, QMatrix4x4& outMatrix) const;
    bool ApplyTransformMatrix(const int& paramIndex, const QMatrix4x4& paramMatrix);
    bool IsEmptyModelIndex(const int& paramIndex) const;

    void GetViewMatrix(QMatrix4x4& outViewMatrix) const ;
    void GetProjectionMatrix(QMatrix4x4& outProjectionMatrix) const;

private:
    QMap<int, RenderObjectInfo> renderMap;

    QMatrix4x4 projectionMatrix;

    std::shared_ptr<QGLShaderProgram> shaderProgram;
    std::shared_ptr<Camera> camera;
};

#endif // RENDERBASE_H
