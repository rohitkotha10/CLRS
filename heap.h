#pragma once
#include <vector>

template<typename T>
class Heap {
public:
    Heap(const std::vector<T>& arr);
    int parent(int i);
    int left(int i);
    int right(int i);
    int size() { return arr.size(); };

    void maxHeapify(int i);
    void buildMaxHeap();
    std::vector<T> arr;
};

template<typename T>
Heap<T>::Heap(const std::vector<T>& arr) {
    this->arr = arr;
};

template<typename T>
int Heap<T>::parent(int i) {
    if (i == 0) return -1;
    return (i + 1) / 2 - 1;
}

template<typename T>
int Heap<T>::left(int i) {
    int temp = 2 * i + 1;
    if (temp >= this->size()) return -1;
    return temp;
}

template<typename T>
int Heap<T>::right(int i) {
    int temp = 2 * i + 2;
    if (temp >= this->size()) return -1;
    return temp;
}

template<typename T>
void Heap<T>::maxHeapify(int i) {
    T l = left(i);
    T r = right(i);
    int largest = i;
    if (l != -1 && arr[l] > arr[i])
        largest = l;
    else
        largest = i;
    if (r != -1 && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        T temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(largest);
    }
}

template<typename T>
void Heap<T>::buildMaxHeap() {
    int start = parent(this->size() - 1);
    for (int i = start; i >= 0; i--) { maxHeapify(i); }
}
