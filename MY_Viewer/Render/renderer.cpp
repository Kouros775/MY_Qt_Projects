#include "renderer.h"
#include <Qt3DExtras>
#include <Qt3DRender>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QCuboidMesh>


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
bool Renderer::AddModel(const int& paramIndex, const QString& paramName, Qt3DRender::QGeometryRenderer* paramMesh)
{
    bool bRes = false;

    MeshModel* model = new MeshModel(rootEntity);
    model->setObjectName(paramName);
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
    QColor color(200, 200, 200);
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
             Qt3DRender::QMaterial* material = model->GetMaterial();
             Qt3DExtras::QPhongMaterial* phongMaterial = dynamic_cast<Qt3DExtras::QPhongMaterial*>(material);

             if(phongMaterial)
             {
                 QColor color(200, 200, 200);
                 phongMaterial->setDiffuse(color);
                 phongMaterial->setSpecular(color);
                 phongMaterial->setAmbient(color);
             }
         }
    }

    MeshModel* model = GetModel(paramIndex);
    if(nullptr != model)
    {
        Qt3DRender::QMaterial* material = model->GetMaterial();
        Qt3DExtras::QPhongMaterial* phongMaterial = dynamic_cast<Qt3DExtras::QPhongMaterial*>(material);

        if(phongMaterial)
        {
            QColor color(100, 100, 100);
            phongMaterial->setDiffuse(color);
            phongMaterial->setSpecular(color);
            phongMaterial->setAmbient(color);
        }
    }
    else
    {

    }

    return bRes;
}

bool Renderer::SetMaterial(const int &paramIndex, const eMaterialType &paramMaterialType)
{
    bool bRes = false;

    MeshModel* meshModel = GetModel(paramIndex);
    if(meshModel)
    {
        Qt3DRender::QMaterial* material = meshModel->GetMaterial();
        material->~QMaterial();

        if(eMaterialType::PhongMaterial == paramMaterialType)
        {
            Qt3DExtras::QPhongMaterial* phongMaterial = new Qt3DExtras::QPhongMaterial(meshModel);
            meshModel->addComponent(phongMaterial);

            QColor color(200, 200, 200);
            phongMaterial->setDiffuse(color);
            phongMaterial->setSpecular(color);
            phongMaterial->setAmbient(color);
            phongMaterial->setShininess(3.0f);
        }
        else if(eMaterialType::GoochMaterial == paramMaterialType)
        {
            Qt3DExtras::QGoochMaterial* goochMaterial = new Qt3DExtras::QGoochMaterial(meshModel);
            meshModel->addComponent(goochMaterial);

            QColor color(200, 200, 200);
            goochMaterial->setDiffuse(color);
            goochMaterial->setSpecular(color);
            goochMaterial->setShininess(3.0f);
        }
        bRes = true;
    }

    return bRes;
}

bool Renderer::SetColor(const int &paramIndex, const QColor &paramColor)
{
    bool bRes = false;

    MeshModel* meshModel = GetModel(paramIndex);
    if(meshModel)
    {
        Qt3DRender::QMaterial* material = meshModel->GetMaterial();

        Qt3DExtras::QPhongMaterial* phongMaterial = dynamic_cast<Qt3DExtras::QPhongMaterial*>(material);
        if(phongMaterial)
        {
            phongMaterial->setDiffuse(paramColor);
            phongMaterial->setSpecular(paramColor);
            phongMaterial->setAmbient(paramColor);
            phongMaterial->setShininess(3.0f);

            bRes = true;
        }
        else
        {

        }
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

        bRes = true;
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

        QVector3D translateVector = transform->translation();

        transform->setTranslation(-translateVector);
        auto q = transform->rotation();
        QMatrix4x4 qM;
        qM.rotate(q);

        transform->setMatrix(rotateMatrix * qM);
        transform->setTranslation(translateVector);
        bRes = true;
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
bool Renderer::Scale(const MeshModel* paramModel, const float& paramDelta)
{
    bool bRes = false;

    if(nullptr != paramModel)
    {
        Qt3DCore::QTransform* transform = paramModel->GetTransform();

        if(paramDelta > 0.0f)
        {
            transform->setScale3D(QVector3D(2.0f, 2.0f, 2.0f));
        }
        else
        {
            transform->setScale3D(QVector3D(-2.0f, -2.0f, -2.0f));
        }

        bRes = true;
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


void Renderer::AddCube(const int& paramIndex, const QVector3D paramExtents)
{
    Qt3DExtras::QCuboidMesh* cubeMesh = new Qt3DExtras::QCuboidMesh(rootEntity);

    cubeMesh->setXExtent(paramExtents.x());
    cubeMesh->setYExtent(paramExtents.y());
    cubeMesh->setZExtent(paramExtents.z());

    this->AddModel(paramIndex, "Cube", cubeMesh);
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
