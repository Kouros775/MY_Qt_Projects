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


public slots:
    void RemoveAllModel();
    void AddCube(const int& paramIndex);
    void AddTorus(const int& paramIndex);
    void AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    void RemoveModel(const int& paramIndex);
    void SelectModel(const int& paramIndex);
    void EditModelColor(const int& paramIndex, const QColor& paramColor);
private:
    Renderer* renderer;

    // QWindow interface
protected:
    void wheelEvent(QWheelEvent *) override;
};

#endif // RENDERWINDOW_H
