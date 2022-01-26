#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    // vector container란? 자동으로 메모리가 할당되는 배열이라고 생각하면 좋다.
    // 맨 뒤쪾에서 삽입과 삭제가 ㄱㅏ능하다(자료구조 스택 느낌과 비슷).But! 배열 기반이므로 삽입 삭제가 빈번하게 일어난다면 비효율적임

    // vector 형식
    // 1. vector<자료형> 변수명 --> 벡터 생성
    // 2. vector<자료형> 변수명(숫자) --> 숫자만큼 벡터 생성 후 0으로 초기화
    // 3. vector<자료형> 변수명 = {변수1, 변수2, 변수3} --> 벡터 생성 후 오른쪾 변수 값으로 초기화
    // 4. vector<자료형> 변수명[] = {, } --> 벡처 배열(2차원 벡터)선언 및 초기화(열은 고정, 행은 가변
    // 5. vector<vector<자료형>> 변수명 --> 2차원 벡터 ㅅㅐㅇ성(열과 행 모두 가변)
    // 6. vector<자료형>변수명.assign(범위, 초기화할 값) --> 벡터의 범위 내에서 해당 값으로 초기화


    // int형 벡터 생성
    std::vector<int> v1;

    // int형 벡터 생성 후 크기를 4로 할당(모든 벡터요소 0으로 초기화)
    std::vector<int> v2(4);

    // int형 벡터 생성 후 크기가 5개이고, 값들을 모두 2로 초기화
    std::vector<int> v3(5, 2);

    // int형 벡터 생성 후 1,2,3으로 초기화
    std::vector<int> v4 = {1, 2, 3};

    // int형 벡터 배열 생성(행은 가변이지만 열은 고정) - (열은 2개로 고정!)
    std::vector<int> v5[] = {{1, 2},
                             {3, 4}};

    // 2차원 벡터 생성(행과 열 모두 가변)
    std::vector<std::vector<int>> v6;

    // 벡터 범위를 5로 지정하고 정수 10으로 초기화
    std::vector<int> v7 = {1, 2, 3, 4, 5};
    v7.assign(5, 10); //assign()함수를 통해 5개의 배열값을 10으로 재정의


    // vector의 멤버 함수
    std::vector<int> v = {1, 2, 3, 4};

    v.assign(5,2); // 2의 값으로 5개의 원소 할당
    v.at(3); // 형식: v.at(index) --> index번쨰 원소를 참조함.(v[index]보다 속도는 느리지만, 범위를 점검하므로 안전)
    v[3]; // 형식: v[index] --> index번ㅉㅐ 원소를 참조함. 점검 안해서 속도 ㅃㅏ름
    v.front(); // 첫번ㅉㅐ 원소를 참조
    v.back(); // 마지막 원소를 참조
    v.clear(); // 모든 원소를 제거, 원소만 제거하고 메모리는 남이있음. size만 줄고, capacity는 그대로 남아있음
    v.push_back(1); // 마지막 원소 뒤에 원소 1을 삽입
    v.pop_back(); // 마지막 원소를 제거
    v.begin(); // 첫번ㅉㅐ 원소를 가리킴(itr과 함꼐 사용)
    v.end(); // 마지막의 "다음"을 가리킴(itr과 함꼐 사용)
    v.rbegin(); // reverse begin을 가리킨다(거꾸로해서 첫번ㅉㅐ 원소를 가리킴)
    v.rend(); // reverse end을 가리킨다(거꾸로 해서 마지막의 ㄷㅏ음을 가리킴)
    v.reserve(4); // 형식: v.reserve(n) --> n개의 원소를 저장할 위치를 예약합니다.(동적 할당 해놈)
    v.resize(10); // 형식: v.resize(n) --> 크기를 n으로 변경한다. 이전보다 크기가 커졌을 경우, 디폴트 값은 0
    v.resize(15, 3); // 크기를 n으로 변경, 디폴트 값은 3
    v.size(); // 원소의 갯수 리턴
    v.capacity(); // 할당된 공간의 크기를 리턴한다.
    v.swap(v1); // v1과 v2의 원소와 capacity 바꿔줌(모든 것을 스왑)
  /*  v.insert(2, 3, 4); // 2번ㅉㅐ 위치에 3개의 4값을 삽입한다. (뒤에 값들은 뒤로 밀림)
    v.insert(2, 3);
    v.erase(2); // 파라미터를 하나 받는 경우에는 벡터의 itr 위치의 인자를 삭제
    v.erase(1,3);*/ //파라미터를 두개 받는 경우에는 [1,3)의 범위의 인자를 삭제(1이상 3이하의 범위의 인자들 삭제)
    v.empty(); // 비어있는지 검사


    // vector의size와 capacity와의 관계
    v.size(); // 원소개수 리턴
    v.capacity(); // 할당된 공간의 크기를 리턴
    // capacity는 미리 정해준 만큼 동적할당을 미리 한다.






    // vector의 iterator(반복자)
    // v.begin() --> 벡터 시작점의 주소 값 반환
    // v.end() --> 벡터(끝부분+1) 주소값 반환
    // v.rbegin() --> (revers begin의 약자) 벡터의 끝 지점을 시작점으로 반환
    // v.rend() --> (revers end의 약자) 벡터의(시작+1) 지점을 끝 부분으로 반환

//    std::vector<int> v = {1, 2, 3, 4};

    for_each(v.begin(), v.end(), [&](int& n){
        std::cout << n << std::endl;
    });

    return 0;

}
