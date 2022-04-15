#include "mainwindow.h"
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QListWidget>
#include <QDockWidget>
#include <QFileDialog>
#include <QApplication>
#include <QStandardPaths>
#include <Qt3DRender/QMesh>

#include "Widget/modellistwidgetitem.h"
#include "Widget/renderwidget.h"


#define IMAGE_PATH_NEW_ACTION          "://images/new.png"
#define IMAGE_PATH_OPEN_ACTION          ":/images/open.png"
#define IMAGE_PATH_DELETE_ACTION        "://images/model_delete.png"
#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , renderWidget(nullptr)
    , currentIndex(0)
{
    addWidgets();

    QDockWidget* dock = new QDockWidget(tr("Model List"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    listWidget = new QListWidget(dock);
    connect(listWidget, &QListWidget::itemPressed, this, &MainWindow::itemPressed);
    dock->setWidget(listWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock);


    renderWidget = make_shared<RenderWidget>();
    setCentralWidget(renderWidget.get());
    statusBar()->showMessage(tr("Ready"));
}

MainWindow::~MainWindow()
{

}

void MainWindow::addWidgets()
{
    QMenu* fileMenu;
    fileMenu = menuBar()->addMenu(tr("&File"));

    QAction* newAct;
    newAct = new QAction(QIcon(IMAGE_PATH_NEW_ACTION), tr("New Scene"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("New Scene"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newScene);
    fileMenu->addAction(newAct);

    QAction* openAct;
    openAct = new QAction(QIcon(IMAGE_PATH_OPEN_ACTION), tr("Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Load Model File"));
    connect(openAct, &QAction::triggered, this, &MainWindow::loadModel);
    fileMenu->addAction(openAct);


    QAction* deleteAct;
    deleteAct = new QAction(QIcon(IMAGE_PATH_DELETE_ACTION), tr("&Delete"), this);
    deleteAct->setShortcuts(QKeySequence::Delete);
    deleteAct->setStatusTip(tr("Delete Model File"));
    connect(deleteAct, &QAction::triggered, this, &MainWindow::deleteModel);
    fileMenu->addAction(deleteAct);



    QToolBar* fileToolBar;
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(deleteAct);
}

void MainWindow::newScene()
{
    qDebug() << __FUNCTION__;
}


void MainWindow::loadModel()
{
    QString path = QFileDialog::getOpenFileName(nullptr
                                                , "파일 선택"
                                                , QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
                                                , "stl (*.stl) ;; obj (*.obj) ;; ply (*.ply)");

    Qt3DRender::QMesh* loadMesh = new Qt3DRender::QMesh;

    QUrl urlPath = QUrl::fromLocalFile(path);

    QString meshName = path.section("/", -1);

    loadMesh->setMeshName(meshName);
    loadMesh->setSource(urlPath);

    QString itemText = QString::number(currentIndex) + " : " + meshName;

    ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
    item->SetIndex(currentIndex);
    item->SetName(meshName);

    listWidget->addItem(item);
    renderWidget->AddModel(currentIndex, loadMesh);
    currentIndex++;
}


void MainWindow::deleteModel()
{
    renderWidget->RemoveModel(currentIndex);
    listWidget->takeItem(listWidget->currentRow());
}


void MainWindow::itemPressed(QListWidgetItem *item)
{
    ModelListWidgetItem* modelItem = dynamic_cast<ModelListWidgetItem*>(item);
    currentIndex = modelItem->GetIndex();
}


