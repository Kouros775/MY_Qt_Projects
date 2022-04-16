#include "commandloadmodel.h"
#include <QFileDialog>
#include <QApplication>
#include <QStandardPaths>
#include <Qt3DRender/QMesh>
#include "Widget/modellistwidgetitem.h"

#include "Document/document.h"


#define IMAGE_PATH_MODEL_WIDGET_ITEM    "://images/model_image.png"


CommandLoadModel::CommandLoadModel(QObject *parent)
    : ICommand(parent)
    , listWidget(nullptr)
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

    if(path.size() > 0)
    {
        Qt3DRender::QMesh* loadMesh = new Qt3DRender::QMesh;

        QUrl urlPath = QUrl::fromLocalFile(path);

        QString meshName = path.section("/", -1);

        loadMesh->setMeshName(meshName);
        loadMesh->setSource(urlPath);

        int addIndex = Document::Instance().GetAddIndex();
        QString itemText = QString::number(addIndex) + " : " + loadMesh->meshName();

        ModelListWidgetItem* item = new ModelListWidgetItem(QIcon(IMAGE_PATH_MODEL_WIDGET_ITEM), itemText);
        item->SetIndex(addIndex);
        item->SetName(loadMesh->meshName());

        listWidget->addItem(item);

        emit AddModel(addIndex, loadMesh);
        Document::Instance().SetAddIndex(addIndex + 1);
        Document::Instance().SetSelectedIndex(addIndex + 1);
    }
}
