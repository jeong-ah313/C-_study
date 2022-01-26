#include <iostream>
void swap1(int num1, int num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

void swap2(int &num1, int &num2)
{
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    int a = 20;
    int b = 60;

//    swap1(a,b);
    swap2(a,b);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    return 0;
}
