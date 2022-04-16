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

#include "Command/commandloadmodel.h"
#include "Command/commandremovemodel.h"
#include "Command/commandeditmodelcolor.h"
#include "Command/commandselectlistwidgetitem.h"
#include "Widget/renderwidget.h"
#include "Widget/renderwindow.h"
#include "Widget/modellistwidgetitem.h"


#define IMAGE_PATH_NEW_ACTION          "://images/new.png"
#define IMAGE_PATH_OPEN_ACTION          ":/images/open.png"
#define IMAGE_PATH_DELETE_ACTION        "://images/model_delete.png"

#define IMAGE_PATH_MODEL_ADD_TORUS      "://images/model_torus.png"

#define IMAGE_PATH_EDIT_MODEL_COLOR      "://images/edit_model_color.png"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , renderWidget(nullptr)
    , commandLoadModel(nullptr)
    , commandRemoveModel(nullptr)
    , commandSelectWidgetItem(nullptr)
    , commandEditModelColor(nullptr)
{
    addRenderWidget();
    addListWidget();
    addCommands();
    addToolBarActions();

    RenderWindow* renderWindow = renderWidget->GetRenderWindow();
    connect(listWidget, &QListWidget::itemPressed, commandSelectWidgetItem, &CommandSelectListWidgetItem::ItemPressed);
    connect(commandSelectWidgetItem, &CommandSelectListWidgetItem::SelectModel, renderWindow, &RenderWindow::SelectModel);
}


MainWindow::~MainWindow()
{
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


    // >> Edit Model
    QMenu* editModelMenu = menuBar()->addMenu(tr("&Edit"));
    QAction* editModelColor = new QAction(QIcon(IMAGE_PATH_EDIT_MODEL_COLOR), tr("&Edit Color"), this);
    editModelColor->setStatusTip(tr("Edit Model Color."));
    editModelMenu->addAction(editModelColor);
    connect(editModelColor, &QAction::triggered, commandEditModelColor, &CommandEditModelColor::Execute);
    connect(commandEditModelColor, &CommandEditModelColor::EditModelColor, renderWindow, &RenderWindow::EditModelColor);
    fileToolBar->addAction(editModelColor);
}

void MainWindow::addListWidget()
{
    QDockWidget* dock = new QDockWidget(tr("Model List"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    listWidget = new QListWidget(dock);
    dock->setWidget(listWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::addRenderWidget()
{
    renderWidget = new RenderWidget(this);
    setCentralWidget(renderWidget);
}


void MainWindow::addCommands()
{
    commandSelectWidgetItem = new CommandSelectListWidgetItem(this);
    commandLoadModel = new CommandLoadModel(this);
    commandRemoveModel = new CommandRemoveModel(this);
    commandEditModelColor = new CommandEditModelColor(this);

    commandLoadModel->SetListWidget(listWidget);
    commandRemoveModel->SetListWidget(listWidget);
}


