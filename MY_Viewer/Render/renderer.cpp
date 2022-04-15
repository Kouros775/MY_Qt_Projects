#include "renderer.h"
#include <Qt3DExtras>
#include <Qt3DRender>
#include <Qt3DCore/QEntity>

#include "Command/Transform/commandtransformtranslate.h"
#include "Render/meshmodel.h"
#include "Render/renderbase.h"
#include "Render/rendercamera.h"


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Renderer::Renderer
/// \param parent
///
Renderer::Renderer(QObject *parent)
    : QObject(parent)
    , rootEntity(nullptr)
    , camera(nullptr)
    , renderBase(nullptr)
    , commandTranslate(nullptr)
{
    renderBase = new RenderBase(this);
    camera = new RenderCamera(this);

    commandTranslate = new CommandTransformTranslate(this);
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
    //initializeLight();



    Qt3DRender::QDirectionalLight* directionLight = new Qt3DRender::QDirectionalLight(rootEntity);
    directionLight->setWorldDirection(QVector3D(0.0f, 0.0f, -1.0f));
    //directionLight->setIntensity(10.0f);
    rootEntity->addComponent(directionLight);

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

    // >> Picker
    Qt3DRender::QObjectPicker* picker = new Qt3DRender::QObjectPicker(model);
    picker->setDragEnabled(true);
    QObject::connect(picker, &Qt3DRender::QObjectPicker::pressed, this, &Renderer::pressed);
    QObject::connect(picker, &Qt3DRender::QObjectPicker::moved, this, &Renderer::moved);
    //QObject::connect(picker, &Qt3DRender::QObjectPicker::entered, this, &Renderer::moved);
    model->addComponent(picker);
    // << Picker

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

bool Renderer::Translate(const int &paramIndex, const QVector3D &startPos, const QVector3D &endPos) const
{
    bool bRes = false;

    MeshModel* model = GetModel(paramIndex);
    if(nullptr != model)
    {
        Qt3DCore::QTransform* transform = model->GetTransform();

        QVector3D currentPosition = transform->translation();
        QVector3D moveAmount = endPos - startPos;
        moveAmount.setZ(0.0f);

        transform->setTranslation(currentPosition + moveAmount);
    }
    else
    {

    }

    return bRes;
}

bool Renderer::Rotate(const MeshModel *paramModel, const QVector3D &startPos, const QVector3D &endPos) const
{
    bool bRes = false;

    if(nullptr != paramModel)
    {
        Qt3DCore::QTransform* transform = paramModel->GetTransform();

        QVector3D rotateAxis = QVector3D::crossProduct(startPos, endPos);

        float rotateDegree = 5.0f;

        QMatrix4x4 rotateMatrix;
        rotateMatrix.rotate(rotateDegree, rotateAxis);

        transform->setMatrix(rotateMatrix * transform->matrix());
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


void Renderer::pressed(Qt3DRender::QPickEvent *pick)
{
    QVector3D start = pick->worldIntersection();
    startWorldPosition = start;
}

void Renderer::moved(Qt3DRender::QPickEvent *pick)
{
    QVector3D world = pick->worldIntersection();
    MeshModel* pickModel = qobject_cast<MeshModel*>(sender()->parent());
    int index = pickModel->GetIndex();

    if(Qt3DRender::QPickEvent::Buttons::LeftButton & pick->buttons())
    {
        Translate(index, startWorldPosition, world);
    }
    else if(Qt3DRender::QPickEvent::Buttons::RightButton & pick->buttons())
    {
        Rotate(pickModel, startWorldPosition, world);
    }

    startWorldPosition = world;
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
