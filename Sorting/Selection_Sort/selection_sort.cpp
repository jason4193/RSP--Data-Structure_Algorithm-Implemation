#include "iostream"
#define MAX_SIZE 10

void selection_sort(int array[]){

    for (int c = 0; c < MAX_SIZE; c++){
        int min = c;
         // find the smallest item
        for (int i = c; i < MAX_SIZE; i++){
            if (array[min] > array[i]){
                min = i;
            }
        }
        std::cout << min << '\n';
        // swap the current with the min
        int temp = array[c];
        array[c] = array[min];
        array[min] = temp;

    }

}

int main() {

    int array [MAX_SIZE];

    // initialise array
    for (int i = 0; i < MAX_SIZE; i++){
        array[i] = rand() % MAX_SIZE;
    }

    // print array
    for (int i = 0; i < MAX_SIZE; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    selection_sort(array);

    // print array
    for (int i = 0; i < MAX_SIZE; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}