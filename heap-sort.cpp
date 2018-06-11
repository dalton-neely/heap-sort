//Dalton Neely
//Heap-Sort.cpp
//June 11th, 2018

#include <iostream>
#include "max-heap.hpp"
#include "heap-sort.hpp"

using namespace std;

#define asize(x) (sizeof(x) / sizeof((x)[0]))

int main(int argc, char * argv[]){
    if(argc >= 2){
        string argument(argv[1]);
        if(argument == "test"){ // Test is passed in the command line
            maxHeapTest();
            heapSortTest();
        }
    }else{ // Actual program
        int arr[] = {5,65,58,65,6,98,7,1,569,7,52,4,562,7,2,-8};
        int * sorted = heapSort(arr, asize(arr));
        cout << endl << "[";
        for(int i = 0; i < asize(arr); i++){
            if(i < asize(arr) - 1)
                cout << sorted[i] << ",";
            else
                cout << sorted[i];
        }
        cout << "]" << endl;
    }
    return 0;
}