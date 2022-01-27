#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

// <ifstream> : input file stream
// 1. ������ ������ ����ϴ� open �Լ�
// �Լ�����: void open(const char* fileName, ios_base::openmode mode = ios_base::in);
// �Լ�����: viod open(const string& fileName, ios_base::openmode mode = ios_base::in);
// �Լ�����: ù������ ���ڷ� open�� ���� �̸��� ����, �ι����� ���ڷ� ������ ����̴�. ���� �� ������ ������� ��������� ���� ��带 ���ϸ� �ȴ�.
// ios_base::in - ������ read�� �������� open�� ���̴�.
// ios_base::out - ���Ͽ� write�� �������� open�� ���̴�.
// ios_base::binary = ������ ���̳ʸ�(������) ���·� open�� ���̴�.
// +) ate, app, trunc�� ��嵵 �����Ѵ�.

// 2. ���ȴ��� Ȯ���ϴ� is_open �Լ�
// �Լ� ����: bool is_open() const; - ������ ���ȴ��� Ȯ���ϴ� �Լ�

// 3. ������ �������� �ݴ� close �Լ�
// �Լ�����: void close(); - ���ϰ��� ������ �ݾƹ����� ��������

// 4. char �ϳ��� ���Ͽ��� ���α׷����� �о���� get �Լ�
// �Լ�����: istream& get (char& c); - ���� �����Ͽ��� �� char�� �о �Ű������� ���� c�� �־���
//char c;
//while(readFile.get(c))   ------> like �����ͼ� (get�ؼ�) c�� �־��.
//{
//    // ���� char�� c�� ����ֽ��ϴ�.
//    std::cost << c;
//}

// 5. ���ٝ� �о���� getline �Լ�
// �Լ�����: istream & getline(char* str, streamsize len); - ���ٝ� ���ڿ��� �о str�� �������ִ� �Լ�
// iftream::getline() �Լ���  ���ڿ��� �޾ƿ��� ���°� char* Ÿ���̱� �������� string Ÿ������ �ٷ� ���� �� ���ٴ� Ư¡�� ����..�� �����������Ф�\

// 6. eof �Լ�
// �Լ�����: bool eof() const; - ������ ���� ������ true�� ��ȯ�ϰ� �ƴϸ� false�� ��ȯ


// <ofstream> : output file stream
// ���α׷��� ����� ���Ͽ� �� �� �ְ� ���� Ŭ����

// 1. ������ �� ���� ����ϴ� open �Լ�
// �Լ� ����: void open (const char* fileName, ios_base::openmode mode = ios_base::out);
//           void open (const string& fileName, ios_base::openmode mode = ios_base::out);
// �Լ� ����: ù������ ���ڴ� ���� �̸�, �κ��ä����� ���ڴ� ����Ʈ�� out

// 2. ������ ���ȴ��� Ȯ���ϴ� is_open �Լ�
// �Լ� ����: bool is_open() const; - ������ ���ȴ��� Ȯ���ϴ� ��������

// 3. close �Լ�
// �Լ� ����: void clos(); - ���ϰ��� ������ �ݾƹ����� �Լ�

// 4. write �Լ�
// �Լ� ����: ostream& write(const char* str, streamsize n); - ù������ ������������ ���� ĳ���� ������ Ÿ���� ���ڿ��� n��ŭ�� ���Ӥ��̸�ŭ ���Ͽ� write�ϴ� �Լ�


// ---------------------------------------------
// �̷��� ifstream, ofstream Ŭ������ ���ļ� ���� ����� Ŭ������� �Ѵ�.

int main(void)
{

    // ifstream

    // ���� �б�1
    std::cout << "�����б�1" << std::endl;

    std::ifstream fin("test.txt"); // fin ��ü ����(cin ó�� �̿�!)
    if (!fin)
    {
        std::cout << "Error, no such file exists" << std::endl;
        exit(100);
    } // ���� ���� Ȯ��

    std::string str;
    while (getline(fin, str)) // ������ ���������� �� �پ� �о����
    {
        std::cout << str << std::endl;
    }

    fin.close(); // ���� �ݱ�

    std::cout << std::endl;

    // ���� �б�2
    std::cout << "�����б�2(�� ���� �������ؼ� ��� �ȵ�)" << std::endl;

    std::ifstream ifs; // ifs��� ifstream ��ü�� ������
    ifs.open("test.txt"); // ifs�� test�� ������
    // ���� ���� �б�
    char ch;
    char buf[20];
    std::string str2;
    ifs >> ch; // test.txt ���Ͽ��� �� ���ڸ� �о� ���� ch�� ������
    ifs.getline(buf, 20); // test.txt. ���Ͽ��� �� ���� �о� �迭 buf�� ����
    getline(ifs, str);
    ifs.close(); // �ݱ�

    // ���� �б�3 - ���ٝ� �о����
    std::cout << "�����б�3" << std::endl;

    std::ifstream ifs2;
    std::string str3;

    ifs2.open("test.txt");
    if(!ifs2.is_open())
    {
        std::cout << "������ �� ���� �����ϴ�." << std::endl;
        exit(1);
    }
    else
    {
        std::cout << "������ ���������� �������ϴ�." << std::endl;
        getline(ifs2, str3);
        std::cout << str3 << std::endl;
        ifs2.close();
    }

    std::cout << std::endl;

    // ���� �б� 4
    std::cout << "�����б�4" << std::endl;

    std::ifstream input("test.txt"); // �б� ���� ����

    while (!input.eof()) // ���� ������ Ȯ��
    {
        getline(input, str); //string str�� ���Ͽ� ���ε����� �б�
        std::cout << str << std::endl;
    }
    input.close(); // ���� �ݱ�


    // ofstream
    // ���� ����
    std::cout << "\n ���Ͼ���1" << std::endl;

    std::ofstream output("test_prac.txt"); // ���� ���� ����
    output << "Hello C++!" << std::endl; // ���Ͽ� ����
    output.close(); // ���� �ݱ�

    //----------------------
    // ��ü���� ���� �����

    std::string str4;
    std::ofstream output2("test2.txt"); // ���� ���� ����

    output2 << "Hello world~" << std::endl;
    output2 << "Hello everyone^^" << std::endl;
    output2.close();

    std::ifstream input2("test2.txt");  // �б� ���� ����

    while(!input2.eof())
    {
//        getline(input2, str4);
        char str4[100];
        input2.getline(str4, 100);
        std::cout << str4 << std::endl;
    }
    input2.close();


    // -------------------------------------------------------------------------------------
    // csv ���� ó��
    // ifstream�� ostream�� ���� ������� �ʰ�, fstream���� �̿��ؼ� ������� �� ����! *0*!
    // ����
//    std::fstream fs;
//    fs.open("���ϸ�", ios::in or ios::out); // in�� �ش� ��ġ�� ������ �аڴٴ� �ǹ�, out�� �ش� ��ġ�� ������ ���ڴٴ� �ǹ�
//    fs.close();

    std::cout << "csv�����б�1" << std::endl;

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



    // �����б� ����
//    std::ifstream readFile; // readFile�̶�� ifstream ��ü�� ����
//    readFile.open("test.txt"); // readFile�� test.txt�� ������
////    ifstream readFile("test.txt");

//    char ch;
//    char buf[20];
//    std::string str;
//    readFile >> ch;
//    readFile.getline(buf, 20); // example.txt ���Ͽ��� �� ���� �о� �迭 buf�� ������
//    getline(readFile, str); // example.txt ���Ͽ��� �� ���� �о� ���ڿ� ��ü�� str�� ������

//    for (int i = 0; bool eof() const == True;  )
//    std::cout << &buf[1] << std::endl;

//    // ���� �ݱ�
//    readFile.close(); // ���ϰ��� ������ ����


    return 0;

}
