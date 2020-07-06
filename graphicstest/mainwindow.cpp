#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    /*
    // create our object and add it to the scene
    item = new MyItem();
    scene->addItem(item);
    */
    newEffect = new Effect();
    scene->addItem(newEffect);


    // Why is this needed? lol. But it solves the display issue
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
