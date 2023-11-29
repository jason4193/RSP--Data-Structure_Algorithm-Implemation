#ifndef KEY
#define KEY
/*
Class Key (Array of value, size of value)
Methods:
contrustor()
decontrustor()
search(value)
insert(newValue)
remove(value)
*/

#include "iostream"
using namespace std;

#define VALUES_MAX_SIZE 5

class Key {
    public: 
    int* values;
    int size;

    Key(): size(0) {
        values = new int[VALUES_MAX_SIZE];
    }

    ~Key(){
        delete[] values;
    }
    
    /*
    O(V)
    -- sorted array can reduce to O(logV) via binary search
    */
    int search(int value);

    // O(1)
    void insert(int newValue);

    // O(V)
    void remove(int value);

    // O(V)
    void print();
};

int Key::search(int value){
    for (int i = 0; i < size; i++){
        if (values[i] == value) {
            return i;
        }
    }
    return -1;
}

void Key::insert(int newValue){
    if (size == VALUES_MAX_SIZE){
        cout << "the values array is full" << endl;
        return;
    } else {
        values[size] = newValue;
        size++;
    }
}

void Key::remove(int value){
    int index = search(value);
    if (index == -1){
        cout << "value " << value <<" not found" << endl;
        return;
    } else {
        for (int i = index+1; i < size; i++){
            values[i-1] = values[i];
        }
        size--;
        return;
    }
}

void Key::print(){
    cout << "[ ";
    for (int i = 0; i < size; i++){
        cout << values[i] << " ";
    }
    cout << "]" << endl;
}


#endif

