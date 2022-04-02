#include "mdimainwindow.h"
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QPushButton>

MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QString::fromUtf8("MY MDI"));



    QMdiSubWindow* subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300, 200);
    QPushButton* pushButton = new QPushButton(QString("PushButton"), subWindow1);
    subWindow1->setWidget(pushButton);


    QMdiSubWindow* subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300, 200);

    QMdiArea* area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);
    setCentralWidget(area);
}
