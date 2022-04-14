#include "mainwindow.h"
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QListWidget>
#include <QDockWidget>
#include <QApplication>
#include <QFileDialog>
#include <Qt3DRender>


#include "Document/modeldocument.h"
#include "Widget/modellistwidgetitem.h"

#include "mdimainwindow.h"


#define IMAGE_PATH_OPEN_ACTION          ":/images/open.png"
#define IMAGE_PATH_DELETE_ACTION        "://images/model_delete.png"
#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mdiMainWindow(nullptr)
{
    addButtons();

    QDockWidget* dock = new QDockWidget(tr("Model List"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    listWidget = new QListWidget(dock);
    connect(listWidget, &QListWidget::itemPressed, this, &MainWindow::itemPressed);
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





    QAction* openAct;
    openAct = new QAction(QIcon(IMAGE_PATH_OPEN_ACTION), tr("Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Load Model File."));
    connect(openAct, &QAction::triggered, this, &MainWindow::loadModel);
    fileMenu->addAction(openAct);


    QAction* newAct;
    newAct = new QAction(QIcon(IMAGE_PATH_DELETE_ACTION), tr("&Delete"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Delete Model File."));
    connect(newAct, &QAction::triggered, this, &MainWindow::deleteModel);
    fileMenu->addAction(newAct);



    QToolBar* fileToolBar;
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
}


void MainWindow::loadModel()
{
    QString path = QFileDialog::getOpenFileName(nullptr
                                                , "파일 선택"
                                                , QStandardPaths::writableLocation(QStandardPaths::DesktopLocation)
                                                , "Files(*.*)");

    Qt3DRender::QMesh* loadMesh = new Qt3DRender::QMesh;

    QUrl urlPath = QUrl::fromLocalFile(path);

    QString meshName = path.section("/", -1);

    loadMesh->setMeshName(meshName);
    loadMesh->setSource(urlPath);

    ModelDocument& modelDocument = ModelDocument::Instance();
    int index = modelDocument.AddModel(loadMesh);
    modelDocument.SetSelectedIndex(index);


    QString itemText = QString::number(index) + " : " + meshName;

    ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
    item->SetIndex(index);
    item->SetName(meshName);

    listWidget->addItem(item);
    mdiMainWindow->AddModel(index, loadMesh);
}


void MainWindow::deleteModel()
{
    ModelDocument& modelDocument = ModelDocument::Instance();
    int selectedIndex = modelDocument.GetSelectedIndex();
    modelDocument.SetSelectedIndex(0);
}


void MainWindow::itemPressed(QListWidgetItem *item)
{
    ModelListWidgetItem* modelItem = dynamic_cast<ModelListWidgetItem*>(item);

    ModelDocument& modelDocument = ModelDocument::Instance();
    modelDocument.SetSelectedIndex(modelItem->GetIndex());
    qDebug() << modelItem->GetIndex() <<" : " << modelItem->GetName();
}


