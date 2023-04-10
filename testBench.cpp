#include "utils.h"
#include "priorityQueue.h"
using namespace std;

int main() {
    Timer t1;

    vector<int> arr = readIntArray(cin);
    printArray(arr);

    t1.start("sort");

    PriorityQueue<int> ans(arr);
    ans.heapInsert(10);

    printArray(ans.arr);
    t1.display();
    return 0;
}