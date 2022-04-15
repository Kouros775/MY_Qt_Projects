#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <Qt3DExtras/Qt3DWindow>
#include <QObject>

class Renderer;
namespace Qt3DRender
{
    class QMesh;
}


class RenderWindow : public Qt3DExtras::Qt3DWindow
{
    Q_OBJECT
public:
    explicit RenderWindow(QScreen *screen = nullptr);
    ~RenderWindow() override;

    void Initialize();


    // QWindow interface
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;


public slots:
    void AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    void RemoveModel(const int& paramIndex);
    void SelectModel(const int& paramIndex);
private:
    Renderer* renderer;
};

#endif // RENDERWINDOW_H
