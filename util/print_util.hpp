#pragma once

#include <iostream>
#include "list_node.hpp"

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