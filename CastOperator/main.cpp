#include <iostream>

// type casting

// type casting�� ����- static_cast, const_cast, reinterpret_cast, dynamic_cast

void example()
{

}

// <1> static_cast
// ����(����): static_cast<��ȯ�� Ÿ��>(��ȯ���)

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

    // 1) �Ǽ��� ������, ������ �Ǽ��� ��ȯ
    b = 10.111;
    a = static_cast<int>(b);
    std::cout << a << std::endl;

    // 2) �ڽ� Ŭ���� �����Ͱ� �ڽ� Ŭ������ ����Ű�� �͵� ����
    c_instance = static_cast<Child>(c_instance);
    c_instance.say();

    // 3) �θ� Ŭ���� �����Ͱ� �ڽ� Ŭ������ ����Ű�� �͵� ������
    ptr_p_instance = static_cast<Child*>(&c_instance);
    ptr_p_instance -> say();

    // 4��) �ڽ� Ŭ���� ���Ͱ� �θ� Ŭ������ ����Ű�� �ř� ����
    ptr_c_instance = static_cast<Child*>(&p_instance);
    ptr_c_instance -> say();

// <2> const_cast
    //����(����): const_cast<��ȯ�� Ÿ��>(��ȯ ���)
    //��� �ñ�: ������ �� ������������ ��� �������ϸ�, ��� �Ӽ�(const) �� volatile ������ ���� ���

    // 1) pointer ������ Const �����ڸ� �����ϴ� ������
    const int *const_int_ptr = new int(10);
    int *int_ptr;

    std::cout << *const_int_ptr << std::endl;

    int_ptr = const_cast<int*>(const_int_ptr); // const_int_ptr�� const �����ڸ� ��� ����
    *int_ptr = 20; // const_int_ptr�� ���� ����

    std::cout << *const_int_ptr << std::endl;


// <3> reinterpret_cast
    // ����(����): reinterpret_cast<��ȯ�� Ÿ��>(��ȯ���)
    // ���ñ�: ����� ��ȯ�� ������ ���� ������ ����� ��ȯ ��� ���, ��, const�� ����ϴ� ��ȯ ����� ����� �� ����

    // ����� �� ��ȯ
    int *int_ptr1 = new int(10);
    char *char_ptr;

    std::cout << *int_ptr1 << std::endl;

    char_ptr = reinterpret_cast<char*>(int_ptr1);
    *char_ptr = 20; //int_ptr�� �������� ����

    std::cout << *int_ptr1 << std::endl;

    // const ������ ��� ��, ����� �� ���Ť�ȯ
    const int *int_ptr2 = new int(10);
    char *char_ptr2;

    std::cout << *int_ptr2 << std::endl;

    char_ptr2 = reinterpret_cast<char*>(const_cast<int*>(int_ptr2));
    *char_ptr2 = 20; // int_ptr�� ���� ����

    std::cout << *int_ptr2 << std::endl;

    // chat_ptr���� ���� �ִ°ǰ�?? �̰� ��ä��� ���ä���?
    std::cout << *char_ptr2 << std::endl;

// <4> dynamic_cast
    // ����(����): dynamic_cast<��ȯ�� Ÿ��>(��ȯ���)
    // ���ñ� : class�� ������ ������ �� ��ȯ ��, �����ϱ� down casting�� ���� ����Ѵ�.
    //           class�� ���� ������ �� ��ȯ ��, �����ϰ� down casting�� ���� ����Ѵ�.
    //           ��, parent�� virtual �Լ��� �����ؾ� ���� �����Ѵ�.

    Parent2* ptr_p_instance2 = new Child2();
    Child2* ptr_c_instance2;

    ptr_p_instance2->say2();

    if (ptr_p_instance2 == nullptr){
        std::cout << "error compile" << std::endl;
    }
    ptr_c_instance2 -> say2();


    return 0;


}
