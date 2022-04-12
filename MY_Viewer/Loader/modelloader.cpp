#include "modelloader.h"
#include <memory>
#include <Qt3DRender/QMesh>

#include "Render/rendermodel.h"



ModelLoader::ModelLoader()
{
}

bool ModelLoader::LoadModel(const QString& path, RenderModel* outRenderModel)
{
    bool bRes = false;

    std::shared_ptr<RenderModel> loadModel = std::shared_ptr<RenderModel>();


    std::shared_ptr<Qt3DRender::QMesh> mesh = std::shared_ptr<Qt3DRender::QMesh>();
    QUrl urlPath;
    urlPath.setPath(path);

    mesh->setSource(urlPath);

    Qt3DRender::QMesh::Status status = mesh->status();

    switch (status)
    {
        case Qt3DRender::QMesh::Status::Loading :
        {
            break;
        }
        case Qt3DRender::QMesh::Status::Ready :
        {
            loadModel->SetMesh(mesh);
            bRes = true;
            break;
        }
        case Qt3DRender::QMesh::Status::Error :
        {
            break;
        }
        case Qt3DRender::QMesh::Status::None :
        {
            break;
        }
    }

    return bRes;
}
