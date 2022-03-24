#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Person;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void pushButtonChange();

private slots:
    void _changeName(const QString& name);

private:
    Ui::Widget *ui;
    Person* person;
};

#endif // WIDGET_H
