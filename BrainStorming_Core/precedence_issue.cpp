#include <iostream>

using namespace std;

int main()
{
    int* p;
    int a[] = {2, 9, 13};
    p = a;


    cout << "Pointer Add for B (Before) " << p << endl;
    // Question: which part of the expression is evaluated first. Left side of + or right side of +
    int b = *p++ + *p++;    // what is the value of b
    cout << "Expression : b = *p++ + *p++; " <<endl;
    cout << "B = " << b << endl;      // Resut was 11 on CodeBlock MinGW
    cout << "Pointer Add for B (After) " << p << endl;
    cout << "--------------" << endl <<endl;

    p = a;
    cout << "Pointer Add for C (Before) " << p << endl;
    // Question: which part of the expression is evaluated first. Left side of + or right side of +
    int c = *p + *p++;      // what is the value of c
    cout << "Expression : c = *p + *p++; " << endl;
    cout << "C = " << c << endl;      // Resut was 4 on CodeBlock MinGW
    cout << "Pointer Add for C (After) " << p << endl;
    cout << "--------------" << endl << endl;

    p = a;
    cout << "Pointer Add for D (Before) " << p << endl;
    // Question: which part of the expression is evaluated first. Left side of + or right side of +
    int d = *p++ + *p;      // what is the value of d
    cout << "Expression : d = *p++ + *p; " << endl;
    cout << "D = " << d << endl;      // Resut was 4 on CodeBlock MinGW
    cout << "Pointer Add for D (After) " << p << endl;

    return 0;
}

/*
a[] = {2, 9, 13};

******************************************
Output:

    Pointer Add for B (Before) 0x61fe00
    Expression : b = *p++ + *p++;
    B = 11
    Pointer Add for B (After) 0x61fe08
    --------------

    Pointer Add for C (Before) 0x61fe00
    Expression : c = *p + *p++;
    C = 4
    Pointer Add for C (After) 0x61fe04
    --------------

    Pointer Add for D (Before) 0x61fe00
    Expression : d = *p++ + *p;
    D = 11
    Pointer Add for D (After) 0x61fe04

******************************************
Conclusion: Left side of + is evalued first.
******************************************

*/
