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