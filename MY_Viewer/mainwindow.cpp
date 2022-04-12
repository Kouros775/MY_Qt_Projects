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




#define IMAGE_PATH_NEW_ACTION ":/images/new.png"
#define IMAGE_PATH_OPEN_ACTION ":/images/open.png"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _addButtonAction();

    QDockWidget* dock = new QDockWidget(tr("Target"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    QListWidget* customerList = new QListWidget(dock);
    customerList->addItems(QStringList() << "One" << "Two" << "Three" << "Four" << "Five");

    dock->setWidget(customerList);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    setCentralWidget(new MDIMainWindow());

    statusBar()->showMessage(tr("Ready"));

    // >> Command
    //commandOpenFile = new CommandOpenFile();
    //commandNewScene = new CommandNewScene();
    // << Command
}

MainWindow::~MainWindow()
{

}

void MainWindow::_addButtonAction()
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
    openAct->setStatusTip(tr("Open an existing file."));
    connect(openAct, &QAction::triggered, this, &MainWindow::_open);
    fileMenu->addAction(openAct);



    QToolBar* fileToolBar;
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
}


void MainWindow::_newFile()
{
}


void MainWindow::_open()
{
}
