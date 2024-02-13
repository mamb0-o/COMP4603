//
//  BST.cpp
//  Lab3P1
//
//  Created by GUW06 on 2023-01-27.
//

template<typename T>
int BST<T>::count()
{
    // your code goes here
    TreeNode<T>* root= new TreeNode<T>(element);
    int leftSide=0;
    int rightSide=0;
    int nodeRoot=1;
    if(root==nullptr) return 0;
    while(root!=nullptr){
        left= root->left;
        right=root->right;
        leftSide++;
        rightSide++;
    }
    return nodeRoot + leftSide + rightSide;
}

