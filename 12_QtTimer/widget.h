#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}


class QTimer;


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void _startTimer();
    void _stopTimer();
    void _elapsedTimer();


private:
    Ui::Widget *ui;
    QTimer* m_timer;
};

#endif // WIDGET_H
