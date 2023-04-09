#include "utils.h"
using namespace std;

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

int binSearch(int num, vector<int>& arr) {
    int start = 0;
    int end = arr.size();
    while (start < end) {
        int cur = (start + end) / 2;
        if (arr[cur] == num)
            return cur;
        else if (arr[cur] > num) {
            end = cur;
        } else if (arr[cur] < num) {
            start = cur + 1;
        }
    }
    return -1;
}