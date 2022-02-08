#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <QVector>
#include "threadtest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_timer_clicked();
    void onTimerCount();
    void on_pushButton_thread_clicked();
    void threadFinish(const int value);

//    void on_pushButton_timer_2_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* m_timer;
    ThreadTest* m_thread;
};

#endif // MAINWINDOW_H
