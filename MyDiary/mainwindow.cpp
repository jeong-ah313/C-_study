#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QtDebug>
#include <QFile>
#include <QDir>
#include <QString>
#include <QMessageBox>
#include <QDate>
#include <QDateTime>
#include <QComboBox>
#include <QFileDialog>

//static int sum(int a, int b)
//{
//    return a + b;
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 원하는 색으로 글자색 변환
void MainWindow::on_pushButton_7_clicked()
{
    QColorDialog dlg;
    dlg.currentColor();

    QColor SelectColor = QColorDialog::getColor();
    if (SelectColor.isValid()) {
        QPixmap px(40, 40);
        px.fill(SelectColor);

        const QString styleSheet = "color: " + SelectColor.name();
        qDebug() << styleSheet;
        ui->textEdit_2->setStyleSheet(styleSheet); // 글자색 변환
    }
}

// txt 파일 불러오기
void MainWindow::on_pushButton_2_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "파일 선택", "C:\\Users\\user\\Desktop", "Files(*.txt)");
    qDebug() << filePath;

    // 읽기 파일
    QFile file(filePath); // 선택한 파일을 불러오기(읽기)
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) // 파일열기
        return;

    QString text;

    QTextStream in(&file);
    while (!in.atEnd()){ // 파일의 끝이 아니면
        QString line = in.readLine(); // 한줄씨ㄱ 읽는다.
        //            qDebug() << line;
        text += line + "\n";
    }


    QMessageBox::information(this, "title", "Success!");


    //    qDebug() << text;
    ui->textEdit_2->setText(text);

    file.close();
}

// txt 파일 저장 - 파일 저장 안됨....
void MainWindow::on_pushButton_3_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "파일 저장", "C:\\Users\\user\\Desktop", "Files(*.txt)"); // 현재 문서를 저장할 파일을 선택
    //    qDebug() << File;

    // 저장 파일
    QFile output(filePath);
    if (!output.open(QIODevice::ReadWrite | QIODevice::Text))
        return;

    QString TextOut;
    QTextStream out(&output); // output위치의 포인터를 out이라 정함

    const auto text = ui->textEdit_2->toPlainText();

    out << text;

    output.close();

    QMessageBox::information(this, "title", "Success!");
}


void MainWindow::on_pushButton_clicked()
{
    ui->textEdit_2->clear();
    // 지울게 없을ㄸㅐ는 따로 다른 메세지창을 띄우게 하는 게 좋을 것 같음
    QMessageBox::information(this, "title", "Clear!");

}

// 날짜
void MainWindow::on_pushButton_4_clicked()
{

    QDateTime time= QDateTime::currentDateTime();
    QString time_text = time.toString("yyyy - MM - dd"); // lineEdit에 담을거라 \n가 안먹음

    ui->lineEdit->setText(time_text);

}

// 시간
void MainWindow::on_pushButton_8_clicked()
{
    QTime time= QTime::currentTime();
    QString time_text = time.toString("hh : mm : ss"); // lineEdit에 담을거라 \n가 안먹음

    ui->lineEdit_2->setText(time_text);
}


void MainWindow::on_textEdit_2_textChanged()
{
    const auto text = ui->textEdit_2->toPlainText();
    ui->plainTextEdit_2->document()->setPlainText(QString::number(text.length()));
}

