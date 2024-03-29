#include <iostream>

using namespace std;

class A {
public:
    virtual void f(int){
        cout<< "\nA:F";
    }
    virtual void g(double){
        cout << "\n A:G";
    }
    int h(A *){
        cout << "\n A:H";
        return 0;
    }
};

class B : public A {
public:
    void f(int){
        cout<< "\nB:F";
    }
    virtual int h(B *){
        cout << "\n B:H";
        return 0;
    }
};

class C : public B {
public:
     void g(double){
        cout << "\n C:G";
    }
    int h(B *){
        cout << "\n C:H";
        return 0;
    }
};


int main()
{
    A a;
    B b;
    C c;
    A *pA;
    B *pB;

    // Table 1
    cout << "\ntable 1" ;
    pA = &a;
    pA->f(2);       // 1
    pA->g (3.2);    // 2
    pA->h(&a);      // 3
    pA->h(&b);      // 4

    pA = &b;
    pA-> f(2);      // 5
    pA->g (3.2);    // 6
    pA->h(&a);      // 7
    pA->h(&b);      // 8

    pA = &c;
    pA-> f(2);      // 9
    pA->g (3.2);    // 10
    pA->h(&a);      // 11
    pA->h(&b);      // 12

    // Table 2
    cout << "\ntable 2" ;
    pB = (B *)&a;        // Error: invalid conversion from 'A *" to 'B *'
    //pB->f(2);       // 1
    //pB->g (3.2);    // 2
    //pB->h(&a);      // 3 Error: invalid conversion from 'A *" to 'B *'
    //pB->h(&b);      // 4

    pB = &b;
    pB-> f(2);      // 5
    pB->g (3.2);    // 6
    //pB->h(&a);      // 7 Error: invalid conversion from 'A *" to 'B *'
    pB->h(&b);      // 8

    pB = &c;
    pB-> f(2);      // 9
    pB->g (3.2);    // 10
    //pB->h(&a);      // 11 Error: invalid conversion from 'A *" to 'B *'
    pB->h(&b);      // 12


    return 0;

}

