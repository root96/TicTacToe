#include "line.h"
#include <QPainter>

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(QColor("#673400"), 10, Qt::SolidLine));
    if (lineType == Vertically) painter->drawLine(0, 50, 100, 50);
    if (lineType == Horizontal) painter->drawLine(50, 0, 50, 100);
    if (lineType == DiagonalLeft) painter->drawLine(0, 0, 100, 100);
    if (lineType == DiagonalRight) painter->drawLine(0, 100, 100, 0);
}
