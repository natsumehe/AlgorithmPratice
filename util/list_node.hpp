#pragma once

#include <iostream>
#include <vector>

using namespace std;

// 单链表节点定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 将列表转换为单链表
ListNode* vectorToListNode(const vector<int>& vec) {
    ListNode* dum = new ListNode(0);
    ListNode* cur = dum;
    for(int val : vec){
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dum->next;
}

// 释放分配给链表的内存空间
void freeMemoryLinkedList(ListNode* head) {

    ListNode* cur = head;
    while (head != nullptr) {
        cur = head->next;
        delete cur;
    }
}