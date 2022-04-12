#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H


#include <QWidget>


class RenderWindow;


class RenderWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = nullptr);
    ~RenderWidget() override;


    QSize sizeHint() const override;


private:
    RenderWindow* renderWindow;
};

#endif // RENDERWIDGET_H
