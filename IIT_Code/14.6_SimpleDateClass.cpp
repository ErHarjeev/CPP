/* Simple Date Class
*/

#include <iostream>
using namespace std;

char month_name[][4]= {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep", "Oct", "Nov", "Dec"};
char day_name[][4] = {"Mon","Tue","Wed","Thr","Fri", "Sat", "Sun"};

class Date{
    enum Month_t{Jan=1,Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    enum Day_t{Mon =1, Tue, Wed, Thr, Fri, Sat, Sun};
    typedef unsigned short UINT;
    UINT date,day, month;
public:
    Date(UINT l_date, UINT l_day, UINT l_month):
        date(l_date), day((Day_t)l_day), month((Month_t)l_month)
    {
        cout << " Date Ctor" <<endl;
    }

    void print_date(void)
    {
        cout << "Date = " << date << ", Day = "
        << day_name[day-1] << ", Month = " << month_name[month-1] <<endl;
    }
    ~Date()
    {
        cout << "Date Dtor" << endl;
        print_date();
    }
};


int main(void)
{
    // Copy Initialization. The values { 1, 1, 1 } are used to construct a temporary Date object, which is then copied to d1.
    Date d1 = { 1, 1, 1};
    // Direct Initialization: This directly calls the constructor of Date with the arguments 2, 2, 2
    Date d2 (2,2,2);
    // Uniform Initialization (or Brace Initialization): This uses curly braces {} to initialize d3. It is part of the C++11 uniform initialization syntax
    Date d3 {3,3,3};

    return 0;
}
