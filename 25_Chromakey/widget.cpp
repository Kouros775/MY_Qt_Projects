#include "widget.h"
#include "ui_widget.h"
#include <imageprocessing.h>
#include <QPixmap>


#define PATH_SOURCE_IMAGE "://images/jana_480p.png"
#define PATH_TARGET_IMAGE "://images/target_480p.png"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
  , imgProcess(nullptr)
{
    ui->setupUi(this);
    connect(ui->pbtChromakey, SIGNAL(clicked()), this, SLOT(slotChromakey()));

    sourceQImage = QImage(PATH_SOURCE_IMAGE);
    targetQImage = QImage(PATH_TARGET_IMAGE);
    resultQImage = QImage(targetQImage.width(),
     targetQImage.height(),
     QImage::Format_RGB32);

    sourceQImageDataSize = targetQImage.width() * targetQImage.height() * 4;

    imgProcess = new ImageProcessing(sourceQImageWidth, sourceQImageHeight, sourceQImageDataSize);
}


Widget::~Widget()
{
    delete ui;
    delete imgProcess;
}

void Widget::slotChromakey()
{
    imgProcess->chromakeyProcess(sourceQImage, targetQImage, resultQImage);

    int width = ui->labelChromakey->width();
    int height = ui->labelChromakey->height();

    QPixmap drawPixmap = QPixmap::fromImage(resultQImage).scaled(width, height);

    ui->labelChromakey->setPixmap(drawPixmap);
}
