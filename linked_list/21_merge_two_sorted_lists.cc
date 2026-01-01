#include <iostream>
#include "../util/list_node.hpp"

using namespace std;


class Solution {
    // 递归方法
public:
    SingleListNode<int>::ListNode* mergeTwoLists(SingleListNode<int>::ListNode* l1, SingleListNode<int>::ListNode* l2){
        if (l1 == nullptr) {
            return l2;
        }
        else if (l2 == nullptr) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    // 迭代方法
    SingleListNode<int>::ListNode* mergeTwoListsIterative(SingleListNode<int>::ListNode* l1, SingleListNode<int>::ListNode* l2) {
        SingleListNode<int>::ListNode dummy(0);
        SingleListNode<int>::ListNode* tail = &dummy;   
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            }
            else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1 != nullptr) {
            tail->next = l1;
        }
        else {
            tail->next = l2;
        }
        // tail.next = (l1 != nullptr) ? l1 :l2;
        return dummy.next;
    }
};

int main() {
    Solution sol;
    vector<int> vec1 = {1,2,3};
    vector<int> vec2 = {1,3,4};
    SingleListNode<int>::ListNode* l1 = SingleListNode<int>::vectorToListNode(vec1);
    SingleListNode<int>::ListNode* l2 = SingleListNode<int>::vectorToListNode(vec2);
    // 递归调用
    SingleListNode<int>::ListNode* merged_recursion = sol.mergeTwoLists(l1, l2);
    
    cout << "递归合并后的链表：";
    for (SingleListNode<int>::ListNode* p = merged_recursion; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;

    // 迭代调用
    l1 = SingleListNode<int>::vectorToListNode(vec1);
    l2 = SingleListNode<int>::vectorToListNode(vec2);
    SingleListNode<int>::ListNode* merged_interative = sol.mergeTwoListsIterative(l1, l2);
    
    cout << "迭代合并后的链表: ";
    for (SingleListNode<int>::ListNode* p = merged_interative; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    
    SingleListNode<int>::freeMemoryLinkedList(merged_recursion);
    return 0;
}
    