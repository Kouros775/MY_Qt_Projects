#include "renderer.h"
#include <Qt3DRender>
#include <Qt3DExtras>

#include "Render/rendermodel.h"
#include "Render/renderbase.h"
#include "Render/rendercamera.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Renderer
/// \param parent
///
Renderer::Renderer(QObject *parent)
    : QObject(parent)
    , renderBase(nullptr)
    , camera(nullptr)
{
    renderBase = std::make_shared<RenderBase>();
    camera = std::make_shared<RenderCamera>();
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
std::shared_ptr<Qt3DCore::QEntity> Renderer::Initialize(Qt3DRender::QCamera* paramCamera)
{
    std::shared_ptr<Qt3DCore::QEntity> rootEntity = renderBase->Initialize();

    camera  = std::make_shared<RenderCamera>();
    camera->Initialize(paramCamera, rootEntity);

    return rootEntity;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::AddModel
/// \param paramIndex
/// \param paramModel
/// \return
///
bool Renderer::AddModel(const int &paramIndex, const RenderModel &paramModel)
{
    bool bRes = false;

    RenderModelInfo* renderModelInfo = new RenderModelInfo();


    std::shared_ptr<Qt3DCore::QTransform> transform = std::make_shared<Qt3DCore::QTransform>();
    transform->setScale3D(QVector3D(1.5, 1, 0.5));
    transform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    // Material
    std::shared_ptr<Qt3DRender::QMaterial> material = std::make_shared<Qt3DExtras::QPhongMaterial>();

    renderModelInfo->material = material;
    renderModelInfo->transform = transform;
    renderModelInfo->mesh = paramModel.GetMesh();

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
