#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std::chrono;
// <10���� ������� 100,000�� ������ ��, �߻��ϴ� ���� ������>
void worker(int &result){
    for (auto i = 0; i < 10000; i++)
    {
        result += 1;
    }
}

int main()
{
    // thread ���� ����
    std::vector<std::thread> workers; //�����带 ���� worker�̶�� ��������� �������

    // thread�� ������ ����
    int count = 0;

    steady_clock::time_point start = steady_clock::now(); //steady_clock::time_point�� ���� ���۸�
    for (int i = 0; i < 10; i++)
    {
        workers.push_back(std::thread(worker, std::ref(count))); //���۷����� ���ڸ� �����Ϸ��� ref�Լ��� ���þ���
    }

}
