#include <iostream>

void static_cast_prac()
{
    // static_cast
    // 묵시적 캐스트로 일반 변수형을 반환해준다.

    int d = 65;
    char ch1 = d; // 컴파일러가 묵시적으로 캐스팅을 해줌 -> 근데 이ㄸㅐ는 걍 char의 첫번ㅉㅐ인 A로 바뀐건가??
    char ch2 = static_cast<char>(d); //static_cast를 해도 무방

    std::cout << "컴파일러가 묵시적으로 캐스팅 했을 떄: " << d << std::endl;
    std::cout << "컴파일러가 묵시적으로 캐스팅 했을 떄: " << ch1 << std::endl;
    std::cout << "static_cast로 캐스팅 했을 떄: " << ch2 << std::endl << std::endl;

    float b = 12.111;
    int a = static_cast<int>(b);
    std::cout << "실수->정수 변환: " << a << std::endl << std::endl;

}

void reterpret_cast_prac(){
    // reterpret_cast
    // 일반적으로 허용하지 ㅇㅏㄶ는 위험한 형변호나을 할 ㄸㅐ ㅅㅏ용한다.
    // 단지 안의 있는 비트열만 보고 원하는 형으로 ㄱㅏㅇ제 ㅂㅕ호나을 ㅎㅏㄹ ㄸㅐ ㅅㅏ용한다.
    // 포인터를 정수로 ㅂㅕㄴ호나하는 ㅈㅏㄱ업을 ㅅㅏ용할 ㄸㅐ 많이 사용한다.

    int a = 10, b = 20;
    int *c = &a;
    int *d = &b;
    std::cout << "포인터를 정수로 변환: " << *c << std::endl; // a값
    std::cout << "포인터를 정수로 변환: " << *d << std::endl; // b값
    a = reinterpret_cast<int>(&b);

    std::cout << "포인터를 정수로 변환: " << a << std::endl; // 질문: 포인터 값이(즉, 주소값이 정수로 저장되어 a에 저장된 거 같음)
    std::cout << "포인터를 정수로 변환: " << *c << std::endl;
    std::cout << "포인터를 정수로 변환: " << b << std::endl; // 질문: b값에는 원래 ㅈㅓ장한 값이 그대로 오게 되는 것을 볼 수 있음
    std::cout << "포인터를 정수로 변환: " << *d << std::endl << std::endl;
}

class Parent2
{
public:
    Parent2() {std::cout << "Parent2" << std::endl;}
    virtual~Parent2() {std::cout << "~Parent2" << std::endl;}

    void say2()
    {
        std::cout << "parent2 say" << std::endl;
    }
};

class Child2 : public Parent2
{
public:
    Child2() {std::cout << "Child2" << std::endl;}
    virtual ~Child2() {std::cout << "~Child2" << std::endl; }

    void say2()
    {
        std::cout << "Child2 say" << std::endl;
    }
};

void dynamic_cast_prac()
{
    // dynamic_cast
    // 유일하게 c스타일의 형변환으로 불가능한 캐스팅.
    // 상속관계에 있는 클래스의 형변환을 수행하며, 동시에 안전한지 검사한다.

//    Truck* pTruck = new Car;
//    Truck* pTruck = dynamic_cast<Truck*>(new Car);

    // 질문: 잘 모르겠음....
    Parent2* ptr_p_instance2 = new Child2;
//    Parent2* ptr_p_instance2 = dynamic_cast<Parent2*>(new Child2);

    std::cout << std::endl;
}

void const_cast_prac()
{
    // const_cast
    // const 속성이나 volatile 속성을 해제할 ㄸㅐ 사용한다. 변수를 정의할 ㄸㅐ volatile 키워드를 사용한다.
    // 즉 상수로 정의한 변수를 변경하고 싶을 ㄸㅐ 사용한다.


    // 1) pointer 변수에 Const 지정자를 제거하는 ㅇㅖ제
    const int *const_int_ptr = new int(10);
    int *int_ptr;

    std::cout << *const_int_ptr << std::endl;

    int_ptr = const_cast<int*>(const_int_ptr); // const_int_ptr의 const 지정자를 잠시 제거
    *int_ptr = 20; // const_int_ptr의 값을 변경

    std::cout << *const_int_ptr << std::endl;
    std::cout << *int_ptr << std::endl;
}
int main()
{
    static_cast_prac();
    reterpret_cast_prac();
    dynamic_cast_prac();
    const_cast_prac();
}

