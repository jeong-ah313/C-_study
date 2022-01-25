#include <iostream>
#include <thread> // thread 헤더파일 추가
#include <cstdio>
#include <vector>

void func1() // 작업
{
    long long total = 0;
    for (int i = 0; i < 100000000; i++) // i는 작업 갯수
    {
        total += i;
    }
    std::cout << "작업 종료 : " << total << std::endl;
}

void func2(long long& sum, long long start, long long end)
{
    for (long long i = start; i < end; i++) // i는 작업 갯수
    {
        sum += i;
    }
}

//void thread1()
//{
//    std::thread t1(func1); // 스레드 객체 생성 - t1은 인자로 전달받은 함수 func1을 새로운 스레드에서 실행하게 된다.
//}

inline void thread10()
{
//    std::thread t1(func1); // 스레드 객체 생성 - t1은 인자로 전달받은 함수 func1을 새로운 스레드에서 실행하게 된다.
//    std::thread t2(func1); // 스레드 객체 생성 - t1은 인자로 전달받은 함수 func1을 새로운 스레드에서 실행하게 된다.

    // 쓰레드 작업 분할
    std::vector<std::thread> workers;
    long long sum[10] = {0, 0, 0, 0, 0, 0, 0,};
    for(int i = 0; i < 10; i++)
    {
        const long long start = (i * 10000000);
        const long long end = start + 10000000;
        workers.push_back(std::thread(func2, std::ref(sum[i]), start, end));
    }

    // 작업 완료 될 떄 ㄲㅏ지 ㄱㅣ다려주기
//    for(auto& e : workers)
    for(int i = 0; i < workers.size(); i++)
    {
        workers[i].join();
//        e.join();
    }

    // 작업 결과를 합치기
    long long total = 0;
    for(int i = 0; i < 10; i++)
    {
        total += sum[i];
    }

    // 출력
    std::cout << "result is : " << total << std::endl;
}
#include <chrono>
using namespace std::chrono;
int main()
{
    system_clock::time_point start = system_clock::now();
    std::thread t1(func1); // 스레드 객체 생성 - t1은 인자로 전달받은 함수 func1을 새로운 스레드에서 실행하게 된다.
    t1.join();
//    thread10();
    system_clock::time_point end = system_clock::now();
    nanoseconds nano = end - start;
    std::cout << "경과시간(나노초 ns) : " << nano.count() << std::endl;
    return 0;
}
