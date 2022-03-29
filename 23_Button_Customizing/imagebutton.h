#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include <QWidget>


class QEvent;
class QPaintEvent;
class QMouseEvent;


class ImageButton : public QWidget
{
    enum class E_BEHAVIOUR_STATE
    {
        NORMAL,
        ENTER,
        LEAVE,
        PRESS,
        RELEASE,
        DISABLE
    };

    Q_OBJECT
public:
    explicit ImageButton(QWidget *parent = nullptr);
    void setDisabled(bool val);


protected:
    virtual void paintEvent(QPaintEvent* event) override;
    virtual void enterEvent(QEvent* event) override;
    virtual void leaveEvent(QEvent* event) override;
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;

signals:
    void clicked();

private:
    QString imgFileName;
    E_BEHAVIOUR_STATE behaviour;
    bool disabled;
};

#endif // IMAGEBUTTON_H
