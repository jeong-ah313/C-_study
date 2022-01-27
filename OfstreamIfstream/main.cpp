#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

// <ifstream> : input file stream
// 1. 파일을 열ㄸㅐ 사용하는 open 함수
// 함수원형: void open(const char* fileName, ios_base::openmode mode = ios_base::in);
// 함수원형: viod open(const string& fileName, ios_base::openmode mode = ios_base::in);
// 함수설명: 첫번ㅉㅐ 인자로 open할 파일 이름이 들어가고, 두번ㅉㅐ 인자로 오픈할 모드이다. 오픈 할 파일을 어떤식으로 사용할지에 따라 모드를 정하면 된다.
// ios_base::in - 파일을 read할 목적으로 open할 것이다.
// ios_base::out - 파일에 write할 목적으로 open할 것이다.
// ios_base::binary = 파일을 바이너리(이진수) 형태로 open할 것이다.
// +) ate, app, trunc의 모드도 존재한다.

// 2. 열렸는지 확인하는 is_open 함수
// 함수 원형: bool is_open() const; - 파일이 열렸는지 확인하는 함수

// 3. 파일을 열었으면 닫는 close 함수
// 함수원형: void close(); - 파일과의 연결을 닫아버리는 ㅎㅏㅁ수

// 4. char 하나씪 파일에서 프로그램으로 읽어오는 get 함수
// 함수원형: istream& get (char& c); - 읽은 ㅍㅏ일에서 한 char로 읽어서 매개변수로 넣은 c에 넣어줌
//char c;
//while(readFile.get(c))   ------> like 가져와서 (get해서) c에 넣어라.
//{
//    // 읽은 char가 c에 들어있습니다.
//    std::cost << c;
//}

// 5. 한줄씪 읽어오는 getline 함수
// 함수원형: istream & getline(char* str, streamsize len); - 한줄씪 문자열을 읽어서 str에 저장해주는 함수
// iftream::getline() 함수는  문자열을 받아오는 형태가 char* 타입이기 ㄸㅐ문에 string 타입으로 바로 받을 수 없다는 특징이 있음..이 무슨말인지ㅠㅠ\

// 6. eof 함수
// 함수원형: bool eof() const; - 파일의 끝이 나오면 true를 반환하고 아니면 false를 반환


// <ofstream> : output file stream
// 프로그램의 출력을 파일에 할 수 있게 돕는 클래스

// 1. 파일을 열 ㄸㅐ 사용하느 open 함수
// 함수 원형: void open (const char* fileName, ios_base::openmode mode = ios_base::out);
//           void open (const string& fileName, ios_base::openmode mode = ios_base::out);
// 함수 설명: 첫번ㅉㅐ 인자는 파일 이름, 두벼ㅓㄴㅉㅐ 인자는 디폴트값 out

// 2. 파일이 열렸는지 확인하는 is_open 함수
// 함수 원형: bool is_open() const; - 파일이 열렸는지 확인하는 ㅎㅏㅁ수

// 3. close 함수
// 함수 원형: void clos(); - 파일과의 연결을 닫아버리는 함수

// 4. write 함수
// 함수 원형: ostream& write(const char* str, streamsize n); - 첫번ㅉㅐ ㅁㅐ개변수로 받은 캐릭터 포인터 타입의 문자열의 n만큼의 ㄱㅣㄹ이만큼 파일에 write하는 함수


// ---------------------------------------------
// 이러한 ifstream, ofstream 클래스를 합쳐서 파일 입출력 클래스라고 한다.

int main(void)
{

    // ifstream

    // 파일 읽기1
    std::cout << "파일읽기1" << std::endl;

    std::ifstream fin("test.txt"); // fin 객체 생성(cin 처럼 이용!)
    if (!fin)
    {
        std::cout << "Error, no such file exists" << std::endl;
        exit(100);
    } // 파일 열림 확인

    std::string str;
    while (getline(fin, str)) // 파일이 끝날때까지 한 줄씩 읽어오기
    {
        std::cout << str << std::endl;
    }

    fin.close(); // 파일 닫기

    std::cout << std::endl;

    // 파일 읽기2
    std::cout << "파일읽기2(얜 여는 연습만해서 출력 안됨)" << std::endl;

    std::ifstream ifs; // ifs라는 ifstream 객체를 생성함
    ifs.open("test.txt"); // ifs를 test와 연결함
    // 파일 내용 읽기
    char ch;
    char buf[20];
    std::string str2;
    ifs >> ch; // test.txt 파일에서 한 문자를 읽어 변수 ch에 저장함
    ifs.getline(buf, 20); // test.txt. 파일에서 한 행을 읽어 배열 buf에 저장
    getline(ifs, str);
    ifs.close(); // 닫기

    // 파일 읽기3 - 한줄씪 읽어오기
    std::cout << "파일읽기3" << std::endl;

    std::ifstream ifs2;
    std::string str3;

    ifs2.open("test.txt");
    if(!ifs2.is_open())
    {
        std::cout << "파일을 열 수가 없습니다." << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "파일을 성공적으로 열었습니다." << std::endl;
        getline(ifs2, str3);
        std::cout << str3 << std::endl;
        ifs2.close();
    }

    std::cout << std::endl;

    // 파일 읽기 4
    std::cout << "파일읽기4" << std::endl;

    std::ifstream input("test.txt"); // 읽기 파일 열기

    while (!input.eof()) // 파일 끝인지 확인
    {
        getline(input, str); //string str로 파일에 라인데이터 읽기
        std::cout << str << std::endl;
    }
    input.close(); // 파일 닫기


    // ofstream
    // 파일 쓰기
    std::cout << "\n 파일쓰기1" << std::endl;

    std::ofstream output("test_prac.txt"); // 쓰기 파일 열기
    output << "Hello C++!" << std::endl; // 파일에 쓰기
    output.close(); // 파일 닫기

    //----------------------
    // 전체적인 파일 입출력

    std::string str4;
    std::ofstream output2("test2.txt"); // 쓰기 파일 열기

    output2 << "Hello world~" << std::endl;
    output2 << "Hello everyone^^" << std::endl;
    output2.close();

    std::ifstream input2("test2.txt");  // 읽기 파일 열기

    while(!input2.eof())
    {
//        getline(input2, str4);
        char str4[100];
        input2.getline(str4, 100);
        std::cout << str4 << std::endl;
    }
    input2.close();


    // -------------------------------------------------------------------------------------
    // csv 파일 처리
    // ifstream과 ostream을 각각 사용하지 않고, fstream만을 이용해서 입출력할 수 있음! *0*!
    // 형식
//    std::fstream fs;
//    fs.open("파일명", ios::in or ios::out); // in은 해당 위치에 파일이 읽겠다는 의미, out은 해당 위치에 파일을 쓰겠다는 의미
//    fs.close();

    std::cout << "csv파일읽기1" << std::endl;

    std::string str5;
    std::fstream fs;

    fs.open("csv_prac.csv", std::ios::in);

    while(!fs.eof())
    {
        getline(fs, str5);
        std::cout << str5 << std::endl;
    }
    fs.close();



//    std::ifstream file("test.txt");

//    while (!file.eof())
//        std::cout << file.get();



    // 파일읽기 예제
//    std::ifstream readFile; // readFile이라는 ifstream 객체를 생성
//    readFile.open("test.txt"); // readFile를 test.txt와 연결함
////    ifstream readFile("test.txt");

//    char ch;
//    char buf[20];
//    std::string str;
//    readFile >> ch;
//    readFile.getline(buf, 20); // example.txt 파일에서 한 행을 읽어 배열 buf에 저장함
//    getline(readFile, str); // example.txt 파일에서 한 행을 읽어 문자열 객체인 str에 저장함

//    for (int i = 0; bool eof() const == True;  )
//    std::cout << &buf[1] << std::endl;

//    // 파일 닫기
//    readFile.close(); // 파일과의 연결을 닫음


    return 0;

}
