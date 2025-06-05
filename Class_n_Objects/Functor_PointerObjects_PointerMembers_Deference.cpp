/******************************************************************************
 * Functors (overloaded operator())
 * Operator precedence and associativity
 * Pointer to member functions and variables
 * Member access via . and ->
 * Dereferencing and pointer semantics

 *  precedencece Chart
        Highest
           ()       // function call                Left-to-right
           .        // member access                Left-to-right
           ->       // pointer member access        Left-to-right
           *        // unary dereference            right-to-left
           *        // (lower) multiplication - not part of this group
        Lowest

        ( ) used for grouping expressions is not an operator — it’s a syntax mechanism to override precedence.


*******************************************************************************/
#include <iostream>

struct test{
    int totalcall = 0;
    int totalsent = 0;
    int *pint = new int(7);
    int operator()(int a)
    {
        std::cout << "sent bytes " << a << std::endl;
        totalsent += a;
        totalcall++;
        return 1;
    }
    int point(int a, int b)
    {
        std::cout << "Calling point function with args: " << a << "," << b << std::endl;
        return 0;
    }
    ~test() { delete pint; }
};

int main()
{

    test obj;       // object Instance
    test *pObj = &obj; // Pointer to object

    int (test::*pPoint)(int, int) = &test::point;  // pointer to member function
    int test::*pMember = &test::totalsent; //pointer to a member variable

    int a = obj(4);  // Invoking the overloaded () operator (Functor)
    int b = obj(10); //  Invoking the overloaded () operator (Functor)

    (obj.*pPoint)(2, 3);  // Calling member function via pointer  (on object instance )
    (pObj->*pPoint)(6, 7); // Calling member function via pointer ( on object pointer)

    // Displaying the state of variables after the functor calls
    std::cout << "Total Functor Calls " <<obj.totalcall << " Total Sent " << obj.totalsent << std::endl ;

    // derefencing a pointer member on a object
    std::cout << "Objec Instacet. Pointer Member of class Access " << *(obj.pint) << std::endl;

    // derefencing a pointer member from a object pointer
    std::cout << "Pointer Object. Pointer Memer of class (Arrow operator) " << *(pObj->pint) << std::endl;
    std::cout << "Pointer Object. Pointer Memer of class (derefencing) " << *(*pObj).pint << std::endl;

    // Accessing member variable using pointer-to-member
    std::cout << "Object Instace, member access using pointer-to-member " <<obj.*pMember << std::endl;
    std::cout << "Pointer Object, member access using pointer-to-member " <<pObj->*pMember << std::endl;
}
