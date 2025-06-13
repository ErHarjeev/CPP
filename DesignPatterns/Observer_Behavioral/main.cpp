#include <iostream>
#include "observer.h"

using namespace std;

int main()
{
    cout << "Welcome" << endl;
    Display *output1 = new Display();
    Display_hindi *output2= new Display_hindi();
    Sensor sensor1;
    std::shared_ptr<I_Observer> smrt(output1);

    sensor1.add_observer(smrt);

    smrt.reset(output2);

    sensor1.add_observer(smrt);

    std::cout << "Calling Update" << std::endl;

    sensor1.changed(12);
    sensor1.changed(19);

    // Trick: calling pure virtual function using base class reference.
    I_Observer *ptr_virtual = new Display();
    Display test{};
    I_Observer &ref_virtual = test;

    ptr_virtual->update(5);
    ref_virtual.update(10);

    delete ptr_virtual;
    return 0;
}
