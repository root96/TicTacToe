#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Board();
    view = new QGraphicsView(scene, this);
    grid = new QGridLayout();

    view->setMinimumSize(405, 405);

    grid->addWidget(view, 0, 0, 3, 3);
    grid->addWidget(scene->getStartButton(), 4, 0);
    grid->addWidget(scene->getResetButton(), 4, 1);
    grid->addWidget(scene->getLabel(), 4, 2);
    centralWidget()->setLayout(grid);
}

MainWindow::~MainWindow()
{
    delete ui;
}
