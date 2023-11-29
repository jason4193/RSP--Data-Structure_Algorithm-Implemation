#ifndef DICTIONARY
#define DICTIONARY
/*
Dictionary Implementation
Class Dictionary(Arrary of Keys, size of Keys)
Methods:
Search(key)
Insert(key,value)
removeKey(key)
removeValue(key,value)
Max()
Min()
Predcessor(key)
Successor(key)

Class Key(Array of value, size of value)
*/

#include "string.h"
#include "key.h"
#include "iostream"
using namespace std;

#define KEYS_MAX_SIZE 10


class Dictionary {
    public:
    string keys_name [KEYS_MAX_SIZE];
    Key* keys_ptr [KEYS_MAX_SIZE];
    int size;

    Dictionary(): size(0) {}

    // O(K)
    int searchIndex(string key);

    // O(K)
    void insert(string key, int value); 
    
    /* O(K)
    -- sorted linked list can reduce to O(logK) via binary search
    */
    void removeKey(string key);

    /*
    O(K + V) 
    -- sorted linked list can reduce to O(logK + LogV) via binary search
    */
    void removeValue(string key, int value); 

    // O(K + V)
    void printValue(string key);

};

int Dictionary::searchIndex(string key){
    for (int i = 0; i < size; i++){
        if (keys_name[i] == key){
            return i;
        }
    }
    return -1;
}


void Dictionary::insert(string key, int value){
    int index = searchIndex(key);
    if (index == -1){
        Key* k = new Key();
        k->insert(value);
        keys_name[size] = key;
        keys_ptr[size] = k;
        size++;
    } else {
        keys_ptr[index]->insert(value);
    }
}

void Dictionary::removeKey(string key){
    int index = searchIndex(key);
    if (index == -1){
        cout << "key " << key << " not found" << endl;
    } else {
        delete keys_ptr[index];
        for (int i = index+1; i < size; i++){
            keys_ptr[i-1] = keys_ptr[i];
            keys_name[i-1] = keys_name[i];
        }
        keys_ptr[size] = NULL;
        keys_name[size] = "NONE";
        size--;
    }
}

void Dictionary::removeValue(string key, int value){
    int index = searchIndex(key);
    if (index == -1){
        cout << "key " << key << " not found" << endl;
    } else {
        keys_ptr[index]->remove(value);
    }
}


void Dictionary::printValue(string key){
    int index = searchIndex(key);
    if (index == -1){
        cout << "key " << key << " not found" << endl;
    } else {
        cout << key << ":" ;
        keys_ptr[index]->print();
    }
}

#endif

