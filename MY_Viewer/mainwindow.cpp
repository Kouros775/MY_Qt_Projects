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
#include "Widget/renderwindow.h"


#define IMAGE_PATH_NEW_ACTION          "://images/new.png"
#define IMAGE_PATH_OPEN_ACTION          ":/images/open.png"
#define IMAGE_PATH_DELETE_ACTION        "://images/model_delete.png"
#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"
#define IMAGE_PATH_MODEL_ADD_TORUS      "://images/model_torus.png"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , renderWidget(nullptr)
    , currentIndex(1)
{
    addRenderWidget();
    addToolBarActions();
    addListWidget();
}

MainWindow::~MainWindow()
{
    qDebug() <<__FUNCTION__;
}

void MainWindow::addToolBarActions()
{
    RenderWindow* renderWindow = renderWidget->GetRenderWindow();

    QMenu* fileMenu= menuBar()->addMenu(tr("&File"));

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
    connect(this, &MainWindow::AddModel, renderWindow, &RenderWindow::AddModel);
    fileMenu->addAction(openAct);


    QAction* deleteAct;
    deleteAct = new QAction(QIcon(IMAGE_PATH_DELETE_ACTION), tr("&Delete"), this);
    deleteAct->setShortcuts(QKeySequence::Delete);
    deleteAct->setStatusTip(tr("Delete Model File"));
    connect(deleteAct, &QAction::triggered, this, &MainWindow::deleteModel);
    connect(this, &MainWindow::RemoveModel, renderWindow, &RenderWindow::RemoveModel);
    fileMenu->addAction(deleteAct);

    QToolBar* fileToolBar;
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(deleteAct);

    // >> Model
    QMenu* ModelMenu = menuBar()->addMenu(tr("&Model"));
    QAction* addTorus;
    addTorus = new QAction(QIcon(IMAGE_PATH_MODEL_ADD_TORUS), tr("&Add Torus"), this);
    addTorus->setStatusTip(tr("Add Torus Model"));
    connect(deleteAct, &QAction::triggered, this, &MainWindow::deleteModel);
    ModelMenu->addAction(addTorus);

    // << Model
}

void MainWindow::addListWidget()
{
    RenderWindow* renderWindow = renderWidget->GetRenderWindow();

    QDockWidget* dock = new QDockWidget(tr("Model List"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    listWidget = new QListWidget(dock);
    connect(listWidget, &QListWidget::itemPressed, this, &MainWindow::itemPressed);
    connect(this, &MainWindow::SelectModel, renderWindow, &RenderWindow::SelectModel);
    dock->setWidget(listWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::addRenderWidget()
{
    renderWidget = new RenderWidget(this);
    setCentralWidget(renderWidget);
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

    emit AddModel(currentIndex, loadMesh);
    currentIndex++;
}


void MainWindow::deleteModel()
{
    QListWidgetItem* removeItem = listWidget->takeItem(listWidget->currentRow());

    if(removeItem)
    {
        ModelListWidgetItem* modelItem = dynamic_cast<ModelListWidgetItem*>(removeItem);
        emit RemoveModel(modelItem->GetIndex());
        delete modelItem;
    }
}


void MainWindow::itemPressed(QListWidgetItem *item)
{
    ModelListWidgetItem* modelItem = dynamic_cast<ModelListWidgetItem*>(item);
    emit SelectModel(modelItem->GetIndex());
}

#include <Qt3DExtras/QTorusMesh>
void MainWindow::addTorus()
{
    Qt3DExtras::QTorusMesh* torusMesh = new Qt3DExtras::QTorusMesh();
    torusMesh->setRings(5);
    torusMesh->setRadius(5);
    torusMesh->setSlices(10);
    torusMesh->setMinorRadius(5);


    QString meshName = "torus";

    //torusMesh->setMeshName(meshName);

    QString itemText = QString::number(currentIndex) + " : " + meshName;

    ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
    item->SetIndex(currentIndex);
    item->SetName(meshName);

    listWidget->addItem(item);

    //emit AddModel(currentIndex, torusMesh);
    currentIndex++;
}


