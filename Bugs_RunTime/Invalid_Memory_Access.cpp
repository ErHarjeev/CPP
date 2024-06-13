// this example has two examples of a invalid memory access bug.

#include <iostream>
#define error		// comment it if you want to see solution
int global_val = 1;

class base{
	public:
	int a_base;
	int *p_base;

	base()
	{
		std::cout<<"base const" <<std::endl;
		//Error: Trying to dereference pointer without assigning a memory address serious bug

		#ifdef error
		*p_base = 10;
		#endif // error

		p_base = &global_val;

		#ifndef error
		*p_base = 10;
		#endif // error

	}

	base(const base& other){
		this->a_base = other.a_base;

		//Error: Allocate new memory for p_base and copy the value
		#ifdef error
		;
		#endif // error

		#ifndef error
		this->p_base = new int;
		#endif // error

		*(this->p_base) = *(other.p_base);
	}
};

int main()
{
	base obj_1;
	obj_1.a_base = 5;
	base obj_2(obj_1);
	std::cout << "First object: A" <<obj_1.a_base <<"  " << obj_1.p_base << *(obj_1.p_base) <<std::endl;
	std::cout << "Second object: A" <<obj_2.a_base <<"  " << obj_2.p_base  << *(obj_2.p_base) <<std::endl;

	return 0;
}


/*

Output:
base const

Process returned -1073741819 (0xC0000005)   execution time : 1.815 s
Press any key to continue.

*/

