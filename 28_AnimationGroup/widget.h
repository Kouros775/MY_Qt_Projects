#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


class QPropertyAnimation;
class QSequentialAnimationGroup;
class QParallelAnimationGroup;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void btn_clicked();

private:
    QPropertyAnimation* anim1;
    QPropertyAnimation* anim2;
    //QSequentialAnimationGroup* sGroup;
    QParallelAnimationGroup* pGroup;
};

#endif // WIDGET_H
