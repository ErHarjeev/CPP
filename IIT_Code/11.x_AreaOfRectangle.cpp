#include <iostream>
#include <cmath>

using namespace std;

class point{
public:
    int x, y;
};

class rect{
public:
    point a,b;

    void find_area(void)
    {
        cout << abs(a.x - b.x) * abs(a.y - b.y);
    }
};

int main(void){
    rect first = { {1,5},{5,1}};
    first.find_area();

    return 0;
}
