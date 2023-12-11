#include "iostream"
#define MAX_SIZE 10


void insertion_sort(int array[]){
    // start from the head of the array
    for (int c = 0; c < MAX_SIZE-1; c++){
        int next = array[c+1];
        int i = c+1;
        // check the head and head+1 are in sorted order
        while (array[i-1] > array[i] && i > 0){
            int temp = array[i];
            array[i] = array[i-1];
            array[i-1] = temp;
            i--;
        }

        // print array
        // for (int i = 0; i < MAX_SIZE; i++){
        //     std::cout << array[i] << " ";
        // }
        // std::cout << "\n";
    }
}   

int main(){
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

    insertion_sort(array);

    // print array
    for (int i = 0; i < MAX_SIZE; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}