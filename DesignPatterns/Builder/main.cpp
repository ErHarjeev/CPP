#include <iostream>
using namespace std;

class UART{
public:
    void settingsDisplay(void);
    class Builder;
    friend class Builder;
    ~UART() = default;
    UART(const UART& other)= default;
    UART& operator=(const UART& ohter) = default;

private:
    UART(int baud_rate, bool parity_bit, int data_bits, int stop_bits);
    int baudRate;
    bool parityBit;
    int dataBits;
    int stopBits;
};


UART::UART(int baud_rate, bool parity_bit, int data_bits, int stop_bits):
    baudRate(baud_rate),parityBit(parity_bit),dataBits(data_bits),stopBits(stop_bits)
{
    std::cout<< " UART constructor Init " << std::endl;
}
void UART::settingsDisplay()
{
    std::cout << " Settings are " << baudRate << "," <<parityBit << "," << dataBits<< "," << stopBits << std::endl;
}

class UART::Builder
{
public:
    Builder();
    // return the Builder object to allow chaining action.
    Builder& setBaudRate(int baud_rate);
    Builder& setParityBit(int parity_bits);
    Builder& setDataBits(int data_bits);
    Builder& setStopBits(int stop_bits);
    UART build(void)
    {
        std::cout << "Building UART object " << std::endl ;
        return UART(baudRate,parityBit,dataBits,stopBits);  // Question Copy Construtor invoked or assignment constructor
    }
    ~Builder()=default;
private:
    int baudRate = 9600;
    bool parityBit = 1;
    int dataBits = 8;
    int stopBits=1;
};

UART::Builder::Builder()
{
    std::cout<< "Builder Constructor. Defaults:  " << baudRate << "," << parityBit << ","<< dataBits << "," << stopBits << std::endl;
}

UART::Builder& UART::Builder::setBaudRate(int baud_rate)
{
    this->baudRate = baud_rate;
    return *this;
}

UART::Builder &UART::Builder::setParityBit(int parity_bit)
{
    this->parityBit = parity_bit;
    return *this;
}

UART::Builder &UART::Builder::setDataBits(int data_bits)
{
    this->dataBits = data_bits;
    return *this;
}

UART::Builder &UART::Builder::setStopBits(int stop_bits)
{
    this->stopBits = stop_bits;
    return *this;
}

int main()
{
    cout << "Hello World!" << endl;
    UART obj1 = UART::Builder().setBaudRate(4800).setDataBits(10).build();
    obj1.settingsDisplay();
    return 0;
}




