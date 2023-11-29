#ifndef SINGLY_LIST_NODE
#define SINGLY_LIST_NODE
#include <iostream>

using namespace std;

struct Node {
  int key;
  Node* next;
  Node() = delete;
  Node(int k, Node* n) : key(k), next(n) {}
};

class Link_list {
  public:
  Node* head;
  Node* tail;
  int size;

  Link_list(): head(NULL), tail(NULL) {}

  // function declarations
  void append(int newKey);
  void print();
  Node* search(Node* current, int key);
  Node*& predecesoor(Node*& current, int key);
  void remove(int oldKey);
  void insertAfter(int oldKey, int newKey);

};


void Link_list::append(int newKey){ 
  Node* n = new Node(newKey, NULL);
  if (head == NULL) {
    head = n;
    tail = n;
  } else {
    tail->next = n;
    tail = n;
  }
}

void Link_list::print(){
  Node* current = head;
  cout << current->key << endl;
  while (current->next != NULL){
    current = current->next;
    cout << current->key << endl;
  }
}

void Link_list::remove(int oldKey){ 
  Node* current = head;
  if (current->key == oldKey || current->next == NULL){
    head = current->next;
    delete current;
    size--;
  } else {
    Node*& result = predecesoor(current, oldKey);
    if (result == NULL){
      cout << oldKey << " is not in the list" << endl;
    } else {
      Node* temp_node = result->next;
      if (result->next->next == NULL){
        tail = result;
        result->next = NULL;
        delete temp_node;
      }else{
        result->next = temp_node->next;
        delete temp_node;
      }
      size--;
    }
  }
}

void Link_list::insertAfter(int oldKey, int newKey){ 
    Node* result = search(head, oldKey);
    if (result == NULL){
      cout << oldKey << " is not in the list" << endl;
    } else {
      Node* n = new Node(newKey, NULL);
      if (result->next == NULL){
        result->next = n;
        tail = n;
      } else {
        n->next = result->next;
        result->next = n;
      }
      size++;
    }
}

Node* Link_list::search(Node* current, int key) { 
  if (current == NULL) {
    return NULL;
  }
  if (current->key == key){
    return current;
  } else {
    return search(current->next, key);
  }
}

Node*& Link_list::predecesoor(Node*& current, int key){
  static Node* nullNode = NULL;
  if (current == NULL || current->next == NULL){
    return nullNode;
  }
  if (current->next->key == key){
    return current;
  } else {
    return predecesoor(current->next, key);
  }
}



#endif


