#include <iostream>
#include <chrono>

using namespace std;

class Light
{
private:
typedef struct LED{
        bool led_status;
        int duration;
    };

    LED red;
    LED yellow;
    LED green;
    int state;

public:
    Light(): red{0,0}, yellow{0,100}, green{0,400}, state(0)
        {
            cout<< " Light Const" << endl;
        }

    ~Light()
    {
        cout<< " Light Dest" << endl;
    }

    void advance()
    {
        bool active = true;
        while(active)
        {
            switch(state){
                // green Light ON
            case 0: green.led_status = true;
                    yellow.led_status = false;
                    red.led_status = false;
                    break;
                // Yellow Light ON
            case 1: green.led_status = false;
                    yellow.led_status = true;
                    red.led_status = false;
                    break;
            case 2: green.led_status = false;
                    yellow.led_status = false;
                    red.led_status = true;
                    active = false; // let other pole to switch
                    break;

            }
        }


    }

};

int main()
{

    return 0;
}
