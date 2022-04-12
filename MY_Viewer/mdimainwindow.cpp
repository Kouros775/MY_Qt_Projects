#include "mdimainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>

#include "Widget/renderwidget.h"


MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QString::fromUtf8("MY MDI"));


    QMdiArea* area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    RenderWidget* renderWidget = new RenderWidget();
    area->addSubWindow(renderWidget);

    setCentralWidget(area);
}
