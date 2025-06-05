
#include "library.h"

Book::Book(string cname, string cauthor, int cisbn):
    name(cname), author(cauthor), isbn(cisbn)
{
    issued = false;
    cout<< "Book Created" << name << " " << author << " " << isbn << endl;
    total_books++;
    cout << "Total Books: " <<total_books <<endl;
}


bool Book::check_status(string cname)
{
    return (this->author == cname);
}
bool Book::issue_book(string cname)
{

}

int Book::total_books = 0;
