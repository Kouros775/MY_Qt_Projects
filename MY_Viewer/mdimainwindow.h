#ifndef MDIMAINWINDOW_H
#define MDIMAINWINDOW_H

#include <QOpenGLWidget>

class MDIMainWindow : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit MDIMainWindow(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MDIMAINWINDOW_H
