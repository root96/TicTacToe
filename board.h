#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>
#include <QVector>
#include <QPushButton>
#include <QLabel>
#include "square.h"
#include "circle.h"
#include "xmark.h"
#include "line.h"

class Board : public QGraphicsScene
{
    Q_OBJECT
public:
    Board();

    void drawBoard();
    void putSquaresToBoard();

    void removeSquaresFromBoard();
    void clearBoard();

    void drawCircle(const int&, const int&);
    void removeCirlce();

    void drawXMark(const int&, const int&);
    void removeXMark();

    void drawLine(const LineType&, const int&, const int&);
    void removeLine();

    void drawVerticalLine(const int&);
    void drawHorizontalLine(const int&);
    void drawDiagonalLeftLine();
    void drawDiagonalRightLine();

    QPushButton* createButton(const QString&, const char*);
    QPushButton* getStartButton() const { return startButton; }
    QPushButton* getResetButton() const { return resetButton; }
    QLabel* getLabel() const { return label; }

    bool checkWin();
    void setValuesToZero();

    void setImageToLabel(const SquareType&);
    QString composeImagePath(const SquareType&);
    void removeLabel() { label = nullptr; }

    void message(const QString&, const QString&);

private slots:
    void startClicked();
    void resetClicked();
    void squareClicked();

private:
    int horXMark; // poziomy, pionowy
    int verXMark;
    int horOMark;
    int verOMark;
    int diagLXMark;
    int diagRXMark;
    int diagLOMark;
    int diagROMark;
    int counter;
    bool status;
    SquareType mainSquareType;
    Square* squares[3][3];
    QVector<Square*> vecSquares;
    Circle *circle;
    QVector<Circle*> vecCircles;
    XMark *xmark;
    QVector<XMark*> vecXMarks;
    Line *line;
    QVector<Line*> vecLines;
    QLabel *label;
    QPushButton *startButton;
    QPushButton *resetButton;
};

#endif // BOARD_H
