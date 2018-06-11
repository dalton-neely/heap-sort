#pragma once

#include <iostream>
#include <cassert>
#include <ctime>
#include <string>
#include <iomanip>

#define asize(x) (sizeof(x) / sizeof((x)[0]))

using namespace std;

class Heap{
    private:
        int* arr = NULL;
        int size;
        int capacity;
        int heapify(int);
        int heapDown(int);
        void init();
        int swap(int,int);
    public:
        Heap(int);
        Heap(int*, int);
        int insert(int);
        int insert(int*,int);
        int extract();
        void test();
        void print();
};

Heap::Heap(int size){
    this->size = 0;
    this->capacity = size;
    this->arr = new int[size];
    this->init();
}

void Heap::init(){
    for(int i = 0; i < this->capacity; i++){
        this->arr[i] = -1;
    }
}

Heap::Heap(int * arr, int n){
    this->size = 0;
    this->capacity = n;
    this->arr = new int[n];
    this->init();
    for(int i = 0; i < n; i++)
        this->insert(arr[i]);
}

int Heap::swap(int a, int b){
    int temp = this->arr[a];
    this->arr[a] = this->arr[b];
    this->arr[b] = temp;
}

int Heap::heapify(int index){
    int parent = (index - 1) / 2;
    if(this->arr[parent] < this->arr[index]){
        this->swap(index, parent);
        this->heapify(parent);
    }
    return 0;
}

int Heap::insert(int payload){
    if(this->size <= this->capacity){
        this->arr[this->size] = payload;
        this->heapify(this->size);
        this->size++;
    }else{
        return 1; //heap is full
    }
}

int Heap::insert(int * arr, int n){
    for(int i = 0; i < n; i++)
        this->insert(arr[i]);
}

int Heap::heapDown(int index){
    int parentValue = this->arr[index];
    int parent = index;
    int leftValue = this->arr[(index * 2) + 1];
    int left = (index * 2) + 1;
    int rightValue = this->arr[(index * 2) + 2];
    int right = (index * 2) + 2;
    int plr = 0; // 0 -> parent | 1 -> left | 2 -> right
    int largest = this->arr[parent];
    if(largest < leftValue && left <= this->size){
        largest = leftValue;
        plr = 1;
    }
    if(largest < rightValue && right <= this->size){
        largest = rightValue;
        plr = 2;
    }
    if(plr){
        if(plr == 1){
            this->swap(parent, left);
            this->heapDown(left);
        }else{
            this->swap(parent, right);
            this->heapDown(right);
        }
    }
    return 0;
}

int Heap::extract(){
    int temp = this->arr[0];
    this->size--;
    this->arr[0] = this->arr[this->size];
    heapDown(0);
    return temp;
}

void Heap::print(){
    cout << endl << "##### Max Heap Binary Tree #####" << endl;
    for(int i = 0; i < this->size; i++)
        cout << "[" << i << "]: " << this->arr[i] << endl;
    cout << "################################" << endl << endl;
}

void maxHeapTest(){
    clock_t start = clock();

            cout << "Max heap should have highest value node at top of subtree:";
            int arr1[] = {2,5,15};
            Heap heap1(arr1, asize(arr1));
            assert(heap1.extract() == 15);
            cout << " *";
            int arr2[] = {-9, 432, 2, 23, 2333, -3, 1, -4};
            Heap heap2(arr2, asize(arr2));
            assert(heap2.extract() == 2333);
            cout << "*";
            int arr3[] = {-9, -5422, -8854, -864, -2333, -3, -1, -4};
            Heap heap3(arr3, asize(arr3));
            assert(heap3.extract() == -1);
            cout << "*";
            int arr4[] = {5,5,5,4,5,4,4,5,4,5,5,4,45,5,4,4,5,4,5};
            Heap heap4(arr4, asize(arr4));
            assert(heap4.extract() == 45);
            cout << "*";
            int arr5[] = {8444545,55646484,54564898,548686486,54566};
            Heap heap5(arr5, asize(arr5));
            assert(heap5.extract() == 548686486);
            cout << "*";
            cout << " Pass!" << endl;
            cout << "All tests passed" << endl;

            cout << "Duration: " << fixed << setprecision(2) << (double) (clock() - start) / (double) CLOCKS_PER_SEC << " seconds" << endl;
}