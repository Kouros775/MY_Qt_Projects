#include "mainwindow.h"
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QListWidget>
#include <QDockWidget>
#include <mdimainwindow.h>
#include <QApplication>
#include <QFileDialog>



#include <Qt3DRender>


#define IMAGE_PATH_NEW_ACTION ":/images/new.png"
#define IMAGE_PATH_OPEN_ACTION ":/images/open.png"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mdiMainWindow(nullptr)
{
    addButtons();

    QDockWidget* dock = new QDockWidget(tr("Target"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    listWidget = new QListWidget(dock);

    dock->setWidget(listWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock);


    mdiMainWindow = new MDIMainWindow();

    setCentralWidget(mdiMainWindow);

    statusBar()->showMessage(tr("Ready"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::addButtons()
{
    QMenu* fileMenu;
    fileMenu = menuBar()->addMenu(tr("&File"));


    QAction* newAct;
    newAct = new QAction(QIcon(IMAGE_PATH_NEW_ACTION), tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new File"));
    connect(newAct, &QAction::triggered, this, &MainWindow::_newFile);
    fileMenu->addAction(newAct);


    QAction* openAct;
    openAct = new QAction(QIcon(IMAGE_PATH_OPEN_ACTION), tr("Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Load Model File."));
    connect(openAct, &QAction::triggered, this, &MainWindow::loadModel);


    fileMenu->addAction(openAct);



    QToolBar* fileToolBar;
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
}


void MainWindow::_newFile()
{
}


void MainWindow::loadModel()
{
    QString path = QFileDialog::getOpenFileName(nullptr, "파일 선택", "C:\\", "Files(*.*)");

    Qt3DRender::QMesh* loadMesh = new Qt3DRender::QMesh;

    QUrl urlPath = QUrl::fromLocalFile(path);

    loadMesh->setMeshName(path);
    loadMesh->setSource(urlPath);

    listWidget->addItems(QStringList() << loadMesh->meshName());

    mdiMainWindow->AddModel(loadMesh);
}
