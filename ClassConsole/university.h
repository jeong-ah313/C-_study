#ifndef UNIVERSITY_H
#define UNIVERSITY_H
#include <QString> //string

//friend class
class University
{
public:
    University(); // 생성자
    University(const QString& name, const QString& college, const QString& _class); // 생성자 오버로딩

public:
    int sum(int a, int b);
    float sum(float a, float b); // 메소드 오버로딩
    double sum(double a, double b); // 메소드 오버로딩

    // 메소드(멤버함수)
    void setFullName(const QString& name, const QString& college, const QString& _class);

    // getter, setter
    const QString& getName(void) const; // void 생략가능->파라미터가 ㅇㅓㅄ어서 ㅆㅓ줌
    const QString& getCollege(void) const;
    const QString& getClass(void) const;

    void setName(const QString& name); // return 값이 없어서 void를 ㅆㅓ줌
    void setCollege(const QString& college);
    void setClass(const QString& _class);

protected: //상속해줄거
    QString m_name;
    QString m_college;
    QString m_class;

//    QString name = "";

private:
    // 멤버변수




};

#endif // UNIVERSITY_H
