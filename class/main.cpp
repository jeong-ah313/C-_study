#include "mainwindow.h"
#include <iostream>

#include <QApplication>

// Class: C++에서 클래스란 구조체의 상위호환으로 이해할 수 있음.
// C++의 구조체는 멤버로 함수를 포함할 ㅅㅜ 있다 구조체와 클래스 접근제어의 차이일ㅃㅜㄴ ㄱㅓ의 비슷
// 클래스로 객체 지향 프로그램 작성 가능
// 클래스의 멤버 변수: 프로퍼티(preperty), 멤버함수: 메소드(method)

// 객체 지향 프로그래밍(OOP-Object-Oriented Programming)
// 객체 지향 프로그래밍에서는 모든 데이터를 객체(object)로 취급하며, 객체가 바로 프로그래밍의 중심이 된다.
// 객체 like 사물, 객체의 상태와 행동 구체화 하는 것이 객체 지향 프로그래밍, 객체를 만들어 내기 위한 틀과 같은 개념이 클래스

// 객체 지향 프로그래밍의 특징
// 1. 추상화
// 2. 캡슐화
// 3. 정보 은닉
// 4. 상속성
// 5. 다형성

// 인스턴스(instance)
// 클래스 ㅅㅏ용을 위해서 해당 클래스 타입의 객체를 선언해야함
// 선언된 해당 클래스 타입의 객체를 인스턴스라고 함. 하나의 클래스에서 ㅇㅕ러가지 인스턴스 생성가능.

#include <QString> //string
#include <QtDebug> //printf
#include <QVector> //array


// 클래스의 선언
//class Book
//{
//private:
//    // 멤버변수
//    int current_page_;
//    void set_percent();
//public:
//    //메소드(멤버함수)
//    void Move(int page);
//    void Show();
//};

//// 멤버 함수의 정의
//// (일반함수와 비슷) 클래스의 ㅅㅓㄴ언 안이나 ㅂㅏㄲ에서 ㅁㅗ두 정의할 ㅅㅜ ㅇㅣㅆ다.
//// 클래스 선언 밖에서 멤버 함수를 정의할 ㄸㅐ에는 범위 지정 연산자(::)를 사용하여 해당 함수가 어느 클래스에 속하는지 명시해줘야 함
//// 문법(사용법): 클래스이름:: 멤버함수이름(매개변수목록) {함수의 몸체;}

//// 클래스 선언 ㅂㅏㄲ에서 멤버함수(ex.Move)를 정의하는 예제
//void Book::Move(int page)
//{
//    std::cout << "현재 페이지를 입력하세요";
//    std::cin >> page;
//    current_page_ = page;
//}

//void Book::Show()
//{
//    std::cout << "페이지 보여주기" << current_page_ << std::endl;
//}

// 멤버함수의 호출
// 멤버 참조 연산자(.)를 사용하여 호출할 수 있음.
// 문법(사용법): 1. 객체이름.멤버함수이름(); <- 매개변수가 없는 멤버 함수의 호출 or 객체이름.멤버함수이름(전달할인수목록); <- 매개변수가 있는 멤버함수 호출

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    MainWindow w;

    qDebug() << "fdsfsd";
    w.show();
    return a.exec();
}
