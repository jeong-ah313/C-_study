#ifndef THREADTEST_H
#define THREADTEST_H

#include <QThread>

// 헤더에는 QThead로부터 ㅅㅏㅇ속받은 가상함수 run()을 오버라이드하고 작업을 ㄲㅡㅌ냈을ㄸㅐ MainWindow 클래스에 신호를 ㄴㅏㄹ려줄 Signal함수 FinishCount()를 선언

class ThreadTest : public QThread
{
    Q_OBJECT
public:
    ThreadTest(QObject *parent = 0);
//    ThreadTest();

signals:
    void FinishCount(const int value);

public slots:

protected:
    void run() override;

};

#endif // THREADTEST_H
