#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 수동 생성
    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(on_pushButton_pressed()));
    connect(ui->pushButton, SIGNAL(released()), this, SLOT(on_pushButton_released()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // 클릭(자동 생성)
    QMessageBox::information(this, "title", "hi");
}


void MainWindow::on_radioButton_clicked()
{

}

void MainWindow::on_pushButton_pressed()
{
    qDebug() << "on_pushButton_pressed";
}

void MainWindow::on_pushButton_released()
{
    qDebug() << "on_pushButton_released";
}

