#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

bool f(list<int>& li, vector<double>& vd)
{
    if(li.size() > vd.size())
    {
        cout << " Destination copy is small in size" << endl;
        return false;
    }

    cout << " List Before : " ;
        for(auto& x:li)
        { cout << x << " ";}
        cout << endl;

    cout << " Vector Before : " ;
        for(auto& x:vd)
        { cout << x << " ";}
        cout << endl;

    copy(li.begin(), li.end(), vd.begin());

    cout << " List After : " ;
        for(auto& x:li)
        { cout << x << " ";}
        cout << endl;

    cout << " Vector After : " ;
        for(auto& x:vd)
        { cout << x << " ";}
        cout << endl;

    sort(vd.begin(), vd.end());
    cout << " Vector sorted : " ;
        for(auto& x:vd)
        { cout << x << " ";}
        cout << endl;

    return true;

}

int main()
{
    list<int> src =  {1,22,3,43,5,6};
    vector<double> des(src.size());

    f(src, des);

    return 0;
}
