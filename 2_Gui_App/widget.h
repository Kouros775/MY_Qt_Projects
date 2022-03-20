#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QPushButton>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QPushButton* btn;
    QString str;

public slots:
    void slot_btn();
};

#endif // MAINWINDOW_H
