#include <iostream>
#include <thread> // thread 헤더파일 추가
#include <cstdio>
#include <vector>

using std::thread;

// 쓰레드에 인자 전달하기
void worker(std::vector<int>::iterator start, std::vector<int>::iterator end, int* result)
{
    int sum = 0;
    for (auto itr = start; itr < end; ++itr)
    {
        sum += *itr;
    }
    *result = sum;

    // 쓰레드의 id를 구한다.- 각 스레드에 고유 아이디 번호 할당
    thread::id this_id = std::this_thread::get_id(); //this_thread::get_id() 함수를 통해 현재 내가 돌아가고 있는 쓰레드의 아이디를 알 수 있음.
    printf("쓰레드 %x 에서 %d 부터 %d 까지 계산한 결과 : %d \n", this_id, *start, *(end-1), sum); // 다른 스레드들이 그 ㅅㅏ이에 메세지를 집어넣지 못하게 ㅁㅏㄱㅇ,

}

int main()
{
    // 각 쓰레드에게 임무를 할당하고 있는 모습
    std::vector<int> data(10000);
    for (int i = 0; i < 10000; i++)
    {
        data[i] = i;
    }

    // 각 쓰레드에서 계산된 부분 합들을 저장하는 벡터
    std::vector<int> partial_sums(4);

    std::vector<thread> workers;
    for (int i = 0; i < 4; i++)
    {
        // 각각의 쓰레드(workers)들이 덧셈을 수행해야 할 범위 및 쓰레드를 생성해서 함수에 인자들을 전달
        workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
    }

    for (int i = 0; i < 4; i++)
    {
        workers[i].join();
    }

    int total = 0;
    for (int i = 0; i < 4; i++) {
        total += partial_sums[i];
    }
    std::cout << "전체 합 : " << total << std::endl;
}
