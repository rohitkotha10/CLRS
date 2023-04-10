#pragma once
#include <memory>
#include <vector>
#include <iostream>

template<typename T>
struct Node {
    Node(T val);
    T val;
    std::shared_ptr<Node<T>> parent;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
};

template<typename T>
class Tree {
public:
    Tree(T rootVal);
    // n x 4 table with key, parent, left, right
    Tree(std::vector<std::vector<T>>& table);

    void inorderTraversal(std::shared_ptr<Node<T>> cur);
    void preorderTraversal(std::shared_ptr<Node<T>> cur);
    void postorderTraversal(std::shared_ptr<Node<T>> cur);

    void insertLeft(std::shared_ptr<Node<T>> cur, T val);
    void insertRight(std::shared_ptr<Node<T>> cur, T val);

    std::shared_ptr<Node<T>> search(std::shared_ptr<Node<T>> cur, T val);

    std::shared_ptr<Node<T>> minimumTree(std::shared_ptr<Node<T>> cur);  // provided is bst
    std::shared_ptr<Node<T>> maximumTree(std::shared_ptr<Node<T>> cur);  // provided is bst

    std::shared_ptr<Node<T>> successor(std::shared_ptr<Node<T>> cur);
    std::shared_ptr<Node<T>> predecessor(std::shared_ptr<Node<T>> cur);

    bool checkBST();
    void insertBST(T val);
    void deleteBST(std::shared_ptr<Node<T>> val);

    std::shared_ptr<Node<T>> root;
    int size;
};

template<typename T>
Node<T>::Node(T val) {
    this->val = val;
}

template<typename T>
Tree<T>::Tree(T rootVal) {
    root = std::make_shared<Node<T>>(rootVal);
    size = 1;
}

template<typename T>
Tree<T>::Tree(std::vector<std::vector<T>>& table) {
    root = std::make_shared<Node<T>>(table[0][0]);
}

template<typename T>
void Tree<T>::inorderTraversal(std::shared_ptr<Node<T>> cur) {
    if (cur->left != nullptr) inorderTraversal(cur->left);
    std::cout << cur->val << ' ';
    if (cur->right != nullptr) inorderTraversal(cur->right);
}

template<typename T>
void Tree<T>::preorderTraversal(std::shared_ptr<Node<T>> cur) {
    std::cout << cur->val << ' ';
    if (cur->left != nullptr) preorderTraversal(cur->left);
    if (cur->right != nullptr) preorderTraversal(cur->right);
}

template<typename T>
void Tree<T>::postorderTraversal(std::shared_ptr<Node<T>> cur) {
    if (cur->left != nullptr) postorderTraversal(cur->left);
    if (cur->right != nullptr) postorderTraversal(cur->right);
    std::cout << cur->val << ' ';
}

template<typename T>
void Tree<T>::insertLeft(std::shared_ptr<Node<T>> cur, T val) {
    if (cur->left != nullptr) {
        std::cout << "already there" << std::endl;
        return;
    }
    cur->left = std::make_shared<Node<T>>(val);
    cur->left->parent = cur;
    size++;
}

template<typename T>
void Tree<T>::insertRight(std::shared_ptr<Node<T>> cur, T val) {
    if (cur->right != nullptr) {
        std::cout << "already there" << std::endl;
        return;
    }
    cur->right = std::make_shared<Node<T>>(val);
    cur->right->parent = cur;
    size++;
}

template<typename T>
std::shared_ptr<Node<T>> Tree<T>::search(std::shared_ptr<Node<T>> cur, T val) {
    if (cur->val == val)
        return cur;
    else if (cur->val > val && cur->left != nullptr)
        return search(cur->left, val);
    else if (cur->val < val && cur->right != nullptr)
        return search(cur->right, val);
    else
        return nullptr;
}

template<typename T>
std::shared_ptr<Node<T>> Tree<T>::minimumTree(std::shared_ptr<Node<T>> cur) {
    if (cur->left != nullptr) return minimumTree(cur->left);
    return cur;
}

template<typename T>
std::shared_ptr<Node<T>> Tree<T>::maximumTree(std::shared_ptr<Node<T>> cur) {
    if (cur->right != nullptr) return maximumTree(cur->right);
    return cur;
}

template<typename T>
std::shared_ptr<Node<T>> Tree<T>::successor(std::shared_ptr<Node<T>> cur) {
    if (cur->right != nullptr) return minimumTree(cur->right);

    if (cur->parent == nullptr) return nullptr;
    std::shared_ptr<Node<T>> y = cur->parent;
    while (cur.get() == y->right.get()) {
        cur = y;
        if (y->parent == nullptr) return nullptr;
        y = y->parent;
    }
    return y;
}

template<typename T>
std::shared_ptr<Node<T>> Tree<T>::predecessor(std::shared_ptr<Node<T>> cur) {
    if (cur->left != nullptr) return maximumTree(cur->left);

    if (cur->parent == nullptr) return nullptr;
    std::shared_ptr<Node<T>> y = cur->parent;
    while (cur.get() == y->left.get()) {
        cur = y;
        if (y->parent == nullptr) return nullptr;
        y = y->parent;
    }
    return y;
}

template<typename T>
bool Tree<T>::checkBST() {
    return true;
}

template<typename T>
void Tree<T>::insertBST(T val) {
    std::shared_ptr<Node<T>> y = nullptr;
    std::shared_ptr<Node<T>> x = root;

    std::shared_ptr<Node<T>> z = std::make_shared<Node<T>>(val);
    while (x != nullptr) {
        y = x;
        if (z->val < x->val)
            x = x->left;
        else
            x = x->right;
        z->parent = y;
    }
    if (y == nullptr)
        root = z;
    else if (z->val < y->val)
        y->left = z;
    else
        y->right = z;

    size++;
}

template<typename T>
void Tree<T>::deleteBST(std::shared_ptr<Node<T>> cur) {
    int ans = 0;
    if (cur->left != nullptr && cur->right != nullptr)
        ans = 3;
    else if (cur->left != nullptr)
        ans = 1;
    else if (cur->right != nullptr)
        ans = 2;
    if (ans == 0) {
        std::shared_ptr<Node<T>> par = cur->parent;
        if (par->right.get() == cur.get()) {
            par->right = nullptr;
        } else {
            par->left = nullptr;
        }
        cur = nullptr;
    } else if (ans == 1) {
        std::shared_ptr<Node<T>> par = cur->parent;
        cur->left->parent = par;
        if (par->right.get() == cur.get()) {
            par->right = cur->left;
        } else {
            par->left = cur->left;
        }
        cur = nullptr;
    } else if (ans == 2) {
        std::shared_ptr<Node<T>> par = cur->parent;
        cur->right->parent = par;
        if (par->right.get() == cur.get()) {
            par->right = cur->right;
        } else {
            par->left = cur->right;
        }
        cur = nullptr;
    } else if (ans == 3) {
        std::shared_ptr<Node<T>> par = cur->parent;

        std::shared_ptr<Node<T>> succ = successor(cur);
        if (cur->right.get() == succ.get()) {
            cur->right->parent = cur->parent;
            if (par->right.get() == cur.get()) {
                par->right = cur->right;
            } else {
                par->left = cur->right;
            }
            succ->left = cur->left;
        } else {
            std::shared_ptr<Node<T>> succpar = succ->parent;

            succ->right->parent = succ->parent;
            if (succpar->right.get() == succ.get()) {
                succpar->right = succ->right;
            } else {
                succpar->left = succ->right;
            }

            succ->parent = cur->parent;
            if (par->right.get() == cur.get()) {
                par->right = succ;
            } else {
                par->left = succ;
            }
            succ->left = cur->left;
        }
        cur = nullptr;
    }
    size--;
}