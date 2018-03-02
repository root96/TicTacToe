#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsItem>
#include <QObject>

enum SquareType { X_Mark, O_Mark, Empty };
enum SquareColor { Brown, LightBrow };

class Square : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
public:
    Square() { col = 0; row = 0; setSquareType(Empty); }
    Square(const SquareColor& sc, const int& c, const int& r) : col(c), row(r), sqrColor(sc) {
        setSquareType(Empty);
    }

    QRectF boundingRect() const { return QRectF(0, 0, 100, 100); }
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);
    void mousePressEvent(QGraphicsSceneMouseEvent*) { emit clicked(); }

    const int& getRow() const { return row; }
    const int& getCol() const { return col; }

    void setSquareType(const SquareType& s) { sqrType = s; }
    const SquareType& getSquareType() const { return sqrType; }

signals:
    void clicked();

private:
    int col;
    int row;
    SquareType sqrType;
    SquareColor sqrColor;
};

#endif // SQUARE_H
