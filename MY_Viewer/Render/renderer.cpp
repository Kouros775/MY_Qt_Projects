#include "renderer.h"
#include <Qt3DRender>
#include <Qt3DExtras>

#include "Render/renderbase.h"
#include "Render/rendercamera.h"
#include "Render/meshmodel.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Renderer
/// \param parent
///
Renderer::Renderer(QObject *parent)
    : QObject(parent)
    , camera(nullptr)
    , rootEntity(nullptr)
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

    //model->objectName()
    paramMesh->parentChanged(model);
    Qt3DCore::QTransform* transform = new Qt3DCore::QTransform(model);
    Qt3DExtras::QPhongMaterial* material = new Qt3DExtras::QPhongMaterial(model);
    QColor color(255, 30, 30);
    material->setDiffuse(color);
    material->setSpecular(color);
    material->setAmbient(color);
    material->setShininess(5.0f);

    Qt3DRender::QObjectPicker* picker = new Qt3DRender::QObjectPicker(model);
    picker->setHoverEnabled(false);
    picker->setEnabled(true);

    model->SetIndex(paramIndex);
    model->SetName(paramMesh->meshName());
    model->addComponent(material);
    model->addComponent(transform);
    model->addComponent(paramMesh);
    model->addComponent(picker);

    QObject::connect(picker, SIGNAL(pressed(Qt3DRender::QPickEvent*)), this, SLOT(PickModel(Qt3DRender::QPickEvent*)));
    // QObject::connect(picker2, &Qt3DRender::QObjectPicker::pressed, this, &MainWindow::onPicked);




    Qt3DRender::QRenderSettings* m_renderSettings = new Qt3DRender::QRenderSettings(model);
        m_renderSettings->pickingSettings()->setPickMethod(Qt3DRender::QPickingSettings::TrianglePicking);
        m_renderSettings->pickingSettings()->setPickResultMode(Qt3DRender::QPickingSettings::NearestPick);

    model->addComponent(m_renderSettings);



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

#include <Qt3DRender/QPickEvent>

void Renderer::PickModel(Qt3DRender::QPickEvent* evt) const
{
    Q_UNUSED(evt);
    MeshModel* entity = qobject_cast<MeshModel*>(sender()->parent());
    //qDebug() << "Picked " << entity->objectName();
    QVector3D pickPos = evt->worldIntersection();
    qDebug() << "PickPos : " << pickPos.x() <<", " <<pickPos.y()<<", " << pickPos.z();
}
