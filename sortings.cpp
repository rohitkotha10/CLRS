#include <bits/stdc++.h>
using namespace std;

class Timer {
public:
    void start(string name);
    void display();

private:
    chrono::system_clock::time_point startTime;
    chrono::system_clock::time_point curTime;
    string name;
};

vector<int> readIntArray(istream& instream);
void printArray(vector<int>& arr);

void insertionSort(vector<int>& arr);

void mergeSort(vector<int>& arr, int start, int end);
void merge(vector<int>& arr, int start, int mid, int end);

int main() {
    Timer t1;

    vector<int> arr = readIntArray(cin);
    printArray(arr);

    t1.start("sort");
    mergeSort(arr, 0, arr.size());
    printArray(arr);
    t1.display();
    return 0;
}

void Timer::start(string name) {
    this->name = name;
    startTime = chrono::high_resolution_clock::now();
};

void Timer::display() {
    curTime = chrono::high_resolution_clock::now();
    chrono::duration<float> dur = curTime - startTime;
    cout << name << " Completed in " << dur.count() << "s" << endl;
};

vector<int> readIntArray(istream& instream) {
    int n;
    instream >> n;
    vector<int> temp(n);
    for (int i = 0; i < n; i++) instream >> temp[i];
    return temp;
}

void printArray(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) cout << arr[i] << ' ';
    cout << endl;
}

void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        for (j; j >= 0 && arr[j] > key; j--) { arr[j + 1] = arr[j]; }
        arr[j + 1] = key;
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