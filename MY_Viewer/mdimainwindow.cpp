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


    renderWidget = std::make_shared<RenderWidget>();


    area->addSubWindow(renderWidget.get());

    setCentralWidget(area);
}


void MDIMainWindow::AddModel(const RenderModel *paramModel)
{

}
