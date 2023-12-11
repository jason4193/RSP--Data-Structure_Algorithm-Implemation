#include "iostream"
#define MAX_SIZE 5

class queue {
    public:
    int head;
    int size;
    int* arr;

    queue(int s): size(s), head(-1){
        arr = new int[size];
        for (int i = 0; i < size; i++){
            arr[i] = -1;
        }
    }

    ~queue(){
        delete[] arr;
    }

    void print(){
        for (int i = 0; i < size; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << '\n';
    }

    void enqueue(int value){
        // check the queue is full or not
        if (head >= size){
            return;
        } else {
            head++;
            arr[head] = value;
        }
    }

    int dequeue(){
        // check the queue is empty or not
        if (head == -1){
            return -1;
        } else {
            int result = arr[0];
            for (int i = 0; i < size-1; i++){
                arr[i] = arr[i+1];
            }
            head--;
            return result;
        }
    }


};


void merge(int array[], int begin , int mid, int end){
    queue buffer_1(mid+1-begin);
    queue buffer_2(end-mid);
    for (int i = begin; i <= mid; i++){
        buffer_1.enqueue(array[i]);
    }

    for (int i = mid+1; i <= end; i++){
        buffer_2.enqueue(array[i]);
    }
    // std::cout << "buffer_1.head " << buffer_1.head << '\n';
    // std::cout << "buffer_2.head " << buffer_2.head << '\n';


    int current = begin;
    while (buffer_1.head != -1 && buffer_2.head != -1){
        if (buffer_1.head != -1 && (buffer_2.head == -1 || buffer_1.arr[0] <= buffer_2.arr[0])){
            array[current++] = buffer_1.dequeue(); 
        } else if (buffer_2.head != -1) {
            array[current++] = buffer_2.dequeue();
        }
    }
    while (buffer_1.head != -1){
        array[current++] = buffer_1.dequeue();
    }
    while (buffer_2.head != -1){
        array[current++] = buffer_2.dequeue();
    }

    
}

void merge_sort(int array[], int begin, int end){
    int mid;
    if (begin < end){
        mid = (begin+end)/2;
        merge_sort(array, begin, mid);
        merge_sort(array, mid+1, end);
        // std::cout << begin << mid << end << '\n';
        merge(array, begin, mid, end);
    }
}

int main(){

    /* Test for queue */

    // queue test(1);
    // test.print();
    // test.enqueue(5);
    // test.enqueue(4);
    // test.enqueue(3);
    // test.enqueue(2);
    // test.print();
    // std::cout << test.dequeue() << "\n";
    // std::cout << test.dequeue() << "\n";
    // // std::cout << test.dequeue() << "\n";
    // test.print();

    /* Test Case */

    int array [MAX_SIZE];

    // initialise array
    for (int i = 0; i < MAX_SIZE; i++){
        array[i] = rand() % MAX_SIZE;
        // array[i] = MAX_SIZE - i;
    }   

    // print array
    for (int i = 0; i < MAX_SIZE; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    merge_sort(array, 0, MAX_SIZE-1);

    // print array
    for (int i = 0; i < MAX_SIZE; i++){
        std::cout << array[i] << " ";
    }
    std::cout << "\n";

    return 0;
}