#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "book.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Book book;
    book.Move(2);
    book.Show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

