#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}
class QFile;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void _savePriceInformation();
    void _readPriceInformation();

private:
    Ui::Widget *ui;
    QFile* _pFile;
};

#endif // WIDGET_H
