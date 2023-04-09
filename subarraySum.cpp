#include "utils.h"
using namespace std;

struct tup {
    tup(int af, int bf, int cf) : a {af}, b {bf}, c {cf} {};
    int a, b, c;
};

tup maxSubarray(vector<int>& arr, int first, int last);
tup findCross(vector<int>& arr, int first, int last);

int main() {
    Timer t1;

    vector<int> arr = readIntArray(cin);
    // printArray(arr);

    t1.start("max subarray");

    tup ans = maxSubarray(arr, 0, arr.size());

    cout << ans.a << ' ' << ans.b << ' ' << ans.c << endl;

    t1.display();
    return 0;
}

bool comp(tup& c1, tup& c2) {
    return c1.c < c2.c;
}

tup maxSubarray(vector<int>& arr, int first, int last) {
    // consider fir to last - 1 for calculation
    if (first == last - 1)
        return tup(first, last, arr[first]);
    else {
        int mid = (first + last) / 2;
        tup left = maxSubarray(arr, first, mid);
        tup right = maxSubarray(arr, mid, last);
        tup cross = findCross(arr, first, last);

        if (left.c >= right.c && left.c >= cross.c)
            return left;
        else if (right.c >= left.c && right.c >= cross.c)
            return right;
        else
            return cross;
    }
}

tup findCross(vector<int>& arr, int first, int last) {
    int mid = (first + last) / 2;

    int leftsum = arr[mid - 1];
    int leftind = mid - 1;

    int sum = leftsum;
    for (int i = mid - 2; i >= first; i--) {
        sum += arr[i];
        if (sum >= leftsum) {
            leftsum = sum;
            leftind = i;
        }
    }

    int rightsum = arr[mid];
    int rightind = mid;

    sum = rightsum;
    for (int i = mid + 1; i < last; i++) {
        sum += arr[i];
        if (sum >= rightsum) {
            rightsum = sum;
            rightind = i;
        }
    }

    return tup(leftind, rightind, leftsum + rightsum);
}
