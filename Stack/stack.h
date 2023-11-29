#ifndef STACK
#define STACK
#include "iostream"

using namespace std;
class Stack {
    public:
    int stack [5];
    int top;

    Stack() : top(-1) {}

    void push(int value);
    int pop();

};

/*
Function Inserting item value at the top of stack
Time Complexity O(1)
*/
void Stack::push(int value){
    if (top < 4){
        top++;
        stack[top] = value;
    } else {
        cout << "The stack is full" << endl;
        return;
    }
}

/*
Function return the top item of stack 
Time Complexity O(1)
*/
int Stack::pop(){
    if (top != -1){
        int value = stack[top];
        top--;
        return value;
    } else {
        cout << "The stack is empty" << endl;
        return -1;
    }
}

#endif