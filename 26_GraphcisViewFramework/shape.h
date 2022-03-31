#ifndef SHAPE_H
#define SHAPE_H

#include <QGraphicsItem>

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;

class Shape : public QGraphicsItem
{
public:
    Shape();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

protected:
    void advance(int step) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;

private:
    QColor color;
};

#endif // SHAPE_H
