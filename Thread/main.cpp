#include <iostream>
#include <thread> // thread ������� �߰�

void ManyTimeThread()
{
    // ���ð��� �� �۾���
    // ���ͳݿ��� ������Ʈ���� �ܾ� �𸣴� ���α׷�

//    map < string, string > url_and_content;
//    for (auto itr = url_and_content.begin(); itr != url_and_content/end(); ++itr)
//    {
//        const string& url = itr->first;

//        // download �Լ��� ���ڷ� ���޹��� url�� �ִ� ������Ʈ�� �ٿ�޾� �����Ѵ�.
//        itr -> second = download(url);
//    }

}

// �� ���� ù ������
using std::thread;

void func1() {
  for (int i = 0; i < 10; i++) {
    std::cout << "������ 1 �۵���! \n";
  }
}

void func2() {
  for (int i = 0; i < 10; i++) {
    std::cout << "������ 2 �۵���! \n";
  }
}

void func3() {
  for (int i = 0; i < 10; i++) {
    std::cout << "������ 3 �۵���! \n";
  }
}
int main() {
  thread t1(func1); // ������ ��ü ���� - t1�� ���ڷ� ���޹��� �Լ� func1�� ���ο� �����忡�� �����ϰ� �ȴ�.
  thread t2(func2);
  thread t3(func3);

  // join: �ش��ϴ� ��������� ������ �����ϸ� �����ϴ� �Լ��̴�.
//  t1.join(); // t1.join()�� t1�� �����ϱ� ������ �������� �ʴ´�.
//  t2.join();
//  t3.join();

  // detach: �ش��ϴ� �����带 ���� ��Ų ��, �ؾ������ ��(��� ������� �˾Ƽ� ��׶��忡�� ���ư��� �ȴ�.)
  t1.detach();
  t2.detach();
  t3.detach();

  std::cout << "���� �Լ� ���� \n" << std::endl; // detach�ϴ°� �� ���� �ȵʤ̤� ��ۿ� �ִ� ���� Ȯ���غ���

}
