#include "mainwindow.h"
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QListWidget>
#include <QDockWidget>

#include <Qt3DRender/QMesh>

#include "Command/commandremovemodel.h"
#include "Command/commandloadmodel.h"

#include "Widget/modellistwidgetitem.h"
#include "Widget/renderwidget.h"
#include "Widget/renderwindow.h"


#define IMAGE_PATH_NEW_ACTION          "://images/new.png"
#define IMAGE_PATH_OPEN_ACTION          ":/images/open.png"
#define IMAGE_PATH_DELETE_ACTION        "://images/model_delete.png"

#define IMAGE_PATH_MODEL_ADD_TORUS      "://images/model_torus.png"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , renderWidget(nullptr)
    , commandLoadModel(nullptr)
    , commandRemoveModel(nullptr)
{
    addRenderWidget();
    addListWidget();
    addCommands();
    addToolBarActions();
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
    fileMenu->addAction(newAct);

    QAction* openAct;
    openAct = new QAction(QIcon(IMAGE_PATH_OPEN_ACTION), tr("Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Load Model File"));
    connect(openAct, &QAction::triggered, commandLoadModel, &CommandLoadModel::Execute);
    connect(commandLoadModel, &CommandLoadModel::AddModel, renderWindow, &RenderWindow::AddModel);
    fileMenu->addAction(openAct);


    QAction* deleteAct;
    deleteAct = new QAction(QIcon(IMAGE_PATH_DELETE_ACTION), tr("&Delete"), this);
    deleteAct->setShortcuts(QKeySequence::Delete);
    deleteAct->setStatusTip(tr("Delete Model File"));
    connect(deleteAct, &QAction::triggered, commandRemoveModel, &CommandRemoveModel::Execute);
    connect(commandRemoveModel, &CommandRemoveModel::RemoveModel, renderWindow, &RenderWindow::RemoveModel);
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
    //connect(deleteAct, &QAction::triggered, this, &MainWindow::deleteModel);
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


void MainWindow::itemPressed(QListWidgetItem *item)
{
    ModelListWidgetItem* modelItem = dynamic_cast<ModelListWidgetItem*>(item);
    emit SelectModel(modelItem->GetIndex());
}


void MainWindow::addCommands()
{
    commandLoadModel = new CommandLoadModel(this);
    commandRemoveModel = new CommandRemoveModel(this);

    commandLoadModel->SetListWidget(listWidget);
    commandRemoveModel->SetListWidget(listWidget);
}


