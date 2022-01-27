#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <QVector>

// 추후에 배울 QT에 대해서..잠깐...
template <typename T>
T sum(T a, T b)
{
    return a + b;
}

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

    std::cout << sum(10.1, 20.2) << std::endl;

    // int형 벡터 생성
    std::vector<int> v1;
    QVector<int> qv1;
    qv1.push_back(1);

    // int형 벡터 생성 후 크기를 4로 할당(모든 벡터요소 0으로 초기화)
    std::vector<int> v2(4);

    // int형 벡터 생성 후 크기가 5개이고, 값들을 모두 2로 초기화
    std::vector<int> v3(5, 2);

    // int형 벡터 생성 후 1,2,3으로 초기화
    std::vector<int> v4 = {1, 2, 3};

    for (int i = 0; i < v4.size(); ++i)
    {
        std::cout << v4[i] << std::endl;
    }

    for(const auto& e : v4)
    {
        std::cout << e << std::endl;
    }

    // STL 스탠다드 템플릿 라이브러리
    std::vector<int>::iterator it = v4.begin();
    for(/*생략*/; it != v4.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

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
    v.size(); // 원소의 갯수 리턴 (vector의size와 capacity와의 관계)
    v.capacity(); // 할당된 공간의 크기를 리턴한다.capacity는 미리 정해준 만큼 동적할당을 미리 한다.
//    v.swap(v1); // v1과 v2의 원소와 capacity 바꿔줌(모든 것을 스왑)
    v.insert(v.begin() + 2, 3, 4); // 2번ㅉㅐ 위치에 3개의 4값을 삽입한다. (뒤에 값들은 뒤로 밀림)
//    v.insert(2, 3);
    v.erase(v.begin()); // 파라미터를 하나 받는 경우에는 벡터의 itr 위치의 인자를 삭제
//    v.erase(1,3); //파라미터를 두개 받는 경우에는 [1,3)의 범위의 인자를 삭제(1이상 3이하의 범위의 인자들 삭제)
    v.empty(); // 비어있는지 검사

    // vector의 iterator(반복자)
    // v.begin() --> 벡터 시작점의 주소 값 반환
    // v.end() --> 벡터(끝부분+1) 주소값 반환
    // v.rbegin() --> (revers begin의 약자) 벡터의 끝 지점을 시작점으로 반환
    // v.rend() --> (revers end의 약자) 벡터의(시작+1) 지점을 끝 부분으로 반환





    // -------------------------------------------------------------------------------------------------------------
    // list
    // C++의 list는 더블 링크드 리스트와 비슷하다. -> 노드 기반 컨테이너
    // 정렬(sort), 합치기(merge), 이어붙이기(splice)가 있음
    // 벡터와 마찬가지로, push_front(), push_back(), pop_front(), pop_back(), insert(), erase() 멤버함수가 있음
    // 벡터와 다르게, at, [] 연산자가 존재하지 ㅇ낳는다. 반복자 ++, --로 전급해야 함
    // 형식: list<[Data type]> [변수이름];

    // 관련 함수 정리
    // 반복자
    // begin(): beginning iterator 반환
    // end(): end iterator 반환
    // 삽입
    // push_front(): 리스트 맨 앞의 원소 삭제
    // pop_back(): 리스츠 맨 뒤의 원소 삭제
    // erase(iterator): iterator가 가리키는 부분의 원소 삭제
    // 조회
    // *iterato: iterator가 가리키는 원소에 접근
    // front(): 첫번ㅉㅐ 원소 반환
    // back(): 마지막 원소 반환
    // 기타
    // empty(): 리스트가 비어있는지 여부
    // size(): 리스트 사이즈 반환

    // 리스트 생성
    std::list<int> a;

    // 원소 추가
    a.push_back(22);
    a.push_back(33);
    a.push_front(11);
    a.push_back(44);
    a.push_back(55);

    // 반복자 생성
    std::list<int>::iterator iter = a.begin();

    // 리스트 출력
    for (iter=a.begin(); iter != a.end(); ++iter)
    {
        std::cout << *iter << std::endl; // 원본 리스트: 11 22 33 44 55
    }

   std::cout << "" << std::endl;

   // 원소 삭제
   a.pop_front();
   a.pop_back();

   for(iter=a.begin(); iter != a.end(); ++iter)
   {
       std::cout << *iter << std::endl; // 원소 삭제 후: 22 33 44
    }

   std::cout << "" << std::endl;

   // 리스트 사이즈
   std::cout << a.size() << std::endl;


   // 리스트가 비어있는지 확인
   std::cout << a.empty() << std::endl;

   // 리스트의 첫번ㅉㅐ 원소 확인
   std::cout << a.front() << std::endl;

//   // 반복자 2번ㅉㅐ 위치로 이동
//   iter++;
//   iter++;
//   a.insert(iter, 55555);
//   for(iter=a.begin(); iter != a.end(); ++iter)
//   {
//       std::cout << *iter << std::endl; //22.
//   }




   // -------------------------------------------------------------------------------------------------------------
   // map
   // 맵 기본 함수

   // 기본 형태
   // map<key, value>: key와 value를 pair 형태로 선언합니다.

   // iterator(반복적)
   // begin(): beginning iterator를 반환
   // end(): end iterator를 반환

   // 추가 및 삭제
   // insert(make_pair(key, value)): 맵에 원소를 pair 형태로 추가
   // erase(key): 맵에서 key(키 값)에 해당하는 원소 삭제
   // clear(): 맵의 원소를 모두 삭제

   // 조회
   // find(key): key(키값)에 해당하는 iterator를 반환
   // count(key): key(키값)에 해당하는 원소들(vlaue들)의 개수를 반환

   // 기타
   // empty(): 맵이 비어있으면 true 아니면 false를 반환
   // size(): 맵 원소들의 수를 반환

   //맵 생성
   // <string, int> => <key, value>
   std::map<std::string, int> m;

   // insert(key, value)
   m.insert(std::make_pair("a",1));
   m.insert(std::make_pair("b", 2));
   m.insert(std::make_pair("c", 3));
   m.insert(std::make_pair("d", 4));
   m.insert(std::make_pair("e", 5));
   m["f"] =6; // also possible

   // erase(key)
   m.erase("d");
   m.erase("e");
   m.erase(m.find("f")); // also posiible

   // empty(), size()
   if(!m.empty()) std::cout << "m size: " << m.size() << '\n';

   // find(key)
   // first: key값을 가리킴, second: value값을 가리킴
   std::cout << "a: " << m.find("a")->second << '\n';
   std::cout << "b: " << m.find("b")->second << '\n';

   // count(key)
   std::cout << "a count: " << m.count("a") << '\n';
   std::cout << "a count: " << m.count("b") << '\n';

   // begin(), end()
   std::cout << "traverse" << '\n';

   // map<stirnf, int>::iterator it; also possible
   for (auto it = m.begin(); it != m.end(); it++)
   {
       std::cout << "key: " << it->first << " " << "value: " << it->second << '\n';
   }


    return 0;

}
