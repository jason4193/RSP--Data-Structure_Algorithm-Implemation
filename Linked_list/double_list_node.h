#ifndef SINGLY_LIST_NODE
#define SINGLY_LIST_NODE
#include <iostream>

using namespace std;

struct Node {
  int key;
  Node* next;
  Node* previous;
  Node() = delete;
  Node(int k, Node* n, Node* p) : key(k), next(n), previous(p) {}
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
  Node*& search(Node*& current, int key);
  Node*& predecesoor(Node*& current, int key);
  void remove(int oldKey);
  void insertAfter(int oldKey, int newKey);

};


void Link_list::append(int newKey){
  Node* n = new Node(newKey, NULL, NULL);
  if (head == NULL) {
    head = n;
    tail = n;
  } else {
    n->previous = tail;
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
  Node*& result = search(head, oldKey);
  if (result == NULL){
      cout << oldKey << " is not in the list" << endl;
  } else {
    Node* temp_node = result;
    if (result->next == NULL){
      tail = result->previous;
      result->previous->next = NULL;
      delete temp_node;
    } else if (result->previous == NULL){
      head = result->next;
      result->next->previous = NULL;
    } else {
      result->previous->next = temp_node->next;
      delete temp_node;
    }
    size--;
  }
}

void Link_list::insertAfter(int oldKey, int newKey){ 
    Node* result = search(head, oldKey);
    if (result == NULL){
      cout << oldKey << " is not in the list" << endl;
    } else {
      Node* n = new Node(newKey, NULL, NULL);
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

Node*& Link_list::search(Node*& current, int key) { 
  static Node* nullNode = NULL;
  if (current == NULL) {
    return nullNode;
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


