#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsEllipseItem>

class Circle : public QGraphicsEllipseItem
{
public:
    Circle() {}

    QRectF boundingRect() const { return QRectF(0, 0, 100, 100); }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // CIRCLE_H
