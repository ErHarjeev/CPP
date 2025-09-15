
#include <iostream>
#include <iomanip>
#include <type_traits>
#include <fstream>

template<typename T>
void temp_test(T x)
{
    if constexpr(std::is_same<T, float>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl;
    }
    if constexpr(std::is_same<T, float&>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl ;
    }
    if constexpr(std::is_same<T, float&&>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl;
    }

}

void temp_test(T& x)
{
        if constexpr(std::is_same<T, float>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl;
    }
    if constexpr(std::is_same<T, float&>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl ;
    }
    if constexpr(std::is_same<T, float&&>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl;
    }

}

void temp_test(T&& x)
{
        if constexpr(std::is_same<T, float>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl;
    }
    if constexpr(std::is_same<T, float&>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl ;
    }
    if constexpr(std::is_same<T, float&&>::value)
    {
        std::cout << "Float " << std::endl << std::fixed << std::setprecision(5) << std::endl;
    }

}


int main()
{
    float a = 1.2;
    float& b = a;
    temp_test(a);
    temp_test(b);
    temp_test(2.2);
    std::cout << " -------- " << std::endl;

    temp_test<float>(a);
    temp_test<float&>(a);
    temp_test<float&&>(a);
    std::cout << " -------- " << std::endl;

    temp_test<float>(b);
    temp_test<float&>(b);
    temp_test<float&&>(b);

    return 0;
}
