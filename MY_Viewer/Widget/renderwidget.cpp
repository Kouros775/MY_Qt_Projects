#include "renderwidget.h"
#include <QLayout>

#include "Render/rendercamera.h"


RenderWidget::RenderWidget(QWidget *parent)
    : QWidget(parent)
{
    m_view = new Qt3DExtras::Qt3DWindow();
    m_view->defaultFrameGraph()->setClearColor(QColor(77, 77, 77));

    m_rootEntity = new Qt3DCore::QEntity;
    m_view->setRootEntity(m_rootEntity);


    // Camera
    camera = new RenderCamera();
    camera->Initialize(m_view->camera(), m_rootEntity);




    QWidget *container = QWidget::createWindowContainer(m_view);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(container);

    setLayout(layout);


    createRootEntry();
}

RenderWidget::~RenderWidget()
{

}

void RenderWidget::createRootEntry()
{
    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial();

    // Torus
    Qt3DCore::QEntity *torusEntity = new Qt3DCore::QEntity(m_rootEntity);
    Qt3DExtras::QTorusMesh *torusMesh = new Qt3DExtras::QTorusMesh;
    torusMesh->setRadius(5);
    torusMesh->setMinorRadius(1);
    torusMesh->setRings(100);
    torusMesh->setSlices(20);

    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform;
    torusTransform->setScale3D(QVector3D(1.5, 1, 0.5));
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1, 0, 0), 45.0f));

    torusEntity->addComponent(torusMesh);
    torusEntity->addComponent(torusTransform);
    torusEntity->addComponent(material);



    Qt3DExtras::QExtrudedTextMesh *urlTextMesh
                    = new Qt3DExtras::QExtrudedTextMesh();

    urlTextMesh->setText("www.qt-dev.com");

    Qt3DExtras::QPhongMaterial *urlTextMaterial
                    = new Qt3DExtras::QPhongMaterial();

    urlTextMaterial->setDiffuse(QColor(Qt::green));

    Qt3DCore::QTransform *urlTextTransform = new Qt3DCore::QTransform();
    urlTextTransform->setScale(2.0f);
    urlTextTransform->setTranslation(QVector3D(-10.0f, -4.0f, 15.0f));

    m_textEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_textEntity->addComponent(urlTextMesh);
    m_textEntity->addComponent(urlTextMaterial);
    m_textEntity->addComponent(urlTextTransform);

}

QSize RenderWidget::sizeHint() const
{
    return QSize(1024,800);
}
