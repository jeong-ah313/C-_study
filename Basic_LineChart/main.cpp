#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Chart에서 사용할 데이터를
    // 저장하기 위해 QLineSeries포인터 생성
    QLineSeries *series = new QLineSeries();
    // 즉, series는 데이터를 담을 포인터임(화살표는 앞에 변수가 포인터일떄 사용)
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    // QPointF(xpos, ypos) : 주어진좌표로 점을 생성
    *series << QPointF(11, 1) << QPoint(13, 3) <<QPointF(17, 6) << QPointF(18, 3) << QPoint(20, 2); // 이렇게 한꺼번에 한줄로 값을 넣어줄 수도 있음

    // Chart를 생성하고 특성을 설정
    QChart *chart = new QChart();
    chart->legend()->hide();

    // Chart에 입력된 데이터 적용
    chart->addSeries(series);
    chart->createDefaultAxes(); // 차으테 이미 추가된 계열을 기반으로 차트의 축을 만듦(이전에 추가된 모든 축은 삭제)

    // Set Title
    chart->setTitle("Simple line chart example");

    // QChartView에 chart 입력
    QChartView *chartView = new QChartView(chart);

    // chartView속성 설정
    // QPainter::Antialiasing - 엔진이 가능한 경우 프리미티브의 가장자리를 앤티앨리어싱(계단현상해결)해야 함을 나타냅니다.
    chartView->setRenderHint(QPainter::Antialiasing);

    // 윈도우에 chart설정
    QMainWindow window;
    window.setCentralWidget(chartView); // setCentralWidget으로 위젯을 추가해줌
    window.resize(400, 300);
    window.show();

    return a.exec();

}
