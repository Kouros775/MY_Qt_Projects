#include "widget.h"
#include "ui_widget.h"
#include <shape.h>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <math.h>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene(this);

    for (int i = 0; i < 5; ++i) {
        m_shape[i] = new Shape;
        m_shape[i]->setPos(::sin((i * 6.28) / 5) * 100,
                      ::cos((i * 6.28) / 5) * 100);
        m_scene->addItem(m_shape[i]);
    }

    ui->graphicsView->setScene(m_scene);

    QObject::connect(&m_timer, SIGNAL(timeout()), m_scene, SLOT(advance()));

    timerStart();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::timerStart()
{
    m_timer.start(30);
}
