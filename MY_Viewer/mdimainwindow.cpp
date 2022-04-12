#include "mdimainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>

#include "Widget/renderwidget.h"


MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , renderWidget(nullptr)
{
    setWindowTitle(QString::fromUtf8("MY MDI"));


    QMdiArea* area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


    renderWidget = new RenderWidget();


    area->addSubWindow(renderWidget);

    setCentralWidget(area);
}


void MDIMainWindow::AddModel(Qt3DRender::QMesh* paramMesh)
{
    renderWidget->AddModel(paramMesh);
}
