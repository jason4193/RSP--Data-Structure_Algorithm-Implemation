/*
Stack Implementation
Last-in, First-out LIFO
Functions: push(stack, value), pop(stack)
*/
#include "stack.h"

int main(){
    Stack s;
    
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(-4);
    s.push(5);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

}







