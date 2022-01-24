#include <iostream>
#include <thread> // thread 헤더파일 추가

void ManyTimeThread()
{
    // 대기시간이 긴 작업들
    // 인터넷에서 웹사이트들을 긁어 모르는 프로그램

//    map < string, string > url_and_content;
//    for (auto itr = url_and_content.begin(); itr != url_and_content/end(); ++itr)
//    {
//        const string& url = itr->first;

//        // download 함수는 인자로 전달받은 url에 있는 ㅅㅏ이트를 다운받아 리턴한다.
//        itr -> second = download(url);
//    }

}

// 내 생에 첫 쓰레드
using std::thread;

void func1() {
  for (int i = 0; i < 10; i++) {
    std::cout << "쓰레드 1 작동중! \n";
  }
}

void func2() {
  for (int i = 0; i < 10; i++) {
    std::cout << "쓰레드 2 작동중! \n";
  }
}

void func3() {
  for (int i = 0; i < 10; i++) {
    std::cout << "쓰레드 3 작동중! \n";
  }
}
int main() {
  thread t1(func1); // 스레드 객체 생성 - t1은 인자로 전달받은 함수 func1을 새로운 스레드에서 실행하게 된다.
  thread t2(func2);
  thread t3(func3);

  // join: 해당하는 스레드들이 실행을 종료하면 리턴하는 함수이다.
//  t1.join(); // t1.join()은 t1이 종료하기 전까지 리턴하지 않는다.
//  t2.join();
//  t3.join();

  // detach: 해당하는 스레드를 실행 시킨 후, 잊어버리는 것(대신 스레드는 알아서 백그라운드에서 돌아가게 된다.)
  t1.detach();
  t2.detach();
  t3.detach();

  std::cout << "메인 함수 종료 \n" << std::endl; // detach하는거 잘 이해 안됨ㅜㅜ 답글에 있는 내용 확인해보기

}
