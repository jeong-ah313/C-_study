#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QtDebug>
#include <QFile>
#include <QDir>
#include <QString>

//static int sum(int a, int b)
//{
//    return a + b;
//}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    ui->pushButton

//    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(selectColorButton())); //수동생성
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

void MainWindow::on_pushButton_2_clicked()
{
//    QCoreApplication::applicationDirPath() + "/diary.txt"; // 현재 경로에서 test파일을 추가해줌

//    QString file = "../../Desktop/diary.txt";

//    if (QFile::exists(file))
//    {

//    }

//    ui->textEdit_2->setText();

    // 읽기 파일
    QFile file("diary.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString text;

    QTextStream in(&file);
    while (!in.atEnd()){ // 파일의 끝이 아니면
        QString line = in.readLine(); // 한줄씨ㄱ 읽는다.
//        qDebug() << line;
        text += line + "\n";
    }

//    qDebug() << text;
    ui->textEdit_2->setText(text);


    //

//    QDir Directory("Diary"); // 파일 폴더 선택
//    if(!Directory.exists()) // 폴더 존재 유무 확인
//    {
//        Directory.mkdir("/."); // 없으면 현재 위치에 폴더 생성
//    }


//    QDir Directory("Diary"); // 파일 폴더 선택


//    QFile File("test.txt");

//    // 읽기 전용
//    if(!File.open(QFile::ReadOnly::Text))
//    {
//        if(!File.exists())
//        {

//        }
//    }

}

