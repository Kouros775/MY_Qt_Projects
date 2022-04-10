#ifndef RENDERBASE_H
#define RENDERBASE_H


#include <memory>
#include <QMap>
#include <QMatrix4x4>


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
    void Paint(const QMatrix4x4& viewMatrix, const QMatrix4x4& projMatrix) const;
    void Resize(const int& width, const int& height);
    bool AddModel(const uint& paramIndex, const RenderModel& paramModel);
    bool SetTransformMatrix(const uint& paramIndex, const QMatrix4x4& paramMatrix);
    bool GetTransformMatrix(const uint& paramIndex, QMatrix4x4& outMatrix) const;
    bool ApplyTransformMatrix(const uint& paramIndex, const QMatrix4x4& paramMatrix);
    bool IsEmptyModelIndex(const uint& paramIndex) const;
    bool RayPicking(const QPoint& point, uint& outPickedIndex) const;

private:
    QMap<uint, RenderObjectInfo> renderMap;
    std::shared_ptr<QGLShaderProgram> shaderProgram;
};

#endif // RENDERBASE_H
