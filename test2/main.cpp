#include <iostream>
//#include <QTextCodec>
//using namespace std;

int main()
{

    //예제1
    int a = 10;

    // 여러가지 진법으로 표현된 정수형 상수의 출력을 위해 cout 객체는 dec, hex, oct 조정자를 제공한다.

    std::cout << "숫자 10을 10진수로 표현하면 " << a << "이며," << std::endl;
    std::cout << std::oct; //8진수로 바ㄲㅝ줌
    std::cout << "숫자 10을 8진수로 표현하면 " << a << "이며," << std::endl;
    std::cout << std::hex; //16진수 문자열로 바꿔줌
    std::cout << "숫자 10을 16진수로 표현하면 " << a << "입니다." << std::endl;

    //이진 리터럴 상수
    auto a2 = 0B010111; //auto키워드로 변수 선언 시, 초깃값과 같은 타입으로 변수를 선언 가능

    std::cout << "리터럴 상수:0B010111 일ㄸㅐ:" << a2 << "입니다" << std::endl;

    //심볼릭 상수
    const int ages = 30; //const키워드는 변수 선언 시, 절대 변경하면 안되는 값들을 위해 사용된다. +)상수 선언과 함ㄲㅔ 반드시 초기화 해야 함

    std::cout << "심볼릭상수" << ages << std::endl;

    //예제2
    //int형 타입의 변수에 해당 타입이 저장할 수 있는 최댓값과 그 최댓값을 넘는 숫자를 대입하는 예제
    int num = 2147483647;
    std::cout << "변수 num에 저장된 값은" << num << "입니다." << std::endl; //num 값 이상하게 출력 됨;;
    num = -2147483648;
    std::cout << "변수 num에 저장된 값은 " << num << "입니다." << std::endl;

    //소수점을 16자리 가지는 실수를 float 타입과 double 타입의 변수에 각각 대입하는 예제
    std::cout.precision(10); //자릿수 표현
    float num01 = 3.1415926535897932; //float 타입의 유효 자릿수는 소수점 6자리
    std::cout << "변수 num01에 저장된 값은 " << num01 << "입니다." << std::endl;
    double num02 = 3.1415926535897932; // double 타입의 유효 자릿수는 소수점 16자리
    std::cout << "변수 num02에 저장된 값은 " << num02 << "입니다." << std::endl;

}
