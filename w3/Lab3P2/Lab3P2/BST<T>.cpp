//
//  BST<T>.cpp
//  Lab3P2
//
//  Created by GUW06 on 2023-02-02.
//

#include "BST<T>.hpp"
#include <iostream>

using namespace std;

template <typename T>
BST<T>::BST(T element[], int arraySize) {
    root = nullptr;
    size = 0;
    for (int i = 0; i < arraySize; i++) {
        TreeNode<T> *newNode = new TreeNode<T>(element[i]);
        TreeNode<T> *current = root;
        TreeNode<T> *previous = nullptr;
        while (current != nullptr) {
            previous = current;
            if (element[i] < current->element) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (previous == nullptr) {
            root = newNode;
        } else {
            if (element[i] < previous->element) {
                previous->left = newNode;
            } else {
                previous->right = newNode;
            }
        }
        size++;
    }
}


template <typename T>
BST<T>::BST(BST<T> const &tree) {
    root = nullptr;
    size = 0;
    vector<TreeNode<T> *> nodes;
    nodes.push_back(tree.root);
    int i = 0;
    while (i < nodes.size()) {
        TreeNode<T> *current = nodes[i];
        if (current->left != nullptr) {
            nodes.push_back(current->left);
        }
        if (current->right != nullptr) {
            nodes.push_back(current->right);
        }
        insert(current->element);
        i++;
    }
}

template <typename T>
void BST::insert(Node*& node, int data) {
    if (!node) {
        node = new Node(data);
    } else {
        if (data < node->data) {
            insert(node->left, data);
        } else {
            insert(node->right, data);
        }
    }
}

template <typename T>
void BST::inOrder(Node* node) const {
    if (node) {
        inOrder(node->left);
        std::cout << node->data << " ";
        inOrder(node->right);
    }
}
template <typename T>
void BST::preOrder(Node* node) const {
    if (node) {
        std::cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
template <typename T>
void BST::postOrder(Node* node) const {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->data << " ";
    }
}
template <typename T>
void BST::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

template <typename T>
bool BST<T>::search(T element, TreeNode<T> *node) {
    if (node == nullptr) {
        return false;
    }
    if (element == node->element) {
        return true;
    }
    if (element < node->element) {
        return search(element, node->left);
    } else {
        return search(element, node->right);
    }
}

template <typename T>
TreeNode<T> *BST<T>::remove(T element, TreeNode<T> *node) {
    if (node == nullptr) {
        return nullptr;
    }
    if (element < node->element) {
        node->left = remove(element, node->left);
    } else if (element > node->element) {
        node->right = remove(element, node->right);
    } else {
        if (node->left == nullptr) {
            TreeNode<T> *rightChild = node->right;
            delete node;
            return rightChild;
        } else if (node->right == nullptr) {
            TreeNode<T> *leftChild = node->left;
            delete node;
            return leftChild;
        } else {
            TreeNode<T> *minNode = node->right;
            while (minNode->left != nullptr) {
                minNode = minNode->left;
            }
            node->element = minNode->element;
            node->right = remove(minNode->element, node->right);
        }
    }
    return node;
}

template <typename T>
BST::~BST() {
    destroyTree(root);
}
template <typename T>
void BST::insert(int data) {
    insert(root, data);
}
template <typename T>
void BST::inOrder() const {
    inOrder(root);
    std::cout << std::endl;
}
template <typename T>
void BST::preOrder() const {
    preOrder(root);
    std::cout << std::endl;
}
template <typename T>
void BST::postOrder() const {
    postOrder(root);
    std::cout << std::endl;
}

template <typename T>
bool BST<T>::search(T element) {
    return search(element, root);
}

template <typename T>
bool BST<T>::remove(T element) {
    root = remove(element, root);
    if (root != nullptr) {
        size--;
        return true;
    }
    return false;
}


