#include <iostream>
#include <thread> // thread ������� �߰�
#include <cstdio>
#include <vector>

void func1() // �۾�
{
    long long total = 0;
    for (int i = 0; i < 100000000; i++) // i�� �۾� ����
    {
        total += i;
    }
    std::cout << "�۾� ���� : " << total << std::endl;
}

void func2(long long& sum, long long start, long long end)
{
    for (long long i = start; i < end; i++) // i�� �۾� ����
    {
        sum += i;
    }
}

//void thread1()
//{
//    std::thread t1(func1); // ������ ��ü ���� - t1�� ���ڷ� ���޹��� �Լ� func1�� ���ο� �����忡�� �����ϰ� �ȴ�.
//}

inline void thread10()
{
//    std::thread t1(func1); // ������ ��ü ���� - t1�� ���ڷ� ���޹��� �Լ� func1�� ���ο� �����忡�� �����ϰ� �ȴ�.
//    std::thread t2(func1); // ������ ��ü ���� - t1�� ���ڷ� ���޹��� �Լ� func1�� ���ο� �����忡�� �����ϰ� �ȴ�.

    // ������ �۾� ����
    std::vector<std::thread> workers;
    long long sum[10] = {0, 0, 0, 0, 0, 0, 0,};
    for(int i = 0; i < 10; i++)
    {
        const long long start = (i * 10000000);
        const long long end = start + 10000000;
        workers.push_back(std::thread(func2, std::ref(sum[i]), start, end));
    }

    // �۾� �Ϸ� �� �� ������ ���Ӵٷ��ֱ�
//    for(auto& e : workers)
    for(int i = 0; i < workers.size(); i++)
    {
        workers[i].join();
//        e.join();
    }

    // �۾� ����� ��ġ��
    long long total = 0;
    for(int i = 0; i < 10; i++)
    {
        total += sum[i];
    }

    // ���
    std::cout << "result is : " << total << std::endl;
}
#include <chrono>
using namespace std::chrono;
int main()
{
    system_clock::time_point start = system_clock::now();
    std::thread t1(func1); // ������ ��ü ���� - t1�� ���ڷ� ���޹��� �Լ� func1�� ���ο� �����忡�� �����ϰ� �ȴ�.
    t1.join();
//    thread10();
    system_clock::time_point end = system_clock::now();
    nanoseconds nano = end - start;
    std::cout << "����ð�(������ ns) : " << nano.count() << std::endl;
    return 0;
}
