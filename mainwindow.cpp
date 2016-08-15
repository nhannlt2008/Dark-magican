#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFile file (":/Style.qss");
    file.open(QIODevice::ReadOnly);
    QString style = file.readAll();
    setStyleSheet(style);

}


MainWindow::~MainWindow()
{
    delete ui;
}
