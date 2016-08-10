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


QString randString(int len)
{
    QString str;
    str.resize(len);
    for (int s = 0; s < len ; ++s)
        str[s] = QChar('A' + char(qrand() % ('Z' - 'A')));

    return str;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
   QString ta=ui->plainTextEdit->toPlainText();
   ui->textEdit->setText(ta);
}

void MainWindow::on_toolButton_clicked(bool checked)
{
    int randomValue = qrand() % 9;
    QString ta=randString(randomValue);
    ui->plainTextEdit->clear();
    ui->plainTextEdit->setPlainText(ta);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    int ta= ui->spinBox->value();
    ui->progressBar->setValue(ta);
}

void MainWindow::on_toolButton_2_clicked(bool checked)
{
    ui->textEdit->clear();
}

void MainWindow::on_pushButton_3_clicked(bool checked)
{
    ui->textEdit->setTextBackgroundColor("#f00000");
}
