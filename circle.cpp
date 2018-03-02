#include "circle.h"
#include <QPainter>

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setPen(QPen(QColor("#231512"), 5, Qt::SolidLine));
    painter->drawEllipse(5, 5, 90, 90);
}
