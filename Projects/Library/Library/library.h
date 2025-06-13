#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
using namespace std;

class Book{

public:
    Book(string cname,string cauthor, int cisbn);
    bool check_status(string cname);
    bool issue_book(string cname);


private:
    const string name;
    const string author;
    const int    isbn;
    bool    issued;
    static int total_books;
};

#endif // LIBRARY_H
