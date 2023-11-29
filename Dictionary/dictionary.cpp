#include "dictionary.h"

int main() {

    Dictionary dict;

    dict.insert("Jason", 1234);
    dict.insert("Pat", 4321);
    dict.insert("Jason", 2345);
    dict.insert("David", 1357);

    for (int i = 0 ; i < dict.size; i++){
        cout << dict.keys_name[i] << endl;
    }

    dict.removeKey("Pat");
    dict.removeValue("Jason", 1234);

    for (int i = 0 ; i < dict.size; i++){
        cout << dict.keys_name[i] << endl;
    }

    dict.printValue("Jason");
    dict.printValue("Pat");
    dict.printValue("David");

    return 0;
}