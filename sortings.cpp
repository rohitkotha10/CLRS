#include "utils.h"
#include "heap.h"
using namespace std;

void insertionSort(vector<int>& arr);

void selectionSort(vector<int>& arr);

void bubbleSort(vector<int>& arr);

void mergeSort(vector<int>& arr, int start, int end);
void merge(vector<int>& arr, int start, int mid, int end);

void heapSort(vector<int>& arr);

int main() {
    Timer t1;

    vector<int> arr = readIntArray(cin);
    printArray(arr);

    t1.start("sort");

    heapSort(arr);

    printArray(arr);
    t1.display();
    return 0;
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        for (j; j >= 0 && arr[j] > key; j--) { arr[j + 1] = arr[j]; }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int mnind = i;
        for (int j = i; j < arr.size(); j++) {
            if (arr[j] < arr[mnind]) mnind = j;
        }
        swap(arr[i], arr[mnind]);
    }
}

void bubbleSort(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int key = arr[i];
        for (int j = arr.size() - 1; j >= i + 1; j--) {
            if (arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);
        }
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start + 1 < end) {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid, end);
        merge(arr, start, mid, end);
    }
}

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp;
    int fir = start;
    int sec = mid;

    while (fir < mid && sec < end) {
        if (fir < mid && arr[fir] < arr[sec]) {
            temp.push_back(arr[fir]);
            fir++;
        } else if (sec < end && arr[sec] <= arr[fir]) {
            temp.push_back(arr[sec]);
            sec++;
        }
    }

    if (fir != mid) {
        for (int i = fir; i < mid; i++) temp.push_back(arr[i]);
    } else if (sec != end) {
        for (int i = sec; i < end; i++) temp.push_back(arr[i]);
    }
    for (int i = start; i < end; i++) arr[i] = temp[i - start];
}

void heapSort(vector<int>& arr) {
    Heap<int> myHeap(arr);
    vector<int> ans;
    myHeap.buildMaxHeap();
    for (int i = myHeap.size() - 1; i >= 1; i--) {
        swap(myHeap.arr[0], myHeap.arr[i]);
        ans.push_back(myHeap.arr.back());
        myHeap.arr.pop_back();
        myHeap.maxHeapify(0);
    }
    ans.push_back(myHeap.arr.back());
    myHeap.arr.pop_back();
    reverse(ans.begin(), ans.end());
    arr = ans;
}