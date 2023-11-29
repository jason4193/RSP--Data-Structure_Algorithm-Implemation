#ifndef QUEUE
#define QUEUE

#include "iostream"

using namespace std;

class Queue {
    public:
    int* queue;
    int end;
    int size;

    Queue(int q_size): end(-1), size(q_size){
        queue = new int[q_size];
    }

    ~Queue(){
        delete[] queue;
    }

    void enqueue(int value);
    int dequeue();
};

/*
Function insert item value at the back of queue
Time Complexity O(1)
*/
void Queue::enqueue(int value){
    if (end < size - 1){
        end++;
        queue[end] = value;
    } else {
        cout << "The queue is full" << endl;
        return;
    }
}

/*
Function return the front item from queue
Time Complexity O(N) need to shift every next item one index forward.
Better data structure linked list / doubly-ended queue => O(1)
*/
int Queue::dequeue(){
    if (end != -1){
        int value = queue[0];
        for (int i = 1; i <= end; i++){
            queue[i-1] = queue[i];
        }
        end--;
        return value;
    } else {
        cout << "The queue is empty" << endl;
        return -1;
    }
}

#endif