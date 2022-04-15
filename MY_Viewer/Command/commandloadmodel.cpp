#include "commandloadmodel.h"
#include <QFileDialog>
#include <QApplication>
#include <QStandardPaths>
#include <Qt3DRender/QMesh>
#include "Widget/modellistwidgetitem.h"


#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"


CommandLoadModel::CommandLoadModel(QObject *parent)
    : ICommand(parent)
    , currentIndex(1)
{

}

CommandLoadModel::~CommandLoadModel()
{

}

void CommandLoadModel::Execute()
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

    QString itemText = QString::number(currentIndex) + " : " + loadMesh->meshName();

    ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
    item->SetIndex(currentIndex);
    item->SetName(loadMesh->meshName());

    listWidget->addItem(item);

    emit AddModel(currentIndex, loadMesh);
    currentIndex++;
}
