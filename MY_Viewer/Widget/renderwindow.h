#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <Qt3DExtras/Qt3DWindow>


class RenderCamera;


class RenderWindow : public Qt3DExtras::Qt3DWindow
{
public:
    explicit RenderWindow(QScreen *screen = nullptr);
    ~RenderWindow() override;


    void createRootEntry();

    // QWindow interface
protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;


private:
    Qt3DCore::QEntity *m_rootEntity;

    // Camera
    RenderCamera* renderCamera;
    Qt3DCore::QEntity *torusEntity;
};

#endif // RENDERWINDOW_H
