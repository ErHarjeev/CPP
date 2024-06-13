
/*
    Stack: Implementation using public data
            Using dynamic array.
*/
#include <iostream>
using namespace std;

#define SIZE 10

class stack
{
public:
  char *data;
  int top_, size;

  void empty (void)
  {
	top_ = -1;
  }

  bool push (char x)
  {
	if (top_ < size)
	  {
		data[++top_] = x;
		return true;
	  }

	return false;
  }

  char pop (void)
  {
	return data[--top_];
  }

  int check_top (void)
  {
	cout << "Top =" << top_ << "Size = " << size << endl;
	return top_;
  }

  void print_stack (void)
  {

	if (top_ == -1)
    {
		cout << "Empty Stack";
		return;
    }

	for (int i = 0; i <= top_; i++)
    {
		cout << data[i] << ",";
    }
	cout << endl;
  }

};

int main (void)
{
  int a;
  cout << "Enter size of array";
  cin >> a;
  stack skt1 = { new char[a], -1, a };

  skt1.print_stack ();
  cout << endl;

  skt1.push ('1');
  skt1.push ('2');
  skt1.push ('3');
  skt1.check_top ();
  skt1.pop ();
  skt1.print_stack ();
}
