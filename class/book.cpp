#include "book.h"

#include <iostream>

Book::Book()
{

}

Book::~Book()
{

}

void Book::Move(int page)
{
    std::cout << "현재 페이지를 입력하세요";
    std::cin >> page;
    this->current_page_ = page; //this 생략가능
}

void Book::Show()
{
    std::cout << "페이지 보여주기" << this->current_page_ << std::endl;
}
