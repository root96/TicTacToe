#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>

enum LineType { Vertically, Horizontal, DiagonalLeft, DiagonalRight };

class Line : public QGraphicsLineItem
{
public:
    explicit Line(const LineType& l) : lineType(l) {}

    QRectF boundingRect() const { return QRectF(0,0,100,100); }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

private:
    LineType lineType;
};

#endif // LINE_H
