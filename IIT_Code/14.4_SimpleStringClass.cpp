/*
    Simple String Class
*/

#include <iostream>
#include <cstring>

using namespace std;

class StringClass{
      char *str;
      size_t lenght;
    #define 0
        size_t lenght; //swapped member can cause problem
        char *str;
    #endif


public:
    StringClass(char *l_str):
        str(strdup(l_str)),
        lenght(strlen(l_str))
    {
        cout << "String Class Ctor" << endl;
    }
    ~StringClass()
    {
        free(str);
        cout << "String Class Dtor" << endl;
    }

    void print_val(void){
        cout << "str = " << str << ", Lenght = " << lenght << endl;
    }
};

int main(void)
{
    StringClass t1 = "testStringii";
    t1.print_val();
    return 0;

}
