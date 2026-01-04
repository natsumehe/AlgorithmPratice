#pragma once

#include <iostream>
#include "list_node.hpp"
#include "tree_node.hpp"

using namespace std;

//打印数组
template <typename T>
void printArray(const T* arr, size_t size) {
    cout << "[";
    for(int i{}; i < size; i++) {
        cout << arr[i];
        if(i == size){
            cout << "]";
        }
    }
}      

//打印单链表
template <typename T>
void printSingleLinkedList(typename SingleListNode<T>::ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        head = head->next;
        if (head) {
            cout << " -> ";
        }
    }
    cout << "]" << endl;
}  
    
// 打印矩阵
template <typename T>
void printMatrix(const T** matrix, size_t rows, size_t cols) {
    cout << "[";
    for (size_t i = 0; i < rows; ++i) {
        cout << "[";
        for (size_t j = 0; j < cols; ++j) {
            cout << matrix[i][j];
            if (j < cols - 1) {
                cout << ", ";
            }
        }
        cout << "]";
        if (i < rows - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/// @brief 前序遍历打印二叉树
/// @param root 
template <typename T>
void preorderPrint(TreeNode* root) {
    if (!root) {
        std::cout << "null ";
        return;
    }
    std::cout << root->val << " ";
    preorderPrint(root->left);
    preorderPrint(root->right);
};