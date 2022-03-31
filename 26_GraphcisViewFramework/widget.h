#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>


namespace Ui {
class Widget;
}

class QGraphicsScene;
class Shape;


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void timerStart();

private:
    Ui::Widget *ui;
    QGraphicsScene* m_scene;
    Shape* m_shape[5];
    QTimer m_timer;
};

#endif // WIDGET_H
