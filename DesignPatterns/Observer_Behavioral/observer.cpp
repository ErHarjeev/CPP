
#include "observer.h"
#include <iostream>
// observer interface class
bool I_Observer::update(int value)
{
    std::cout<< "In abstract class : " << value << std::endl;
    return true;
}

// observer concrete interface class
bool Display::update(int value)
{
    std::cout<< "In English class : " << value << std::endl;
    return true;
}

bool Display_hindi::update(int value)
{
    std::cout<< "In Hindi class : " << value << std::endl;
    return true;
}


// Subject class

bool Sensor::add_observer(std::shared_ptr<I_Observer> add_ptr)
{
    obj_handle.push_back(add_ptr);
    return true;
}

void Sensor::changed(int a)
{
    for(std::shared_ptr<I_Observer> ap: obj_handle)
    {
        ap->update(a);
    }
}
