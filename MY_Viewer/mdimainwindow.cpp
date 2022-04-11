#include "mdimainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QOpenGLWidget>


#include "openglwidget.h"
#include "Widget/renderwidget.h"

MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QString::fromUtf8("MY MDI"));

    OpenGLWidget* myOpenGLWidget = new OpenGLWidget();

    QMdiArea* area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //area->addSubWindow(myOpenGLWidget);

    RenderWidget* renderWidget = new RenderWidget();

    area->addSubWindow(renderWidget);

    setCentralWidget(area);
}
