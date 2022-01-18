#include <iostream>
/*조건문
    제어문의 종류: 조건문, 반복문
*/

void example1()
{
    //예제1
    //조건문의 종류: if문, if/else문, if/else if/else문, swiitch문
    //if문-결과가 참이면 주어진 명령을 실행하고, 거짓이면 아무것도 실행하지 않는다.
    int num = 10;

    if (num < 5)
    {
        std::cout << "입력하신 수는 5보다 작습니다." << std::endl;

    }
    if (num == 5)
    {
        std::cout << "입력하신 수는 5입니다." << std::endl;
    }
    if (num > 5)
    {
        std::cout << "입력하신 수는 5보다 큽니다." << std::endl;
    }

    //예제2
    //if/else문-주어진 조건식의 결과가 거짓이면 주어진 명령문을 실행한다
    if (num < 5)
    {
        std::cout << "입력하신 수는 5보다 작습니다." << std::endl;
    }
    else
    {
        if(num == 5)
        {
            std::cout << "입력하신 수는 5입니다." << std::endl;
        }
        else
        {
            std::cout << "입력하신 수는 5보다 큽니다." << std::endl;
        }
    }

    //예제3
    //if / else if /else문
    if (num<5)
    {
        std::cout << "입력하신 수는 5보다 작습니다." <<std::endl;
    }
    else if (num == 5)
    {
        std::cout << "입력하신 수는 5입니다." << std::endl;
    }
    else
    {
        std::cout << "입력하신 수는 5보다 큽니다." << std::endl;
    }

    //예제4
    //switch문
    switch (num)
    {
    case 1:
        std::cout << "입력하신 수는 1입니다." << std::endl;
        break;
    case 2:
        std::cout << "입력하신 수는 2입니다." << std::endl;
        break;
    case 3:
        std::cout << "입력하신 수는 3입니다." << std::endl;
        break;
    case 4:
        std::cout << "입력하신 수는 4입니다." << std::endl;
        break;
    case 5:
        std::cout << "입력하신 수는 5입니다." << std::endl;
        break;
    default:
        std::cout << "1부터 5까지의 수만 입력해 주세요!" << std::endl;
       break;


    }
}

void example2()
{
    //예제1
    //반복문(iteration statements)-프로그램 내에서 똒같은 명령을 일정 횟수만큼 수행하도록 제어하는 명령문
    //while문, do/while문, for문, 범위 기반의 for문

    //while문-특정 조건을 만족할 떄까지 계소개서 주어진 명령문을 반복 실행
    int i = 0;
    int num = 5;


    while (i < num)
    {
        std::cout <<"whie문이 현재" << i+1 << "번ㅉㅐ 반복 실행중입니다." << std::endl;
        i++; //이 부분을 삭제하면 무한 루프에 빠지게 된다.
    }
    std::cout << "while문이 종료된 후 변수 i의 값은" << i << "입니다." << std::endl; //i값이 5가되서 반복문에 들어갈 수 없게 된 것

    //예제2
    //do-while문:while문을 실행하기 전에 조건문부터 검사, 따라서 조건문은 무조건 1번은 실행하게 됨

    do {
        std::cout << "do / while문이 현재" << i + 1 << "번쨰 수행중입니다." << std::endl;
        i++;
    } while (i < num);
    std::cout << "do-while문이 종료된 후 변수 i 값은" << i << "입니다." << std::endl;

    //예제3
    //for문<->while문: for문은 while문과 달리 자체적으로,초기식, 조건식, 증감식을 모두 포함하고 있는 반복문
    for (i = 0; i < num; i++)
    {
        std::cout << "for문이 현재" << i + 1 << "번쨰 반복 수행중입니다." << std::endl;
     }
    std::cout << "for문이 종료된 후 변수 i의 값은 " << i << "입니다." << std::endl;
    //단, for문은 for문에서 직접 선언된 변수는 for문이 종료되면 같이 소멸된다.

    //예제4
    //단위 기반의 for문: 범위 기반의 for문은 표현식 안에 포함되어 있는 모든 값에 대래 한 번씪 루프를 실행해줌
    int arr[5] = {1,3,5,7,9};

    for (int element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;


}

//22.기타제어문
void example3()
{
    //continue문, break문, goto문- continue와 break문은 루프의 흐름을 사용자가 직접 제어할 수 있도록 도와준다.

    //예제1
    //continue문: 루프 내에서 해당 루프의 나머지 부분을 건너뛰고, 바로 다음 조건식의 판단으로 넘겨준다
    int except_num = 2;

    for (int i = 1; i <= 100; i++)
    {
        if (i % except_num == 0)
        {
            continue;
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //예제2
    //break문: 루프 내에서 사용하여 해당 반복문을 완전히 종료시킨 뒤, 반복문 바로 다음에 위치한 명령문을 실행
    //즉, 반복문을 완전히 빠져 나갈 떄 사용!
    int num = 1, sum =0;
    int end_num = 10;

    while (1) //무한루프
    {
        sum += num;
        if (num == end_num)
        {
            break;
        }
        num++;
    }
    std::cout << "1부터" << end_num << "까지 더한 것은 " << sum << " 입니다." << std::endl;
}


int main()
{
    example1();
    example2();
    example3();

}
