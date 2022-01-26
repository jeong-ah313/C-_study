#include <iostream>
#include <thread> // thread ������� �߰�
#include <cstdio>
#include <vector>

using std::thread;

// �����忡 ���� �����ϱ�
void worker(std::vector<int>::iterator start, std::vector<int>::iterator end, int* result)
{
    int sum = 0;
    for (auto itr = start; itr < end; ++itr)
    {
        sum += *itr;
    }
    *result = sum;

    // �������� id�� ���Ѵ�.- �� �����忡 ���� ���̵� ��ȣ �Ҵ�
    thread::id this_id = std::this_thread::get_id(); //this_thread::get_id() �Լ��� ���� ���� ���� ���ư��� �ִ� �������� ���̵� �� �� ����.
    printf("������ %x ���� %d ���� %d ���� ����� ��� : %d \n", this_id, *start, *(end-1), sum); // �ٸ� ��������� �� �����̿� �޼����� ������� ���ϰ� ��������,

}

int main()
{
    // �� �����忡�� �ӹ��� �Ҵ��ϰ� �ִ� ���
    std::vector<int> data(10000);
    for (int i = 0; i < 10000; i++)
    {
        data[i] = i;
    }

    // �� �����忡�� ���� �κ� �յ��� �����ϴ� ����
    std::vector<int> partial_sums(4);

    std::vector<thread> workers;
    for (int i = 0; i < 4; i++)
    {
        // ������ ������(workers)���� ������ �����ؾ� �� ���� �� �����带 �����ؼ� �Լ��� ���ڵ��� ����
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
    std::cout << "��ü �� : " << total << std::endl;
}
