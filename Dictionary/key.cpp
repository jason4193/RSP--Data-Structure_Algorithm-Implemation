#include "key.h"

int main(){

    Key k;
    k.insert(0);
    k.insert(2);
    k.insert(2);
    k.insert(2);
    k.insert(2);
    k.insert(2);

    cout << k.search(0) << endl;
    cout << k.search(3) << endl;

    k.print();

    k.remove(0);
    k.remove(1);
    
    k.print();

    return 0;
}