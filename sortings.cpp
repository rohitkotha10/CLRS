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

int main() {
    Timer t1;

    vector<int> arr = readIntArray(cin);
    printArray(arr);

    t1.start("sort");
    insertionSort(arr);
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