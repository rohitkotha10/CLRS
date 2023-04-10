#include "utils.h"
#include "tree.h"
using namespace std;

int main() {
    Timer t1;

    // vector<int> arr = readIntArray(cin);
    // printArray(arr);

    t1.start("tree");

    Tree<int> myTree(5);
    auto ref = myTree.root;
    myTree.insertLeft(ref, 2);
    myTree.insertRight(ref, 7);

    myTree.inorderTraversal(ref);
    cout << endl;

    int val;
    cin >> val;
    auto cur = myTree.search(myTree.root, val);
    if (cur != nullptr) {
        cout << "Found " << cur->val << ' ';
        if (cur->parent != nullptr) cout << "Parent " << cur->parent->val << ' ';
        if (cur->left != nullptr) cout << "Left " << cur->left->val << ' ';
        if (cur->right != nullptr) cout << "Right " << cur->right->val << ' ';
        cout << endl;
    } else
        cout << "Not Found" << endl;

    t1.display();
    return 0;
}