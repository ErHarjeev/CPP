/*
    Stack Implementation using Private Data and Vectors.
*/

#include <iostream>
#include <vector>
using namespace std;

class stack
{
private:
    vector<char> data;
    unsigned int top;

public:

    stack(unsigned int set_size): top (0)
    {
        data.resize(set_size);
        cout << "Constructed Stack " <<endl;
    }

    bool is_empty(void)
    {
        return (top == 0 );
    }

    void push(char new_val)
    {
        data[top++] = new_val;
    }

    char pop(void)
    {
        return data[--top];
    }

    unsigned int stack_top(void)
    {
        return top;
    }

    void print_stack(void)
    {
        if(top == 0)
        {
            cout << "Empty Stack" << endl;
            return ;
        }
        for(unsigned int i = 0; i < top; i++)
        {
            cout << data[i] << "," ;
        }
        cout << endl;
    }

};

int main(void)
{
    stack s1(50);

    s1.print_stack();
    s1.push('a');
    s1.push('b');
    s1.push('c');
    s1.push('d');
    s1.print_stack();
    cout << s1.pop() << endl;
    s1.print_stack();

    s1.push('k');
    s1.print_stack();
    return 0;

}
