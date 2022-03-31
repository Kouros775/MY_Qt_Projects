#include "shape.h"
#include <QDebug>
#include <QPainter>
#include <QStyleOption>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsSceneMouseEvent>
#include <QStyleOptionGraphicsItem>


Shape::Shape()
{
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    color = QColor(QRandomGenerator::global()->bounded(256),
                   QRandomGenerator::global()->bounded(256),
                   QRandomGenerator::global()->bounded(256)
                   );
}

// QGraphicsScene 내부에서 사용되는 함수.
// 이 아이템의 시작점 x,y,width, height 넘겨줌
QRectF Shape::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

// 출돌을 감지하는 함수.
// 충돌이 감지되는 영역을 지정하면 된다.
// QGraphicsScene 내에서등록된 아이템이 충돌이 일어나면 이 함수에 의해 등록된 영역을
// 감지해 충돌을 감지해준다.
QPainterPath Shape::shape() const
{
    QPainterPath path;
    path.addRect(0, 0, 50, 50);
    return path;
}

// QGrapihcsItem영역에 원하는 요소를 드로잉할 수 있다.
void Shape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(scene()->collidingItems(this).isEmpty())
    {
        painter->setBrush(color);
    }
    else
    {
        painter->setBrush(QColor(Qt::red));
    }

    painter->drawRect(0, 0, 50, 50);
}

// 타이머가 호출되면 이 함수가 자동으로 호출됨.
void Shape::advance(int step)
{
    if(!step)
        return;
    update();
}

// QGraphicsScene 내에서 특정 QGraphicsItem을 마우스로 드래고하기 위한 기능을 제공.
void Shape::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF eventPos = event->pos();
    QPointF shapePos = this->pos();

    QPointF wPos(eventPos.x() + shapePos.x() - 25,
            eventPos.y() + shapePos.y() - 25);

    setPos(wPos);
    update();

    QGraphicsItem::mouseMoveEvent(event);
}
