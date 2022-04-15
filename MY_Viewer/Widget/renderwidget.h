#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H


#include <QWidget>
#include <memory>


using namespace std;


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

    void AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh);
    void RemoveModel(const int& paramIndex);
private:
    shared_ptr<RenderWindow> renderWindow;
};

#endif // RENDERWIDGET_H
