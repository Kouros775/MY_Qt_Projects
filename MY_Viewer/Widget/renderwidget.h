#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H


#include <QWidget>


class RenderWindow;
namespace Qt3DRender
{
    class QMesh;
}


class RenderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = nullptr);
    ~RenderWidget() override;

    QSize sizeHint() const override;

    RenderWindow* GetRenderWindow() const {return renderWindow;}


private:
    RenderWindow* renderWindow;
};

#endif // RENDERWIDGET_H
