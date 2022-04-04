#include "mdimainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QOpenGLWidget>


#include "openglwidget.h"


MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QString::fromUtf8("MY MDI"));

    OpenGLWidget* myOpenGLWidget = new OpenGLWidget();

    QMdiArea* area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    area->addSubWindow(myOpenGLWidget);
    setCentralWidget(area);
}
