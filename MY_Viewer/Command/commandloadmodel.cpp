#include "commandloadmodel.h"
#include <QFileDialog>
#include <QApplication>
#include <QStandardPaths>
#include <Qt3DRender/QMesh>


CommandLoadModel::CommandLoadModel(QObject *parent)
    : ICommand(parent)
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

    emit SignalLoadModel(loadMesh);
}
