#include <iostream>

void static_cast_prac()
{
    // static_cast
    // ������ ĳ��Ʈ�� �Ϲ� �������� ��ȯ���ش�.

    int d = 65;
    char ch1 = d; // �����Ϸ��� ���������� ĳ������ ���� -> �ٵ� �̤����� �� char�� ù�������� A�� �ٲ�ǰ�??
    char ch2 = static_cast<char>(d); //static_cast�� �ص� ����

    std::cout << "�����Ϸ��� ���������� ĳ���� ���� ��: " << d << std::endl;
    std::cout << "�����Ϸ��� ���������� ĳ���� ���� ��: " << ch1 << std::endl;
    std::cout << "static_cast�� ĳ���� ���� ��: " << ch2 << std::endl << std::endl;

    float b = 12.111;
    int a = static_cast<int>(b);
    std::cout << "�Ǽ�->���� ��ȯ: " << a << std::endl << std::endl;

}

void reterpret_cast_prac(){
    // reterpret_cast
    // �Ϲ������� ������� �������� ������ ����ȣ���� �� ���� �������Ѵ�.
    // ���� ���� �ִ� ��Ʈ���� ���� ���ϴ� ������ �������� ����ȣ���� ������ ���� �������Ѵ�.
    // �����͸� ������ ���Ť�ȣ���ϴ� ���������� �������� ���� ���� ����Ѵ�.

    int a = 10, b = 20;
    int *c = &a;
    int *d = &b;
    std::cout << "�����͸� ������ ��ȯ: " << *c << std::endl; // a��
    std::cout << "�����͸� ������ ��ȯ: " << *d << std::endl; // b��
    a = reinterpret_cast<int>(&b);

    std::cout << "�����͸� ������ ��ȯ: " << a << std::endl; // ����: ������ ����(��, �ּҰ��� ������ ����Ǿ� a�� ����� �� ����)
    std::cout << "�����͸� ������ ��ȯ: " << *c << std::endl;
    std::cout << "�����͸� ������ ��ȯ: " << b << std::endl; // ����: b������ ���� �������� ���� �״�� ���� �Ǵ� ���� �� �� ����
    std::cout << "�����͸� ������ ��ȯ: " << *d << std::endl << std::endl;
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
    // �����ϰ� c��Ÿ���� ����ȯ���� �Ұ����� ĳ����.
    // ��Ӱ��迡 �ִ� Ŭ������ ����ȯ�� �����ϸ�, ���ÿ� �������� �˻��Ѵ�.

//    Truck* pTruck = new Car;
//    Truck* pTruck = dynamic_cast<Truck*>(new Car);

    // ����: �� �𸣰���....
    Parent2* ptr_p_instance2 = new Child2;
//    Parent2* ptr_p_instance2 = dynamic_cast<Parent2*>(new Child2);

    std::cout << std::endl;
}

void const_cast_prac()
{
    // const_cast
    // const �Ӽ��̳� volatile �Ӽ��� ������ ���� ����Ѵ�. ������ ������ ���� volatile Ű���带 ����Ѵ�.
    // �� ����� ������ ������ �����ϰ� ���� ���� ����Ѵ�.


    // 1) pointer ������ Const �����ڸ� �����ϴ� ������
    const int *const_int_ptr = new int(10);
    int *int_ptr;

    std::cout << *const_int_ptr << std::endl;

    int_ptr = const_cast<int*>(const_int_ptr); // const_int_ptr�� const �����ڸ� ��� ����
    *int_ptr = 20; // const_int_ptr�� ���� ����

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

