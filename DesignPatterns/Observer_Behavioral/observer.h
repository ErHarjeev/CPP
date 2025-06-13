#ifndef OBSERVER_H
#define OBSERVER_H
#include <vector>
#include <memory>

// observer interface class
class I_Observer
{
public:
    virtual bool update(int value)=0;
    I_Observer() = default;
    virtual ~I_Observer()= default;
};

// observer concrete interface class
class Display:public I_Observer
{
    public:
    bool update (int value);
    Display() = default;
    virtual ~Display()= default;
};

class Display_hindi:public I_Observer
{
    public:
    bool update (int value);
    Display_hindi() = default;
    virtual ~Display_hindi()= default;
};

// Subject class
class Sensor
{
public:
    bool add_observer(std::shared_ptr<I_Observer> add_ptr);
    void changed(int a );
    Sensor() = default;
    ~Sensor() = default;

private:
    std::vector<std::shared_ptr<I_Observer>> obj_handle;
};

#endif // OBSERVER_H
