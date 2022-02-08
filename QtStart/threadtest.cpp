#include "threadtest.h"

// run파일엔 run함수를 구현한다.

ThreadTest::ThreadTest(QObject *parent):
    QThread(parent)
{    
}

void ThreadTest::run()
{
    int high_count = 0;
    int low_count;

    while(high_count<10000)
    {
        high_count++;
        low_count=0;

        while(low_count<100000)
            low_count++;
    }

    emit FinishCount(high_count); // run()함수가 끝났을 ㄸㅐ FInishCount()라는 시그널을 발생시키라는 명령
}
