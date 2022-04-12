#ifndef MDIMAINWINDOW_H
#define MDIMAINWINDOW_H

#include <QMainWindow>


class RenderWidget;
namespace Qt3DRender
{
    class QMesh;
}

class MDIMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MDIMainWindow(QWidget *parent = nullptr);

    void AddModel(Qt3DRender::QMesh* paramMesh);

private:
    RenderWidget* renderWidget;
};

#endif // MDIMAINWINDOW_H
