#ifndef XMARK_H
#define XMARK_H

#include <QGraphicsLineItem>

class XMark : public QGraphicsLineItem
{
public:
    XMark() {}

    QRectF boundingRect() const { return QRectF(0, 0, 100, 100); }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
};

#endif // XMARK_H
