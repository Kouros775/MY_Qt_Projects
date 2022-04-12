#include "renderer.h"
#include <Qt3DRender>
#include <Qt3DExtras>

#include "Render/renderbase.h"
#include "Render/rendercamera.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Renderer
/// \param parent
///
Renderer::Renderer(QObject *parent)
    : QObject(parent)
    , camera(nullptr)
    , renderBase(nullptr)
{
    renderBase = new RenderBase();
    camera = new RenderCamera();
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::~Renderer
///
Renderer::~Renderer()
{

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Initialize
/// \return
///
Qt3DCore::QEntity* Renderer::Initialize(Qt3DRender::QCamera* paramCamera)
{
    Qt3DCore::QEntity* rootEntity = renderBase->Initialize();

    camera  = new RenderCamera();
    camera->Initialize(paramCamera, rootEntity);

    return rootEntity;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::AddModel
/// \param paramIndex
/// \param paramMesh
/// \return
///
bool Renderer::AddModel(const int& paramIndex, Qt3DRender::QMesh* paramMesh)
{
    bool bRes = false;

    RenderModelInfo* renderModelInfo = new RenderModelInfo();


    Qt3DCore::QTransform* transform = new Qt3DCore::QTransform();
    transform->setScale3D(QVector3D(1.5, 1, 0.5));
    transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    // Material
    Qt3DRender::QMaterial* material = new Qt3DExtras::QPhongMaterial();


    renderModelInfo->material = material;
    renderModelInfo->transform = transform;
    renderModelInfo->mesh = paramMesh;

    bRes = renderBase->AddModel(paramIndex, renderModelInfo);


    return bRes;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::DeleteModel
/// \param paramIndex
/// \return
///
bool Renderer::DeleteModel(const int &paramIndex)
{
    bool bRes = false;

    Q_UNUSED(paramIndex);

    return bRes;
}
