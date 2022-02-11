#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

#include <QtCharts>
#include <QChartView>
#include <QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Console;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct Settings {
        QString name;
        qint32 baudRate;
    };

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
//    void openSerialPort();
//    void closeSerialPort();
//    void about();
//    void writeData(const QByteArray &data);
    void readData();

    void on_Connect_clicked();
    void on_DisConnect_clicked();

private:
    void showStatusMessage(const QString &message);

    Ui::MainWindow *m_ui = nullptr;
    QSerialPort *m_serial = nullptr;

    QByteArray m_buffer;

    QChart *m_chart;
    QLineSeries* m_series;

    QVector<QPointF> m_data;

};
#endif // MAINWINDOW_H
