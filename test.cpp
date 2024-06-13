#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    int real, imganiary;
public:
    Complex(int _real , int _imganiary =0): real(_real), imganiary(_imganiary)
    {
        cout << "Default val constructor" << endl;
    }
};

int main(void)
{
    Complex c[3];

    return 0;
}
