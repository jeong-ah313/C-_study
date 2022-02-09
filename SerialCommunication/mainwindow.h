#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public: // 소멸자
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void serial_connect();
    void serial_rescan();
    void widget_changed();
    void send_test();
    void serial_received();

private:
    Ui::MainWindow *ui;
};


#endif
