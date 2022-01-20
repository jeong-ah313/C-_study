#include <iostream>
#include <string>

// 6.문자열

// 28. C언어 스타일의 문자열
void example1()
{
    //문자열 입력
    //C++에서 ㅁㅜㄴ자열을 입력받기 위해서는 문자열이 저장될 문자형 배열을 미리 ㅅㅐㅇ성해 놔야 함
//    const int SIZE = 20;
//    char address[SIZE];
//    char name[SIZE];

//    std::cout << "자신의 이름을 ㅈㅓㄱ어주세요: ";
//    std::cin >> name; //python의 input 이런 ㄱㅓㄴ가봄. 입력 받은 값을 미리 ㅅㅐㅇ성해둔 name에 저장
//    std::cout << "자신이 ㅅㅏㄹ고 있는 도시를 ㅈㅓㄱ어주세요 : ";
//    std::cin >> address;

//    std::cout << address << " 에 ㅅㅏㄹ고 있는 " << name << "님~ ㄳ"; //띄었ㅡ기 및 20바이트 이상의 문자열이 ㄷㅡㄹ어가면 프로그램 강제종료됨

    //cin객체는 띄어ㅆㅡ기를 포함한 문자들 모두를 문자열의 끝으로 인식하기 떄문에, 띄어ㅆㅡ기 포함 문자열을 받으려면  get() method를 이용해야 함.
//    char address2[SIZE];
//    char name2[SIZE];

//    const int SIZE2 = 20;
//    std::cout << "자신의 이름을 ㅈㅓㄱ어주세요: ";
//    std::cin.get(name2, SIZE2).get(); //python의 input 이런 ㄱㅓㄴ가봄. 입력 받은 값을 미리 ㅅㅐㅇ성해둔 name에 저장
//    std::cout << "자신이 ㅅㅏㄹ고 있는 도시를 ㅈㅓㄱ어주세요 : ";
//    std::cin.get(address2, SIZE2).get();

//    std::cout << address2 << " 에 ㅅㅏㄹ고 있는 " << name2 << "님~ ㄳ";
//    //위에ㄲㅓ -> 띄었ㅡ기 및 20바이트 이상의 문자열이 ㄷㅡㄹ어가면 프로그램 강제종료됨

    //띄어쓱ㅣ+20byte 이상 입력하기방법-cin객체의 ignore()메소드 사용
    const int SIZE3 = 20;
    char address3[SIZE3];
    char name3[SIZE3];
    char a[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char b[] = "hello";
    printf("a is : %d, b is : %d\n", sizeof(a), sizeof(b));

    std::cout << "자신의 이름을 ㅈㅓㄱ어주세요: ";
    std::cin.get(name3, SIZE3).ignore(SIZE3, '\n');
    std::cout << "자신이 살고 이;ㅆ는 도시는? ";
    std::cin.get(address3, SIZE3).ignore(SIZE3, '\n');

    std::cout << address3 << "에 살고 있는" << name3 << "님 ㄳ";


    //c언어에서는 입력할 문자열의 ㄱㅣㄹ이를 미리 알고 ㅇㅣㅆ어야하지만, C++는 string을 이용하면 쉽게 ㅎㅐ결가능
    std::string address4, name4;

    std::cout << "\n자신의 이름을 적어주세요: ";
    getline(std::cin, name4);
    std::cout << "자신이 살고 있는 도시를 적어주세요: ";
    getline(std::cin, address4);

    std::cout << address4 << " 살고 있는 " << name4 << "님 ㄳ";


}

int main()
{
    example1();

    return 0;
}
