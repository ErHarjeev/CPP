#include <iostream>
#include <cmath>

using namespace std;

class Complex{
private:
    double re,im;
public:
    Complex(double p_re = 0, double p_im = 0):
        re(p_re), im(p_im)
    {
        cout << "Complex Ctor" << endl;
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

int main(void)
{
    Complex c[3];

    for(size_t i = 0; i < 3; i++)
    {
        c[i].setVal(i+1, i+1);
    }

    return 0;
}
