#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <Qt3DExtras/Qt3DWindow>
#include <memory>


class Renderer;
namespace Qt3DRender
{
    class QMesh;
}



class RenderWindow : public Qt3DExtras::Qt3DWindow
{
public:
    explicit RenderWindow(QScreen *screen = nullptr);
    ~RenderWindow() override;

    void Initialize();

    void AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    void RemoveModel(const int& paramIndex);

    // QWindow interface
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;


private:
    std::shared_ptr<Renderer> renderer;
};

#endif // RENDERWINDOW_H
