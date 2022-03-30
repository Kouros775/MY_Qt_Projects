#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}


class ImageProcessing;


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void slotChromakey();

private:
    Ui::Widget *ui;

    ImageProcessing* imgProcess;
    QImage sourceQImage;
    QImage targetQImage;
    QImage resultQImage;

    int sourceQImageWidth;
    int sourceQImageHeight;
    int sourceQImageDataSize;
};

#endif // WIDGET_H
