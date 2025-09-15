#include <iostream>
#include <exception>

class MyException: public std::exception
{
    public:
    MyException()
    {
        std::cout << "MyException Const " << std::endl;
    }
    virtual ~MyException()
    {
        std::cout << "MyException Dest " << std::endl;
    }
};

class Test{
public:
    int a;
    Test(int _a):a(_a)
    {
        std::cout<< "Test Const " << a << std::endl;
    }

    ~Test()
    {
        std::cout<< "Test Dest " << a <<std::endl;
    }

};

void h()
{
    Test a(1);
    throw 1;
    //throw 1.2;
    //throw exception();
    //throw MyException();
    //throw test(11);
    std::cout << "H exit " << std::endl;
}

void g()
{
    Test b(2);
    try
    {
        h();
    }
    // cannot have anything between try and catch
    //std::cout << "G: before catch" << std::endl;
    catch(int e)
    {
        std::cout << "Int Exception" << std::endl;
    }
    catch(float e)
    {
        std::cout << "float Exception" << std::endl;
    }
    catch(...)
    {
        throw;
    }
    std::cout << "G:exit " << std::endl;
}

void f()
{
    try{
    g();

    }
    catch(MyException e)
    {
        std::cout<< "MyException Exception Catch " << std::endl;
    }
    catch(std::exception e)
    {
        std::cout<< "exception Exception Catch " << std::endl;
    }

    catch(...)
    {
        throw;
    }

    std::cout<< "G exit " << std::endl;
}

int main()
{
    try
    {
       f();
       std::cout << "Can you see me" << std::endl;
    }

    catch(...)
    {
        std::cout << "Unknow \n";
    }

    std::cout << "End of main () \n";
}
