#include "board.h"
#include <QDebug>
#include <QMessageBox>

Board::Board()
{
    drawBoard();
    putSquaresToBoard();

    label = new QLabel();
    setImageToLabel(Empty);
    startButton = createButton(tr("START"), SLOT(startClicked()));
    resetButton = createButton(tr("RESET"), SLOT(resetClicked()));

    counter = 0;
    status = false;
    mainSquareType = Empty;
}

void Board::drawBoard()
{
    this->addRect(-50, -50, 400, 400, QPen(Qt::NoPen), QBrush(QColor("#6f6f6f")));
    this->addRect(-20, -20, 340, 340, QPen(Qt::NoPen), QBrush(QColor("#353535")));
}

void Board::putSquaresToBoard()
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            SquareColor sqrColor = (i+j)%2==0 ? Brown : LightBrow;
            Square* sqr = new Square(sqrColor,i,j);
            squares[i][j] = sqr;
            vecSquares.append(sqr);
            this->addItem(sqr);
            sqr->setPos(i*100, j*100);
            connect(sqr, SIGNAL(clicked()), this, SLOT(squareClicked()));
        }
    }
}

void Board::removeSquaresFromBoard()
{
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            squares[i][j] = nullptr;
        }
    }
    for (Square* sqr : vecSquares) delete sqr;
    vecSquares.clear();
}

void Board::clearBoard()
{
    this->clear();
}

void Board::drawCircle(const int& c, const int& r)
{
    circle = new Circle();
    vecCircles.append(circle);
    this->addItem(circle);
    circle->setPos(c,r);
}

void Board::removeCirlce()
{
    for (Circle *c : vecCircles) delete c;
    vecCircles.clear();
}

void Board::drawXMark(const int &c, const int &r)
{
    xmark = new XMark();
    vecXMarks.append(xmark);
    this->addItem(xmark);
    xmark->setPos(c,r);
}

void Board::removeXMark()
{
    for (XMark *x : vecXMarks) delete x;
    vecXMarks.clear();
}

void Board::squareClicked() {
    Square *sqr = qobject_cast<Square*>(sender());
    qDebug() << "Row:" << sqr->getRow() << "Col:" << sqr->getCol();

    if (!status) return;

    switch(mainSquareType) {
    case X_Mark:
        drawXMark(sqr->getCol()*100, sqr->getRow()*100);
        sqr->setSquareType(X_Mark);
        setImageToLabel(O_Mark);
        mainSquareType = O_Mark;
        counter++;
        break;
    case O_Mark:
        drawCircle(sqr->getCol()*100, sqr->getRow()*100);
        sqr->setSquareType(O_Mark);
        setImageToLabel(X_Mark);
        mainSquareType = X_Mark;
        counter++;
        break;
    default:
        break;
    }

    if (checkWin() == true) {
        status = false;
        if (sqr->getSquareType() == X_Mark) {
            message(tr("WINNER!"), tr("X_MARK!"));
            return;
        } else {
            message(tr("WINNER!"), tr("CIRLCE_MARK!"));
            return;
        }
    }
    if (counter >= 9) {
        status = false;
        message(tr("DRAW !"), tr("No one has won"));
        return;
    }
}

void Board::drawLine(const LineType &lType, const int &col, const int &row)
{
    line = new Line(lType);
    vecLines.append(line);
    this->addItem(line);
    line->setPos(col, row);
}

void Board::removeLine()
{
    for (Line *l : vecLines) delete l;
    vecLines.clear();
}

void Board::drawVerticalLine(const int &row)
{
    drawLine(Vertically, 0, row);
    drawLine(Vertically, 100, row);
    drawLine(Vertically, 200, row);
}

void Board::drawHorizontalLine(const int &col)
{
    drawLine(Horizontal, col, 0);
    drawLine(Horizontal, col, 100);
    drawLine(Horizontal, col, 200);
}

void Board::drawDiagonalLeftLine()
{
    drawLine(DiagonalLeft, 0, 0);
    drawLine(DiagonalLeft, 100, 100);
    drawLine(DiagonalLeft, 200, 200);
}

void Board::drawDiagonalRightLine()
{
    drawLine(DiagonalRight, 0, 200);
    drawLine(DiagonalRight, 100, 100);
    drawLine(DiagonalRight, 200, 0);
}

QPushButton *Board::createButton(const QString &text, const char *member)
{
    QPushButton *button = new QPushButton(text);
    connect(button, SIGNAL(clicked()), this, member);
    return button;
}

void Board::startClicked()
{
    status = true;
    int num = rand();
    if ((num % 2) == 0) {
        mainSquareType = X_Mark;
        setImageToLabel(X_Mark);
    } else {
        mainSquareType = O_Mark;
        setImageToLabel(O_Mark);
    }
}

void Board::resetClicked()
{
    counter = 0;
    status = false;
    removeCirlce();
    removeXMark();
    removeLine();
    removeSquaresFromBoard();
    putSquaresToBoard();
    setValuesToZero();
    setImageToLabel(Empty);
}

bool Board::checkWin() {
    for (int i=0, j; i<3; i++) {
        for (j=0; j<3; j++) {
            if (squares[i][j]->getSquareType() == X_Mark) horXMark++;
            if (squares[j][i]->getSquareType() == X_Mark) verXMark++;
            if (squares[i][j]->getSquareType() == O_Mark) horOMark++;
            if (squares[j][i]->getSquareType() == O_Mark) verOMark++;
        }
        if (horXMark == 3) {
            drawHorizontalLine(i*100);
            return true;
        }
        if (verXMark == 3) {
            drawVerticalLine(i*100);
            return true;
        }
        if (horOMark == 3) {
            drawHorizontalLine(i*100);
            return true;
        }
        if (verOMark == 3) {
            drawVerticalLine(i*100);
            return true;
        }
        horXMark = verXMark = 0;
        horOMark = verOMark = 0;
    }

    for (int i=0; i<3; i++) {
        if (squares[i][i]->getSquareType() == X_Mark) diagLXMark++;
        if (squares[i][2-i]->getSquareType() == X_Mark) diagRXMark++;
        if (squares[i][i]->getSquareType() == O_Mark) diagLOMark++;
        if (squares[i][2-i]->getSquareType() == O_Mark) diagROMark++;
    }
    if (diagLXMark == 3) {
        drawDiagonalLeftLine();
        return true;
    }
    if (diagRXMark == 3) {
        drawDiagonalRightLine();
        return true;
    }
    if (diagLOMark == 3) {
        drawDiagonalLeftLine();
        return true;
    }
    if (diagROMark == 3) {
        drawDiagonalRightLine();
        return true;
    }
    diagLXMark = diagRXMark = 0;
    diagLOMark = diagROMark = 0;
    return false;
}

void Board::setValuesToZero()
{
    horXMark = verXMark = 0;
    horOMark = verOMark = 0;
    diagLXMark = diagRXMark = 0;
    diagLOMark = diagROMark = 0;
}

void Board::setImageToLabel(const SquareType &sqrType)
{
    QPixmap pixmap(composeImagePath(sqrType));
    label->setPixmap(pixmap);
    label->setAlignment(Qt::AlignCenter);
}

QString Board::composeImagePath(const SquareType& sqrType)
{
    QString fileName = "/home/kamil/Documents/repositories/tic_tac_toe/tic_tac_toe/img/";

    switch (sqrType) {
    case X_Mark:
        fileName += "xs";
        break;
    case O_Mark:
        fileName += "os";
        break;
    case Empty:
        fileName += "q";
        break;
    default:
        qDebug() << "There is no file in catalog /img";
        break;
    }
    return fileName += ".bmp";
}

void Board::message(const QString &title, const QString&text)
{
    QMessageBox msg;
    msg.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    msg.setText(title);
    msg.setInformativeText(text);
    msg.setStandardButtons(QMessageBox::Ok);
    msg.exec();
}
