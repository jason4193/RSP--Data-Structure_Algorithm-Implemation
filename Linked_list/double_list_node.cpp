#include "double_list_node.h"
#include "iostream"

int main (){
    Link_list list;
    list.remove(1);
    list.insertAfter(1,2);
    list.append(0);
    list.append(1);
    list.append(2);
    list.print();

    list.remove(0);
    list.insertAfter(2,4);
    list.insertAfter(2,3);
    list.insertAfter(0,1);
    list.print();
    cout << list.head->key << " " << list.tail->key << endl;

}
