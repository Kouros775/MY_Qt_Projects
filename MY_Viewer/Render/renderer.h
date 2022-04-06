#ifndef RENDERER_H
#define RENDERER_H

#include <QMatrix4x4>
#include <memory>


class Camera;
class QGLShaderProgram;


class Renderer
{
public:
    Renderer();

    void Init();
    void Paint();
    void Resize(const int& width, const int& height);

private:
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 viewMatrix;
    QMatrix4x4 transformMatrix;

    std::shared_ptr<QGLShaderProgram> shaderProgram;
    std::shared_ptr<Camera> camera;

     QVector<QVector3D> vertices;
};

#endif // RENDERER_H
