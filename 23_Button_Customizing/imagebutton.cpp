#include "imagebutton.h"
#include <QPainter>
#include <QMouseEvent>
#include <QImage>


#define PATH_FILE_NORMAL   "://resource/normal.png"
#define PATH_FILE_DISABLE  "://resource/disable.png"
#define PATH_FILE_ENTER    "://resource/enter.png"
#define PATH_FILE_PRESS    "://resource/press.png"


ImageButton::ImageButton(QWidget *parent)
    : QWidget(parent)
    , behaviour(E_BEHAVIOUR_STATE::NORMAL)
    , disabled(false)
{
    QImage image(PATH_FILE_NORMAL);
    this->setFixedWidth(image.width());
    this->setFixedHeight(image.height());
}

void ImageButton::setDisabled(bool val)
{
    disabled = val;
    update();
}

void ImageButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter;

    painter.begin(this);

    if(disabled == true)
    {
        imgFileName = PATH_FILE_DISABLE;
    }
    else
    {
        switch (behaviour)
        {
            case E_BEHAVIOUR_STATE::NORMAL:
            {
                imgFileName = PATH_FILE_NORMAL;
                break;
            }
            case E_BEHAVIOUR_STATE::ENTER:
            {
                imgFileName = PATH_FILE_ENTER;
                break;
            }
            case E_BEHAVIOUR_STATE::LEAVE:
            {
                imgFileName = PATH_FILE_NORMAL;
                break;
            }
            case E_BEHAVIOUR_STATE::PRESS:
            {
                imgFileName = PATH_FILE_PRESS;
                break;
            }
        }
    }

    QImage image(imgFileName);

    painter.drawImage(0, 0, image);
    painter.end();
}

void ImageButton::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->behaviour = E_BEHAVIOUR_STATE::ENTER;
    update();
}


void ImageButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->behaviour = E_BEHAVIOUR_STATE::NORMAL;
    update();
}


void ImageButton::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    this->behaviour = E_BEHAVIOUR_STATE::PRESS;
    update();

    emit clicked();
}


void ImageButton::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    this->behaviour = E_BEHAVIOUR_STATE::ENTER;
    update();
}


void ImageButton::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
}
