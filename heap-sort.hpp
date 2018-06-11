#pragma once

#define asize(x) (sizeof(x) / sizeof((x)[0]))

#include "max-heap.hpp"
#include <cassert>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

int * heapSort(int* arr, int n){
    Heap heap(arr, n);
    int * sorted;
    sorted = new int[n];
    for(int i = 0; i < n; i++)
        sorted[i] = heap.extract();
    return sorted;
}

void heapSortTest(){
    clock_t start = clock();

            cout << "Heap sort should sort from highest to lowest value:";
            int arr1[] = {2,5,15};
            int * ptr = heapSort(arr1, asize(arr1));
            assert(ptr[0] == 15);
            assert(ptr[1] == 5);
            assert(ptr[2] == 2); 
            cout << " *";
            cout << " Pass!" << endl;
            cout << "All tests passed" << endl;

            cout << "Duration: " << fixed << setprecision(2) << (double) (clock() - start) / (double) CLOCKS_PER_SEC << " seconds" << endl;
}