#include "square.h"
#include <QPainter>

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*)
{
    if (sqrColor == Brown) painter->setBrush(QColor("#e3e3e3"));
    if (sqrColor == LightBrow) painter->setBrush(QColor("#bdb5b5"));
    painter->setPen(Qt::NoPen);
    painter->drawRect(0, 0, 99, 99);
}

