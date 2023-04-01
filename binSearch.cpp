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

int binSearch(int num, vector<int>& arr);

int main() {
    Timer t1;

    vector<int> arr = readIntArray(cin);
    printArray(arr);

    int num;
    cin >> num;
    t1.start("search");
    cout << binSearch(num, arr) << endl;
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

int binSearch(int num, vector<int>& arr) {
    int start = 0;
    int end = arr.size();
    while (start < end) {
        int cur = (start + end) / 2;
        if (cur == start || cur == end) break;
        if (arr[cur] == num)
            return cur;
        else if (arr[cur] > num) {
            end = cur;
        } else if (arr[cur] < num) {
            start = cur;
        }
    }
    if (arr[start] == num)
        return start;
    else if (arr[end] == num)
        return end;
    else
        return -1;
}