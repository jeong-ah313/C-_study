#include <QCoreApplication>

#include <QtDebug>
#include <iostream>

#include "book.h"
#include "university.h"

int main(int argc, char *argv[])
{
//    Book book;
//    book.Move(2);
//    book.Show();

//    Book book2;
//    book2 = book;

    // universuty
    University uni;
    uni.setFullName("강원대학교", "공과대학", "산업공학과");
    uni.setName("서울대학교");

    std::cout << uni.getName().toStdString() << std::endl;

    qDebug() << uni.getName();

    return 0;
}
