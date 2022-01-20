#include <QCoreApplication>
#include "book.h"

int main(int argc, char *argv[])
{
    Book book;
    book.Move(2);
    book.Show();

    return 0;
}
