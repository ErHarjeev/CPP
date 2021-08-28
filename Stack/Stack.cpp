#include<iostream>
#include<conio.h>
#include<string>

using namespace std;

/* Stack Class
@parameter: top - "Hold the load location on stack "
            arrLength - "Stack Length"
            arr[] - " integer array"
@method:    stack() - "class constructor"
            stack(int) - "Constructor Overloading"
            isEmpty()  - "Check if Stack is Empty"
            isFully()  - "Check if Stack is Fully"

*/
class stack{
private:
    int top;
    int arrLength = 10;
    int arr[];

public:
    /* constructor with default stack size of 10 */
    stack (){
    top =0;
    for(int i=0;i<arrLength;i++)
        arr[i]=0;
    }

    /* constructor overloaded with user define stack size */
    stack (int length)
    {
    arrLength = length;
    top =0;
    for(int i=0;i<arrLength;i++)
        arr[i]=0;
    }

    /* check if stack is empty */
    bool isEmpty(){
    if(top==0)
        return true;
    else
        return false;
    }

    /* check if stack is full */
    bool isFull(){
    if(top==10)
        return true;
    else
        return false;
    }

    /* push a value on a stack */
    void push(int val){
        if(isFull())
            cout<<"Stack is Full"<<endl;
        else{
            arr[top]=val;
            top++;
        }
    }

    /* retrieve LIFO value from stack */
    int pop(){
        int popvalue=0;
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
        }
        else{

        popvalue =  arr[(top-1)];
        }
        return popvalue;
    }

    /* show the number of stack exhausted */
    int stackcount(){
    return (top);
    }

    /* show the value of full stack */
    void display(){
        cout<<"values of array"<<endl;
        for (int i=0;i<arrLength;i++){
        cout<< arr[i]<<"\t";
        }
    }
};

int main(){
    stack s1(20);
    int option, value;

    do{ cout<<"\n____________________________"<<endl;
        cout<<"Select Option to Choose from"<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"1. push() Operation"<<endl;
        cout<<"2. pop() Operation"<<endl;
        cout<<"3. stackcount() Operation"<<endl;
        cout<<"4. display() Operation"<<endl;
        cout<<"5. Clear Screen"<<endl;
        cout<<"Press 0 to exist"<<endl;
        cin>>option;

        /* switch statement to execute particular function */
        switch(option){
            case 1:
                    cout<<"Enter a value to push in stack: "<<endl;
                    cin>>value;
                    s1.push(value);
                    break;
            case 2:
                    cout<<"Last value of Stack is:  "<<s1.pop()<<endl;
                    break;
            case 3:
                    cout<<"Last address of stack used "<<s1.stackcount()<<endl;
                    break;
            case 4:
                    s1.display();
                    break;
            case 5:
                    system("cls");
                    break;
            default: cout<<"Enter a valid Number"<<endl;
                    break;
        }
    }while(option!=0);

return 0;

}
