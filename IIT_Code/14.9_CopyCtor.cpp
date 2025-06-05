#include <iostream>
#include <cmath>

using namespace std;

class Complex{
private:
    double re,im;
public:
    // constructor
    Complex(double p_re = 0, double p_im = 0):
        re(p_re), im(p_im)
    {
        cout << "Complex Ctor" << endl;
    }

    //copy constructor
    Complex(const Complex& c):
        re(c.re), im(c.im)
    {
        cout << "Complex Copy Ctor" <<endl;
    }

    double norm(void)
    {
        return sqrt(re*re + im*im);
    }

    void print(void)
    {
        cout << "|" << re << "+j" <<im << "| = " << norm() << endl;
    }

    void setVal(double p_re, double p_im)
    {
        this->re = p_re;
        this->im = p_im;
    }

    ~Complex()
    {
        cout << "Complex Dtor" << endl;
        cout << "( " << re << "," << im << " )" << endl ;
    }
};

void display(Complex para)
{
    cout << "Display -- " ;
    para.print();
}

int main(void)
{
    Complex c1(4.2, 5.4), // constructor
            c2(c1),         // copy ctor
            c3 = c2;        // copy ctor
     c1.print();
     c2.print();
     c3.print();

     display(c3);   // call by value  copy ctor.

    return 0;
}
