#include "iostream"
#define MAX_SIZE 10

/*
    Binary Search Algorithm
    Time Complexity 
    Best Case O(1)
    Average Case O(logN) 
    Worst Case O(logN)
*/

int binary_search(int array[], int value){
    int tail = MAX_SIZE - 1;
    int head = 0;
    while (head <= tail){
        int mid = (head + tail) / 2;
        
        if (array[mid] == value){
            return mid;
        }

        if (array[mid] < value) {
            head = mid + 1;
        } else {
            tail = mid - 1;
        }
    }
    return -1;
}

int main() {
    // initialise array
    int array [MAX_SIZE] = {10, 30, 35, 40, 50, 55, 60, 70, 85, 100};

    // print the array
    for (int i = 0; i < MAX_SIZE; i++){
        std::cout << array[i] << " ";
    }
    std::cout << '\n';

    std::cout << binary_search(array, 2) << '\n';
    std::cout << binary_search(array, 85) << '\n';

    return 0;
}