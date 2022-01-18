#include <iostream>

void example1(){
    //예제1: 부동소수점방식의 오차
    int i;
    float sum = 0;

    for (i = 0; i < 1000; i++)
    {
        sum += 0.1;
    }
    std::cout << "0.1을 1000번 더한 합계는 " << sum << "입니다."<< std::endl;

    //예제2: 묵시적 타입 변환(자동 타입 변환)-컴파일러가 자동으로 수행
    double num1 = 3.1415;
    double num2 = 8.3E12;
    double num3 = 5;

    std::cout << "num1에 저장된 값은 " << num1 << " 입니다." << std::endl;
    std::cout << "num2에 저장된 값은 " << num2 << " 입니다." << std::endl;
    std::cout << "num3에 저장된 값은 " << num3 << " 입니다." << std::endl;

    //산술 연산에서 일어나는 묵시적 타입 변환
    double result1 = 5 + 3.14;
    double result2 = 5.0f + 3.14;

    std::cout << "result1에 저장된 값은 " << result1 << " 입니다." << std::endl;
    std::cout << "result2에 저장된 값은 " << result2 << " 입니다." << std::endl;

    //명시적 타입 변환-강제 타입 변환
    //1.(변환활 타입)변환할 데이터->C, C++ 둘 다 사용 가능
    //2.변환할 타입(변환할 데이터)->C++에서만 사용 가능
    int num4 = 1;
    int num5 = 4;

    double result3 = num4 / num5;
    double result4 = (double) num4 / num5;
    double result5 = double (num4) / num5;


    std::cout << "result3에 저장된 값은 " << result3 << " 입니다." << std::endl; //피연산자 타입과 일치
    std::cout << "result4에 저장된 값은 " << result4 << " 입니다." << std::endl; //피연산자를 double형으로 ㅁㅕㅇ시해줌
    std::cout << "result5에 저장된 값은 " << result5 << " 입니다." << std::endl; //c++에서만 사용 가능한 스타일
    std::cout << std::endl;

}

void example2()
{
    //예제1
    //산술연산자(arthmetic operator)
    //피연산자들의 결합 방향은 왼ㅉㅗㄱ에서 오른ㅉㅗㄱ
    //+: 더하기, -:ㅃㅐ기, *:곱하기, /:나누기, %:나머지
    int num6 = 10;
    int num7 = 4;

    std::cout << " + 연산자에 의한 결과값은 " << num6 + num7 << " 입니다." << std::endl;
    std::cout << " - 연산자에 의한 결과값은 " << num6 - num7 << " 입니다." << std::endl;
    std::cout << " * 연산자에 의한 결과값은 " << num6 * num7 << " 입니다." << std::endl;
    std::cout << " / 연산자에 의한 결과값은 " << num6 / num7 << " 입니다." << std::endl;
    std::cout << " % 연산자에 의한 결과값은 " << num6 % num7 << " 입니다." << std::endl;
    std::cout << std::endl;
}

void example3()
{
    //예제1
    //대입연산자(assignment operator)
    //변수에 값을 대입할 ㄸㅐ ㅅㅏ용하는 이항 연산자, 결합 방향은 오른ㅉㅗㄱ에서 왼ㅉㅗㄱ
    int num1 = 8;
    int num2 = 8;
    int num3 = 8;

    num1 = num1 + 5;
    num2 = num2 += 5; //오른ㅉㅗㄱ에서 왼ㅉㅗㄱ으로 가므로 5+8->num2=13
    num3 =+ 5; //오른ㅉㅗㄱ에서 왼ㅉㅗㄱ으로 가기 ㄸㅐ문에 ㅜnum3은 5가 되버린다.
    //ㄸㅏ라서, +=순서로 해줘야한다.<주의!!>

    std::cout << "- 연산자에 의한 결과 값은 " << num1 << " 입니다." << std::endl;
    std::cout << "+= 연산자에 의한 결과 값은 " << num2 << " 입니다." << std::endl;
    std::cout << "=+ 연산자에 의한 결과 값은 " << num3 << " 입니다." << std::endl;

    //예제2
    //증감 연산자(increment and decrement operator)
    //피연산자를 1ㅆㅣㄱ 증가 혹은 감소 기킬 ㄸㅐ 사용하는 연산자
    //++x: 피연산자 ㄱㅏㅄ을 1 증가시킨 후, 해당 연산을 ㅈㅣㄴ행
    //x++: 먼저 해당 연산을 수행하고 나서, 피연산자의 값을 1증가시킴
    int num4 = 8;
    int num5 = 8;
    int result1, result2;

    result1 = --num4 + 5; //12
    result2 = num5-- + 5; //12

    std::cout << "전위 감소 연산자에 의한 결과값은" << result1 << "이고, 변수 값은 " << num4 << "로 변했습니다." << std::endl;
    std::cout << "후위 감소 연산자에 의한 결과값은" << result2 << "이고, 변수 값은 " << num5 << "로 변했습니다." << std::endl;

    int x = 10;
    int y = x-- + 5 + --x;

    std::cout << "변수 x의 값은 " << x << "이고 변수 y의 값은 " << y << "로 변했습니다." << std::endl;

}


void example4()
{
    //예제1
    //비교연산자(compare operator)
    //피연산자 사이의 상대적인 크기를 판단하는 연산자->어느 ㅉㅗㄱ이 더 큰지, 작은지 서로 같은지~
    //연산은 왼ㅉㅗㄱ에서 오른ㅉㅗㄱ
    //==:왼ㅉㅗㄱ과 오른ㅉㅗㄱ이 같으면 1반환, !=:왼ㅉㅗㄱ의 피연산자와 오른ㅉㅗㄱ의 피연산자가 같지 않으면 1을 반환, >:왼ㅉㅗㄱ의 피연산자가 오른ㅉㅗㄱ의 피연산자보다 크면 1을 반환,
    //...
    //C++에서 거짓(False)은 0이며, 0이 아닌 모든 것은 참(true)으로 인식된다.

   int num1 = 3;
   int num2 = 7;
   std::cout << "!= 연산자에 의한 결괏값은 " << (num1 != num2) << "입니다." << std::endl;
   std::cout << ">= 연산자에 의한 결괏값은 " << (num1 >= num2) << "입니다." << std::endl << std::endl;

}

void example5()
{
    //예제1
    //논리연산자(logical operator)
    //주어진 논리식을 판단하여 참(true), 거짓(False)를 결정하는 연산자
    //AND-&&:모두 참이면 1반환, OR-||:하나라도 참이면 1반환, NOT-!:결과참이면 0, 거짓이면 1반환
    int num1 = 3;
    int num2 = -7;
    bool result1, result2;


    result1 = (num1 > 0) && (num1 < 5);
    result2 = (num2 < 0) || (num2 > 10);

    std::cout << "&& 연산자에 의한 결괏값은 " << result1 << " 입니다." << std::endl;
    std::cout << "|| 연산자에 의한 결괏값은 " << result2 << " 입니다." << std::endl;
    std::cout << "! 연산자에 의한 결과값은 " << !result2 <<" 입니다." << std::endl << std::endl;
}

void example6()
{
    //예제2
    //비트연산자(bitwise operator)
    //비트(bit) 단위로 논리 연산을 할 ㄸㅐ 사용하는 연산자
    //비트 단위로 왼쪾이나 오른쪼ㄱ으로 전체 비트를 이동하거나, 1의 보수를 만들 떄도 사용됩니다.
    //&: 대응되는 비트가 모두 1이면 1을 반환(AND연산), |: 대응되는 비트 ㅈㅜㅇ에서 하나라도 1이면 1을 반환(OR연산),
    //^: 대응되는 비트가 서로 다르면 1을 반환(비트 XOR 연산), ~: 비트를 1이면 0으로, 0이면 1로 반전(NOT연산)
    //<<: 지정한 수만큼 비드들을 전부 왼ㅉㅗㄱ으로 이동시킴, >>:부호를 유지하면서 지정한 수만큼 비트를 ㅈㅓㄴ부 오른ㅉㅗㄱ으로 이동시킴

    int num1 = 15;
    int num2 = 8;

    std::cout << "~ 연산자에 의한 결과값은 " << (~num1) << " 입니다." << std::endl;
    std::cout << "<< 연산자에 의한 결과값은 " << (num2 << 2) << " 입니다." << std::endl;
    std::cout << ">> 연산자에 의한 결과값은 " << (num2 >> 2) << " 입니다." << std::endl;
}

void example7()
{
    //예제1
    //삼항연산자(ternary operator)
    //C, C++에서만 있는 독특한 연산자
    // 조건식 ? 반환값1 : 반환값2 ->조건식이 참이면 반환값1, 거짓이면 반환값2를 출력
    int num1 = 11;
    int num2 = 10;
    int result;

    result = (num1 < num2) ? num1 : num2;

    std::cout << "둘 중 더 작은 수는" << result << "입니다." << std::endl << std::endl;

    //예제2
    //쉼표연산자
    //얼핏 연산자가 아닌 것처럼 보이지만 다양한 용도로 사용되는 연산자
    //두 연산식을 하나의 연산식으로 나타내고자 할ㄸㅐ, 둘 이상의 인수를 함수로 전달하고자 할 ㄸㅐ 사용한다.

    int num3 = 15, num4 = 8; // 둘 이상의 변수를 ,(쉼표)로 동시에 선언
    std::cout << "첫번ㅉㅐ 수는" << num3 << ".이고, 두번 쨰 수는 " << num4 << "입니다." << std::endl;

    //예제3
    //size of 연신지
    //사용자의 컴퓨터 환경에 ㄸㅏ라 타입에 할당되는 메모리 의 크기가 달라 질 수 있다. sizeof연산자는 단항 연산자로 피연산자의 크기를 바이트 단위로 반환한다.
    std::cout << "char형 데이터에 할당되는 메모리의 크기는" << sizeof(char) << "바이트입니다." << std::endl;
    std::cout << "short형 데이터에 할당되는 메모리의 크기는" << sizeof(short) << "바이트입니다." << std::endl;
    std::cout << "int형 데이터에 할당되는 메모리의 크기는" << sizeof(int) << "바이트입니다." << std::endl;
    std::cout << "long형 데이터에 할당되는 메모리의 크기는" << sizeof(long) << "바이트입니다." << std::endl;
//    std::cout << "long long형 데이터에 할당되는 메모리의 크기는" << sizeof(long long) << "바이트입니다." << std::endl;
    std::cout << "float형 데이터에 할당되는 메모리의 크기는" << sizeof(float) << "바이트입니다." << std::endl;
    std::cout << "double형 데이터에 할당되는 메모리의 크기는" << sizeof(double) << "바이트입니다." << std::endl;
//    std::cout << "long double형 데이터에 할당되는 메모리의 크기는" << sizeof(long double) << "바이트입니다." << std::endl;
}

void example8()
{
    //예제1
    //범위 지정 연산자(scope resolution operator)
    //C++에서 가장 우선순위가 높은 연산자가 범위 지정 연산자
    /*
    1.::식별자
    2.클래스이름::식별자
    3.네임스페이스::식별지
    4.열거체::식별자
    */

    //예제2
    //멤버 포인터 연산자(pointer-to-member operator)
    //멤버 포인터 연산자를 사용하여 클래스의 멤버를 가리키는 포인터를 정의
    //1. 왼쪼ㄱ의 피연산자가 클래스 타입의 객체인 경우:.*
    //2. 왼ㅉㅗㄱ의 피연산자가 클래스 타입의 객체를 가리키는 포인터인 경우: ->*

    //예제3
    //typeid 연산자
    //객체의 타입에 관한정보를 확인
    //typeid(표현식)


}

int main()
{
    example1();
    example2();
    example3();
    example4();
    example5();
    example6();
    example7();

    return 0;
}
