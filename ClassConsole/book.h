#ifndef BOOK_H
#define BOOK_H


class Book
{
public:
    Book();
    ~Book();

public:
    //메소드(멤버함수)
    void Move(int page);
    void Show(void); //void생략가능

protected:

private:
//    void setPercent();

    // 멤버변수
    int current_page_;

};

#endif // BOOK_H
