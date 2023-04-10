#pragma once
#include "heap.h"

template<typename T>
class PriorityQueue: public Heap<T> {
public:
    PriorityQueue(const std::vector<T>& arr);
    T heapMaximum();
    T heapExtractMax();
    void heapIncreaseKey(int i, T key);
    void heapInsert(T key);
};

template<typename T>
PriorityQueue<T>::PriorityQueue(const std::vector<T>& arr) : Heap<T>(arr) {};

template<typename T>
T PriorityQueue<T>::heapMaximum() {
    return this->arr[0];
}

template<typename T>
T PriorityQueue<T>::heapExtractMax() {
    int max = this->arr[0];
    this->arr[0] = this->arr.back();
    this->arr.pop_back();
    this->maxHeapify(0);
    return max;
}

template<typename T>
void PriorityQueue<T>::heapIncreaseKey(int i, T key) {
    this->arr[i] = key;
    while (i > 0 && this->arr[this->parent(i)] < this->arr[i]) {
        int temp = this->arr[this->parent(i)];
        this->arr[this->parent(i)] = this->arr[i];
        this->arr[i] = temp;
        i = this->parent(i);
    }
}

template<typename T>
void PriorityQueue<T>::heapInsert(T key) {
    this->arr.push_back(0);
    this->heapIncreaseKey(this->size() - 1, key);
}
