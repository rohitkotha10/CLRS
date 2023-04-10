#include "utils.h"
#include "tree.h"
using namespace std;

int main() {
    Timer t1;

    // ifstream ifs("tree.txt");
    // vector<vector<int>> arr = readBinarySearchTree(ifs);

    t1.start("tree");

    Tree<int> myTree(15);

    myTree.insertLeft(myTree.search(myTree.root, 15), 6);
    myTree.insertRight(myTree.search(myTree.root, 15), 18);
    myTree.insertLeft(myTree.search(myTree.root, 6), 3);
    myTree.insertRight(myTree.search(myTree.root, 6), 7);
    myTree.insertLeft(myTree.search(myTree.root, 18), 17);
    myTree.insertRight(myTree.search(myTree.root, 18), 20);
    myTree.insertLeft(myTree.search(myTree.root, 3), 2);
    myTree.insertRight(myTree.search(myTree.root, 3), 4);
    myTree.insertRight(myTree.search(myTree.root, 7), 13);
    myTree.insertLeft(myTree.search(myTree.root, 13), 9);

    myTree.inorderTraversal(myTree.root);
    cout << endl;
    myTree.preorderTraversal(myTree.root);
    cout << endl;
    myTree.postorderTraversal(myTree.root);
    cout << endl;

    cout << myTree.minimumTree(myTree.root)->val << ' ' << myTree.maximumTree(myTree.root)->val;
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
        cout << "Successor " << myTree.successor(cur)->val << endl;
        cout << "Predecessor " << myTree.predecessor(cur)->val << endl;
    } else
        cout << "Not Found" << endl;

    t1.display();
    return 0;
}