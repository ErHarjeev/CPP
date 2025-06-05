/*
    Order of Initialization
    Order of initialization does not depend on the order in the initialization list.
    It depends on the order of data members in the definition.
*/
#include <iostream>

using namespace std;

int init_m1(int m){
    cout << "Init m1 " << m << endl;
    return m;
}

int init_m2(int m){
    cout << "Init m2 " << m << endl;
    return m;
}

class Test {
    int m1, m2;
public:

    Test(int a, int b):
        m2(init_m2(b)),
        m1(init_m1(a))
        {
            cout << "Ctor" << endl;
        }

    ~Test()
    {
        cout << "Dtor" << endl;
    }

    void print_val(void){
        cout << "m1 = " << m1 << ", m2 = " << m2 << endl;
    }
};

int main(void)
{
    Test t1(2,3);
    t1.print_val();
    return 0;

}
