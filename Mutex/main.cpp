#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std::chrono;
// <10개의 스레드로 100,000을 더했을 떄, 발생하는 문제 만들어보기>
void worker(int &result){
    for (auto i = 0; i < 10000; i++)
    {
        result += 1;
    }
}

int main()
{
    // thread 넣을 벡터
    std::vector<std::thread> workers; //스레드를 담을 worker이라는 저장공간을 만들어줌

    // thread가 접근할 변수
    int count = 0;

    steady_clock::time_point start = steady_clock::now(); //steady_clock::time_point가 뭔지 구글링
    for (int i = 0; i < 10; i++)
    {
        workers.push_back(std::thread(worker, std::ref(count))); //레퍼런스로 인자를 전달하려면 ref함수를 ㅆㅓ야함
    }

}
