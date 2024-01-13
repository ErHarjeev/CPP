#include <iostream>
using namespace std;

class TestClass
{
	public:
	TestClass()
	{
		std::cout << "TestClass Constructor at " << this << endl;
	}
	~TestClass()
	{
		std::cout << "TestClass Destructor at " << this << endl;
	}
};

int main()
{
	TestClass *p_testclass = new TestClass();
	TestClass var_testclass;

	std::cout<< "Test Class Pointer and Variable created" <<endl ;

	//If we donot delete the pointer then it will cause memory leak.
	delete p_testclass;

	return 0;
}

/*
Output:
	TestClass Constructor at 0x701770
	TestClass Constructor at 0x61fe07
	Test Class Pointer and Variable created
	TestClass Destructor at 0x701770
	TestClass Destructor at 0x61fe07

Conclusion:
	Deleting pointer to dynamically created object is programmer's responsibility
	Make sure Order of pointer deletetion is based on your application.

*/
