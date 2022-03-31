#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QPropertyAnimation;


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void btnClicked();

private:
    QPropertyAnimation* animation;
};

#endif // WIDGET_H
