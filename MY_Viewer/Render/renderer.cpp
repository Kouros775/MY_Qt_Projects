#include "renderer.h"
#include <Qt3DRender>
#include <Qt3DExtras>
#include <Qt3DCore/QEntity>


#include "Render/renderbase.h"
#include "Render/rendercamera.h"
#include "Render/meshmodel.h"

#include "renderer.h"


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
    renderBase = new RenderBase(this);
    camera = new RenderCamera(this);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::~Renderer
///
Renderer::~Renderer()
{
    qDebug() <<__FUNCTION__;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Initialize
/// \return
///
Qt3DCore::QEntity* Renderer::Initialize(Qt3DRender::QCamera* paramCamera)
{
    rootEntity = renderBase->Initialize();
    initializeLight();



    //Qt3DRender::QDirectionalLight* directionLight = new Qt3DRender::QDirectionalLight(rootEntity);
    //directionLight->setWorldDirection(QVector3D(0.0f, 1.0f, 0.0f));
    //directionLight->setIntensity(10.0f);
    //rootEntity->addComponent(directionLight);


    Qt3DRender::QObjectPicker* picker = new Qt3DRender::QObjectPicker(rootEntity);
    QObject::connect(picker, &Qt3DRender::QObjectPicker::pressed, this, &Renderer::pressed);
    QObject::connect(picker, &Qt3DRender::QObjectPicker::moved, this, &Renderer::moved);
    rootEntity->addComponent(picker);


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
    QColor color(100, 100, 100);
    material->setDiffuse(color);
    material->setSpecular(color);
    material->setAmbient(color);
    material->setShininess(3.0f);
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
bool Renderer::RemoveModel(const int &paramIndex)
{
    bool bRes = false;

    bRes = renderBase->RemoveModel(paramIndex);

    return bRes;
}

bool Renderer::SelectModel(const int &paramIndex)
{
    bool bRes = false;

    QMap<int, MeshModel*>* modelMap = renderBase->GetModelMap();
    QMap<int, MeshModel*>::iterator iter = modelMap->begin();
    for(iter ; iter != modelMap->end() ; iter++)
    {
         MeshModel* model = GetModel(iter.key());

         if(nullptr != model)
         {
             Qt3DExtras::QPhongMaterial* material = model->GetMaterial();
             QColor color(100, 100, 100);
             material->setDiffuse(color);
             material->setSpecular(color);
             material->setAmbient(color);
         }
    }

    MeshModel* model = GetModel(paramIndex);
    if(nullptr != model)
    {
        Qt3DExtras::QPhongMaterial* material = model->GetMaterial();
        QColor color(200, 100, 100);
        material->setDiffuse(color);
        material->setSpecular(color);
        material->setAmbient(color);
    }
    else
    {

    }

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
        //Qt3DCore::QTransform* transform = model->GetTransform();
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
        //Qt3DCore::QTransform* transform = model->GetTransform();
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
        //Qt3DCore::QTransform* transform = model->GetTransform();
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

void Renderer::initializeLight()
{
    float intensity = 0.4f;
    {
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("white");
        light->setIntensity(intensity);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(0, 0, 60.0f));
        lightEntity->addComponent(lightTransform);
    }
    {
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("white");
        light->setIntensity(intensity);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(0, 0, -60.0f));
        lightEntity->addComponent(lightTransform);
    }
    {
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("white");
        light->setIntensity(intensity);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(60, 0, 0.0f));
        lightEntity->addComponent(lightTransform);
    }
    {
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("white");
        light->setIntensity(intensity);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(-60, 0, 0.0f));
        lightEntity->addComponent(lightTransform);
    }
    {
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("white");
        light->setIntensity(intensity);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(0, 60, 0.0f));
        lightEntity->addComponent(lightTransform);
    }
    {
        Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
        Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
        light->setColor("white");
        light->setIntensity(intensity);
        lightEntity->addComponent(light);

        Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
        lightTransform->setTranslation(QVector3D(0, -60, 0.0f));
        lightEntity->addComponent(lightTransform);
    }
    //// << light

}


void Renderer::pressed(Qt3DRender::QPickEvent *pick)
{
    qDebug() <<__FUNCTION__;
}

void Renderer::moved(Qt3DRender::QPickEvent *pick)
{
    qDebug() <<__FUNCTION__;
}
