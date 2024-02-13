//
//  BST<T>.hpp
//  Lab3P2
//
//  Created by GUW06 on 2023-02-02.
//

#ifndef BST_T__hpp
#define BST_T__hpp

#include <stdio.h>
template <typename T>
class BST {
private:
    struct TreeNode {
        T element;
        TreeNode<T>* left;
        TreeNode<T>* right;
        TreeNode(T element) : element(element), left(nullptr), right(nullptr) {}
    };
    
    int size;
    TreeNode* root;

    void insert(TreeNode*& node, int data);
    void inOrder(TreeNode* node) const;
    void preOrder(TreeNode* node) const;
    void postOrder(TreeNode* node) const;
    void destroyTree(TreeNode* node);
    
    bool search(T element, TreeNode<T> *node);
    TreeNode<T> *remove(T element, TreeNode<T> *node);
    
    void clearModifier(TreeNode<T> *node) {
            if (node->left != NULL) {
                clearHelper(node->left);
            }
            if (node->right != NULL) {
                clearHelper(node->right);
            }
            delete node;
        }

public:
    BST() : root(nullptr) {}
    ~BST();
    BST(T element[], int arraySize);
    BST(BST<T> const &tree);

    int const getSize() {
            return size;
        }
    void clear() {
            // Clear all nodes in the tree using a post-order traversal
            if (root != NULL) {
                clearModifier(root);
                size = 0;
                root = NULL;
            }
        }
    
    void insert(int data);
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    
    bool search(T element);
    bool remove(T element);
    
    
    vector<TreeNode<T>*> *path(T element) {
            vector<TreeNode<T>*> *result = new vector<TreeNode<T>*>;
            TreeNode<T> *curr = root;
            while (curr != NULL) {
                result->push_back(curr);
                if (element == curr->element) {
                    return result;
                }
                else if (element < curr->element) {
                    curr = curr->left;
                }
                else {
                    curr = curr->right;
                }
            }
            delete result;
            return NULL;
        }
    
    
    class Iterator;
    Iterator begin() const{return Iterator();}
    Iterator end() const{return Iterator(nullptr);}
};
#endif /* BST_T__hpp */
