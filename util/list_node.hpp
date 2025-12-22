#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// 单链表节点定义
template <typename T = int>
class SingleListNode{

    public:
    struct ListNode {
        T val;
        ListNode* next;
        ListNode(T x) : val(x), next(nullptr) {}
    };

    ListNode* head;
    size_t size;

    // 将列表转换为单链表（静态方便从外部直接调用）
    static ListNode* vectorToListNode(const std::vector<T>& vec) {
        ListNode* dum = new ListNode(T());
        ListNode* cur = dum;
        for (const T& val : vec) {
            cur->next = new ListNode(val);
            cur = cur->next;
        }
        ListNode* head = dum->next;
        delete dum;
        return head;
    }

    // 释放分配给链表的内存空间（静态）
    static void freeMemoryLinkedList(ListNode* head) {
        while (head) {
            ListNode* nxt = head->next;
            delete head;
            head = nxt;
        }
    }

    // 释放分配给链表的内存空间（非静态）
    void freeMemoryLinkedList() {
        ListNode* head = this->head;
        while (head) {
            ListNode* nxt = head->next;
            delete head;
            head = nxt;
        }
    }

    // 单链表增
    // 在链表头添加
    void addHead(T val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    // 在链表尾添加 
    void addTail(T val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
        }
        else {
            ListNode* cur = head;
            while (cur->next) {
                cur = cur->next;
            }
            cur->next = newNode;
        }
        size++;
    }
    // 在链表中间添加
    void addIndex(size_t index, T val) {
        if (index > this->size or index < 0) {
            throw out_of_range("Index out of range");
        }
        ListNode* newNode = new ListNode(val);
        ListNode* cur = head;
        for (size_t i = 0; i < index; ++i) {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        this->size++;
    }

    // 单链表删
    // 在链表头删除
    void delHead() {
        if (!head) {
            throw runtime_error("List is empty");
        }
        ListNode* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    // 在链表尾删除
    void delTail() {    
        if (!head) {
            throw runtime_error("List is empty");
        }
        ListNode* cur = head;
        while (cur->next->next) {
            cur = cur->next;
        }
        delete cur->next;
        cur->next = nullptr;
        size--;
    }
    // 在链表中间删除
    void delIndex(size_t index) {
        if (index >= this->size or index < 0) {
            throw out_of_range("Index out of range");
        }
        ListNode* cur = head;
        for (size_t i = 0; i < index; ++i) {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        size--;
    }
    // 单链表改
    // 改链表头
    void changeHead(T val) {
        if (!head) {
            throw runtime_error("List is empty");
        }
        head->val = val;
    }
    // 改链表尾
    void changeTail(T val) {
        if (!head) {
            throw runtime_error("List is empty");
        }
        ListNode* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        cur->val = val;
    }
    // 改链表中间
    void changeIndex(size_t index, T val) {
        if (index >= this->size or index < 0) {       
            throw out_of_range("Index out of range");
        }   
        ListNode* cur = head;
        for (size_t i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->val = val;
    }

    // 单链表查
    // 查询链表头
    T getHead() const {
        if (!head) {
            throw runtime_error("List is empty");
        }   
        return head->val;
    }
    // 查询链表尾
    T getTail() const {
        if (!head) {
            throw runtime_error("List is empty");
        }
        ListNode* cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        return cur->val;
    }
    // 查询链表中间
    T getIndex(size_t index) const {
        if (index >= this->size or index < 0) {
            throw out_of_range("Index out of range");
        }
        ListNode* cur = head;
        for (size_t i = 0; i < index; ++i) {
            cur = cur->next;
        }
        return cur->next->val;
    }

    // 遍历
    // 遍历链表
    void traverse() const {
        ListNode* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

};

// 创建双链表--双虚拟节点-头尾节点
template <typename T>
class DoubleListNode {
    struct ListNode
    {
        T val;
        ListNode* next;
        ListNode* prev;
        ListNode(T x) : val(x), next(nullptr), prev(nullptr) {}
    };
    
    // 虚拟头节点和尾节点
    ListNode* head;
    ListNode* tail;
    size_t size;

    //初始化节点
public:
//创建虚拟化头尾节点
    DoubleListNode() {
        head = new ListNode(T());
        tail = new ListNode(T());
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // 析构函数释放节点
    ~DoubleListNode() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 增
    // 在链表头添加
    void addHead(T val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head->next;
        newNode->prev = head;
        head->next->prev = newNode;
        head->next = newNode;
        size++; 
    }
    // 在链表尾添加
    void addTail(T val) {
        ListNode* newNode = new ListNode(val);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
        size++;
    }

    //链表中间
    void addIndex(size_t index, T val) {
        if (index > size or index < 0) {
            throw out_of_range("Index out of range");
        }
        else if(index == size) {
            addTail(val);
        }
        else {
            ListNode* newNode = new ListNode(val);
            ListNode* current = head;
            for(size_t i{}; i < index; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            size++;
        }
        
    }

    // 删
    // 在链表头删除
    void delHead() {
        if (head->next == tail) {
            throw runtime_error("List is empty");
        }
        ListNode* temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;
        delete temp;
        size--;
    }
    // 在链表尾删除
    void delTail() {
        if (head->next == tail) {
            throw runtime_error("List is empty");
        }
        ListNode* temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        delete temp;
        size--;
    }
    // 在链表中间删除
    void delIndex(size_t index) {
        if (index >= size or index < 0) {
            throw out_of_range("Index out of range");
        }
        ListNode* current = head;
        for(size_t i{}; i < index; ++i) {
            current = current->next;
        }
        current = current->next;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }   

    // 改
    // 改链表头
    void changeHead(T val) {
        if (head->next == tail) {
            throw runtime_error("List is empty");
        }
        head->next->val = val;
    }
    // 改链表尾
    void changeTail(T val) {
        if (head->next == tail) {
            throw runtime_error("List is empty");
        }
        tail->prev->val = val;
    }
    // 改链表中间
    void changeIndex(size_t index, T val) {
        if (index >= size or index < 0) {
            throw out_of_range("Index out of range");
        }
        ListNode* current = head;
        for(size_t i{}; i <= index; ++i) {
            current = current->next;
        }
        current->val = val;
    }   

    // 查
    // 查询链表头
    T getHead() const {
        if (head->next == tail) {
            throw runtime_error("List is empty");
        }
        return head->next->val;
    }
    // 查询链表尾
    T getTail() const {
        if (head->next == tail) {
            throw runtime_error("List is empty");
        }
        return tail->prev->val;
    }
    // 查询链表中间
    T getIndex(size_t index) const {
        if (index >= size or index < 0) {
            throw out_of_range("Index out of range");
        }
        ListNode* current = head;
        for(size_t i{}; i <= index; ++i) {
            current = current->next;
        }
        return current->val;
    }   

    // 遍历
    // 遍历链表
    void traverse() const {
        ListNode* current = head->next;
        while (current != tail) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }   

 
};
