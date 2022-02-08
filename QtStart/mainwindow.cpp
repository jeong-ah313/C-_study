#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timer = new QTimer(this); // QTimer: 시간 간격에 따라 반복하거나 특정 시간에 이벤트가 발생하도록 처리할 수 있는 위젯(밀리초 기준)
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimerCount()));

    m_thread = new ThreadTest(this);
    connect(m_thread, SIGNAL(FinishCount(const int)), this, SLOT(threadFinish(const int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int count=0; // static은 전역변수 같은 느낌
    QString qstr;
    // arg: 여러개의 포맷 지정자를 사용할 ㄸㅐ arg()함수를 계속 이어 붙이면 된다
    qstr = QString("%1 %2 %3...").arg(count).arg(count+1).arg(count+2); // QStringdms %d 이런게 아니라 %1,2 넣어줌
    ui->lineEdit->setText(qstr);
    count++;
}

void MainWindow::on_pushButton_timer_clicked()
{
    m_timer->start(100);
}

void MainWindow::onTimerCount()
{
    static int count=0;
    static QVector<int> integers;
    integers.push_back(count); // Qvector의 추가해주는 함수(integer에 count를 더해줌)

    QString qstr;
    qstr = QString("%1 %2 %3").arg(integers[0]).arg(integers.last()).arg(integers.size());
    ui->lineEdit->setText(qstr);

    count++; // 해주면 100이되니까
    if(count==100) // 100이라서 초기화 시켜줘서 다음번에 다시 실행할떈 0부터 시작되는 것
    {
        count=0;
        integers.clear();
        m_timer->stop();
    }
}

void MainWindow::on_pushButton_thread_clicked()
{
    m_thread->start();
}

void MainWindow::threadFinish(const int value)
{
//    m_thread->isFinished() // ㄲㅡㅌ났냐?
//    m_thread->isRunning() // 돌고 있냐?

    ui->lineEdit->setText(QString("high_count=%1").arg(value));
}
