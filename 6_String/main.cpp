#include <iostream>
#include <string>

// 6.���ڿ�

// 28. C��� ��Ÿ���� ���ڿ�
void example1()
{
    //���ڿ� �Է�
    //C++���� ���̤��ڿ��� �Է¹ޱ� ���ؼ��� ���ڿ��� ����� ������ �迭�� �̸� ���������� ���� ��
//    const int SIZE = 20;
//    char address[SIZE];
//    char name[SIZE];

//    std::cout << "�ڽ��� �̸��� ���ä����ּ���: ";
//    std::cin >> name; //python�� input �̷� ���ä�����. �Է� ���� ���� �̸� ���������ص� name�� ����
//    std::cout << "�ڽ��� �������� �ִ� ���ø� ���ä����ּ��� : ";
//    std::cin >> address;

//    std::cout << address << " �� �������� �ִ� " << name << "��~ ��"; //����ѱ� �� 20����Ʈ �̻��� ���ڿ��� ���Ѥ���� ���α׷� ���������

    //cin��ü�� ���ѱ⸦ ������ ���ڵ� ��θ� ���ڿ��� ������ �ν��ϱ� ������, ���ѱ� ���� ���ڿ��� ��������  get() method�� �̿��ؾ� ��.
//    char address2[SIZE];
//    char name2[SIZE];

//    const int SIZE2 = 20;
//    std::cout << "�ڽ��� �̸��� ���ä����ּ���: ";
//    std::cin.get(name2, SIZE2).get(); //python�� input �̷� ���ä�����. �Է� ���� ���� �̸� ���������ص� name�� ����
//    std::cout << "�ڽ��� �������� �ִ� ���ø� ���ä����ּ��� : ";
//    std::cin.get(address2, SIZE2).get();

//    std::cout << address2 << " �� �������� �ִ� " << name2 << "��~ ��";
//    //�������� -> ����ѱ� �� 20����Ʈ �̻��� ���ڿ��� ���Ѥ���� ���α׷� ���������

    //����+20byte �̻� �Է��ϱ���-cin��ü�� ignore()�޼ҵ� ���
    const int SIZE3 = 20;
    char address3[SIZE3];
    char name3[SIZE3];
    char a[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char b[] = "hello";
    printf("a is : %d, b is : %d\n", sizeof(a), sizeof(b));

    std::cout << "�ڽ��� �̸��� ���ä����ּ���: ";
    std::cin.get(name3, SIZE3).ignore(SIZE3, '\n');
    std::cout << "�ڽ��� ��� ��;���� ���ô�? ";
    std::cin.get(address3, SIZE3).ignore(SIZE3, '\n');

    std::cout << address3 << "�� ��� �ִ�" << name3 << "�� ��";


    //c������ �Է��� ���ڿ��� ���Ӥ��̸� �̸� �˰� ���Ӥ����������, C++�� string�� �̿��ϸ� ���� �����ᰡ��
    std::string address4, name4;

    std::cout << "\n�ڽ��� �̸��� �����ּ���: ";
    getline(std::cin, name4);
    std::cout << "�ڽ��� ��� �ִ� ���ø� �����ּ���: ";
    getline(std::cin, address4);

    std::cout << address4 << " ��� �ִ� " << name4 << "�� ��";


}

int main()
{
    example1();

    return 0;
}
