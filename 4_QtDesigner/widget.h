#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

private slots:
    void slider1_valueChanged(int val);
    void slider2_valueChanged(int val);
    void slider3_valueChanged(int val);
};

#endif // WIDGET_H
