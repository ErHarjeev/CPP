/* Point and Rect Classes: Embedded Objects.
   Default, Copy and Overloaded Constructor.

    Construct:
        embedded objects
        class object
    Destruct:
        class object
        embedded objects.

*/

#include <iostream>
using namespace std;

class Point{
    int x, y;
public:
    // Default Ctor
    Point():
        x(0), y(0)
    {
        cout << "Point Ctor";
        print();
        cout << endl;
    }

    // Overloaded Ctor
    Point(int p_x, int p_y):
        x(p_x),y(p_y)
    {
        cout << "Point Ctor";
        print();
        cout << endl;
    }

    void print(void) const
    {
        cout << "(X = " << x << ",Y = " << y << " )" ;
        return ;
    }

    //Dtor
    ~Point()
    {
        cout << "Point Dtor" << endl;
    }
};

class Rect{
    Point TL, BR;

public:

    Rect()
    {
        cout << "Rect Ctor" ;
        print();
        cout << endl ;
    }

    Rect(int p1x, int p1y, int p2x, int p2y):
        TL(p1x, p1y), BR(p2x, p2y)
    {
       cout << "Rect Ctor" ;
       print();
       cout << endl ;
    }

    Rect(const Point& p_t1, const Point& p_t2):
        TL(p_t1), BR(p_t2)
    {
        cout << "Rect Ctor" ;
        print();
        cout << endl ;
    }

    Rect(const Point& p_t1, int brx, int bry):
        TL(p_t1), BR(brx, bry)
    {
       cout << "Rect Ctor" ;
       print();
       cout << endl ;
    }

    void print(void) const
    {
        cout << "[ " ;
        TL.print() ;
        cout << "  " ;
        BR.print();
        cout  << " ]" << endl;
    }

    Rect( const Rectt& r):
        TL(r.TL), BR(r.BR)
    {
        cout << "Rect C_Ctor" ;
        print();
        cout << endl ;
    }

    ~Rect()
    {
        cout << "Rect Dtor" ;
        print();
        cout << endl ;
    }

};

int main(void)
{
    cout << "--------" <<endl;
    Rect r2(Point(3,5),Point(5,6));
    cout << "--------" <<endl;
}
