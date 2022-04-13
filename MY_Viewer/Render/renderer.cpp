#include "renderer.h"
#include <Qt3DRender>
#include <Qt3DExtras>
#include <Qt3DCore/QEntity>

#include "Render/renderbase.h"
#include "Render/rendercamera.h"
#include "Render/meshmodel.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Renderer
/// \param parent
///
Renderer::Renderer(QObject *parent)
    : QObject(parent)
    , rootEntity(nullptr)
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
    SAFE_DELETE(renderBase);
    SAFE_DELETE(camera);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Initialize
/// \return
///
Qt3DCore::QEntity* Renderer::Initialize(Qt3DRender::QCamera* paramCamera)
{
    rootEntity = renderBase->Initialize();

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

    MeshModel* model = new MeshModel(rootEntity);
    model->setObjectName(paramMesh->meshName());
    model->SetIndex(paramIndex);

    // >> mesh
    paramMesh->parentChanged(model);
    model->addComponent(paramMesh);
    // << mesh

    // >> transform
    Qt3DCore::QTransform* transform = new Qt3DCore::QTransform(model);
    model->addComponent(transform);
    // << transform

    // >> material
    Qt3DExtras::QPhongMaterial* material = new Qt3DExtras::QPhongMaterial(model);
    QColor color(255, 30, 30);
    material->setDiffuse(color);
    material->setSpecular(color);
    material->setAmbient(color);
    material->setShininess(5.0f);
    model->addComponent(material);
    // << material

    bRes = renderBase->AddModel(paramIndex, model);


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


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Translate
/// \param paramIndex
/// \param startPoint
/// \param endPoint
/// \return
///
bool Renderer::Translate(const int &paramIndex, const QPoint& startPoint, const QPoint& endPoint)
{
    bool bRes = false;

    MeshModel* model = GetModel(paramIndex);
    if(nullptr != model)
    {
        Qt3DCore::QTransform* transform = model->GetTransform();
        //transform->set

        QVector3D startPos(startPoint);
    }
    else
    {

    }

    return bRes;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Rotate
/// \param paramIndex
/// \param startPoint
/// \param endPoint
/// \return
///
bool Renderer::Rotate(const int& paramIndex, const QPoint& startPoint, const QPoint& endPoint)
{
    bool bRes = false;

    MeshModel* model = GetModel(paramIndex);
    if(nullptr != model)
    {
        Qt3DCore::QTransform* transform = model->GetTransform();
        QVector3D pos;
        pos.toPoint()
        //transform->set
    }
    else
    {

    }

    return bRes;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Scale
/// \param paramIndex
/// \param startPoint
/// \param endPoint
/// \return
///
bool Renderer::Scale(const int& paramIndex, const QPoint& startPoint, const QPoint& endPoint)
{
    bool bRes = false;

    MeshModel* model = GetModel(paramIndex);
    if(nullptr != model)
    {
        Qt3DCore::QTransform* transform = model->GetTransform();
        //transform->set
    }
    else
    {

    }

    return bRes;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::GetModel
/// \param paramIndex
/// \return
///
MeshModel *Renderer::GetModel(const int &paramIndex) const
{
    return renderBase->GetModel(paramIndex);
}
