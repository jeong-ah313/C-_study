#include <iostream>

// type casting

// type casting의 종류- static_cast, const_cast, reinterpret_cast, dynamic_cast

void example()
{

}

// <1> static_cast
// 문법(사용법): static_cast<변환할 타입>(변환대상)

class Parent
{
public:
    void say()
    {
        std::cout << "parent say" << std::endl;
    }
};
class Child: public Parent
{
public:
    void say()
    {
        std::cout << "child say" << std::endl;
    }
};



// <4>
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

int main()
{
    Parent p_instance;
    Parent* ptr_p_instance;
    Child c_instance;
    Child* ptr_c_instance;
    float b;
    int a;

    // 1) 실수를 정수로, 정수를 실수로 변환
    b = 10.111;
    a = static_cast<int>(b);
    std::cout << a << std::endl;

    // 2) 자식 클래스 포인터가 자식 클래스를 가리키는 것도 가능
    c_instance = static_cast<Child>(c_instance);
    c_instance.say();

    // 3) 부모 클래스 포인터가 자식 클래스를 가리키는 것도 ㄱㅏ능
    ptr_p_instance = static_cast<Child*>(&c_instance);
    ptr_p_instance -> say();

    // 4번) 자식 클래스 포터가 부모 클래스를 가리키는 거솓 가능
    ptr_c_instance = static_cast<Child*>(&p_instance);
    ptr_c_instance -> say();

// <2> const_cast
    //문법(사용법): const_cast<변환할 타입>(변환 대상)
    //사용 시기: 포인터 및 참조형에서만 사용 ㄱㅏ능하며, 상수 속성(const) 및 volatile 제거할 ㄸㅐ 사용

    // 1) pointer 변수에 Const 지정자를 제거하는 ㅇㅖ제
    const int *const_int_ptr = new int(10);
    int *int_ptr;

    std::cout << *const_int_ptr << std::endl;

    int_ptr = const_cast<int*>(const_int_ptr); // const_int_ptr의 const 지정자를 잠시 제거
    *int_ptr = 20; // const_int_ptr의 값을 변경

    std::cout << *const_int_ptr << std::endl;


// <3> reinterpret_cast
    // 문법(사용법): reinterpret_cast<변환할 타입>(변환대상)
    // 사용시기: 명시적 변환과 동작이 동일 함으로 명시적 변환 대신 사용, 단, const를 사용하는 변환 대상은 사용할 수 없음

    // 명시적 형 변환
    int *int_ptr1 = new int(10);
    char *char_ptr;

    std::cout << *int_ptr1 << std::endl;

    char_ptr = reinterpret_cast<char*>(int_ptr1);
    *char_ptr = 20; //int_ptr의 ㄱㅏㅄ을 변경

    std::cout << *int_ptr1 << std::endl;

    // const 지정자 사용 시, 명시적 형 ㅂㅕㄴ환
    const int *int_ptr2 = new int(10);
    char *char_ptr2;

    std::cout << *int_ptr2 << std::endl;

    char_ptr2 = reinterpret_cast<char*>(const_cast<int*>(int_ptr2));
    *char_ptr2 = 20; // int_ptr의 값을 변경

    std::cout << *int_ptr2 << std::endl;

    // chat_ptr에도 값이 있는건가?? 이건 어ㄸㅓㅎ게 나올ㄲㅏ?
    std::cout << *char_ptr2 << std::endl;

// <4> dynamic_cast
    // 문법(사용법): dynamic_cast<변환할 타입>(변환대상)
    // 사용시기 : class의 포인터 ㄱㅏㄴ 형 변환 시, 안전하기 down casting을 위해 사용한다.
    //           class의 참조 변수간 형 변환 시, 안전하게 down casting을 위해 사용한다.
    //           단, parent에 virtual 함수가 존재해야 정상 동작한다.

    Parent2* ptr_p_instance2 = new Child2();
    Child2* ptr_c_instance2;

    ptr_p_instance2->say2();

    if (ptr_p_instance2 == nullptr){
        std::cout << "error compile" << std::endl;
    }
    ptr_c_instance2 -> say2();


    return 0;


}
