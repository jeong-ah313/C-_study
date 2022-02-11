#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>

#include <QLabel>
#include <QMessageBox>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_serial(new QSerialPort(this))     // 시리얼(포트) 생성
    , m_chart(nullptr)
    , m_series(nullptr)
{
    m_ui->setupUi(this);

    /// 차트 생성
    m_chart = new QChart();
    m_chart->legend()->hide();
//    chart->addSeries(f);
    m_chart->setTitle("Line Chart Example");
//    m_chart->createDefaultAxes();
    QValueAxis *axisX = new QValueAxis();
    QValueAxis *axisY = new QValueAxis();
    m_chart->addAxis(axisX, Qt::AlignBottom);
    m_chart->addAxis(axisY, Qt::AlignLeft);

    axisX->setRange(0, 3000);
//    axisX->setTickCount(10);
    axisY->setRange(-20, 20);

//    auto axesX = m_chart->axes(Qt::Horizontal);
//    auto axesY = m_chart->axes(Qt::Vertical);
//    axesX.at(0)->setRange(0, 100);
//    axesY.at(0)->setRange(0, 100);

    /// 시리즈 생성
    m_series = new QLineSeries();
//    for (int i = 0; i < 500; i++) {
//        QPointF point((qreal) i, qSin(M_PI / 50 * i) * 100);
//        point.ry() += QRandomGenerator::global()->bounded(20);
//        *m_series << point; // operator
//    }

    /// 차트뷰 생성
    QChartView *chartView = new QChartView(m_chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    m_ui->verticalLayout->addWidget(chartView);

    m_chart->addSeries(m_series);

    m_ui->Connect->setEnabled(true);  // ui 멤버변수에서 연결동작에 대한 활성화를 설정
    m_ui->DisConnect->setEnabled(false);  // ui 멤버변수에서 비연결동작에 대한 활성화를 설정

    // 만든 다음에 Connect 연결 해주기 !!!!!!!
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);

    // 닫을 떄의 connect도 설정해줘야 함.

//    QString test = "6.655\r\n";
//    auto r = test.indexOf('\r');
//    auto n = test.indexOf('\n');
//    auto result = test.mid(0, r);
//    qDebug() << QString::number(r) << QString::number(n);
//    qDebug() << result;
}

//소멸자
MainWindow::~MainWindow()
{
    delete m_ui;
}

// 버튼 클릭시, 시리얼포트 열 떄.
void MainWindow::on_Connect_clicked()
{
    m_serial->setPortName("COM5"); // 포트 이름 설정
    m_serial->setBaudRate(9600); // 보드레이트 설정
    m_serial->setDataBits(QSerialPort::Data8); // 데이터 비트 설정
    m_serial->setParity(QSerialPort::NoParity); // 패리티 설정
    m_serial->setStopBits(QSerialPort::OneStop); // 스탑 비트 설정
    m_serial->setFlowControl(QSerialPort::NoFlowControl); // 플로우 컨트롤 설정
    if (m_serial->open(QIODevice::ReadWrite)) { // 읽고 쓰기 모드로 염
//        const QByteArray data = m_serial->readAll();
//        qDebug() << data;
        m_buffer.clear();
        m_ui->Connect->setEnabled(false);  // ui 멤버변수에서 연결동작에 대한 활성화를 설정
        m_ui->DisConnect->setEnabled(true);  // ui 멤버변수에서 비연결동작에 대한 활성화를 설정
    }
}

void MainWindow::readData() // 읽기데이터 함수
{
    const QByteArray data = m_serial->readAll();    // 데이터는 멤버변수 시리얼에서 모든 것을 읽어 온 것

    m_buffer.push_back(data);

    // 파싱
    int r = m_buffer.indexOf('\r');
    int n = m_buffer.indexOf('\n');
    if(r != -1 && n != -1)
    {
        auto result = m_buffer.left(r);
        m_buffer.remove(0, n + 1);
//        qDebug() << result;

        // 여긴 lineEditor라서, 문자열인 result로 넣어서 출력을해줘야하는거고
//        m_ui->lineEdit->setText(result);

        // 차트에 숫자로 넣어주시 위해
        // 문자열(string) -> 실수(float)로 변환

        auto points = m_series->pointsVector();

        const double x = points.length() + m_data.length();
        const double y = result.toDouble();
        m_data.push_back(QPointF(x, y));
//        if(m_data.size() == 100)
//        {
//            points.append(m_data);
//            m_series->replace(points); // 화면 다시 그린다.
//            m_data.clear();
//        }

//        float f = std::stof(result.data()); // float로 바꿔줌
//        qDebug() << QString::number(y);
//        m_series->append(x, y);
//        qDebug() << QPointF(x, y);


//        m_ui->frame->putData(f);
//        m_ui->frame->addSeries(f);

//        chart->putData(f);
//        m_chart->addSeries(f);

//        m_ui->frame->chart->f;

        //
    }

//    qDebug() << data;

    // 일단 linechart에다가 그려봄
//    m_ui->lineEdit->setText(data);

    // 이제 linechart에 그려야 함.


    // 나중에 ui에 타이틀 추가해주기
    // m_ui->lineEdit->setTitle("Zoom in/out example");
}

// 시리얼포트를 닫을 떄
void MainWindow::on_DisConnect_clicked()
{
    if (m_serial->isOpen()) // 멤버변수 시리얼이 열려 있을 ㄸㅐ
        m_serial->close();  // 멤버변수 시리얼을 닫음

    auto points = m_series->pointsVector();

    points.append(m_data);
    m_series->replace(points); // 화면 다시 그린다.
    m_data.clear();

    m_ui->Connect->setEnabled(true);  // ui 멤버변수에서 연결동작에 대한 활성화를 설정
    m_ui->DisConnect->setEnabled(false);  // ui 멤버변수에서 비연결동작에 대한 활성화를 설정

//    m_ui->lineEdit->clear();
//    showStatusMessage(tr("Disconnected"));  // 상태메세지를 보여준다(Disconnected 띄움)
}

