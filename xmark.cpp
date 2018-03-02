#include "xmark.h"
#include <QPainter>

void XMark::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(QColor("#231512"), 5, Qt::SolidLine));
    painter->drawLine(5, 5, 90, 90);
    painter->drawLine(5, 90, 90, 5);
}

