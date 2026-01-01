#include "../util/list_node.hpp"
#include "../util/print_util.hpp"

class Solution {
    public:
    /// @brief 反转全链表-递归实现
    /// @param head 
    /// @return last 
    SingleListNode<int>::ListNode* reverseList_recursive(SingleListNode<int>::ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        SingleListNode<int>::ListNode* last = reverseList_recursive(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }

    /// @brief 迭代实现
    /// @param head 
    /// @return pre
    SingleListNode<int>::ListNode* reverseList_iteration(SingleListNode<int>::ListNode* head){
        SingleListNode<int>::ListNode* pre = nullptr;
        SingleListNode<int>::ListNode* cur = head;
        while(cur != nullptr){
            SingleListNode<int>::ListNode* next = cur->next; //保存节点
            cur-> next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

};

int main() {
    Solution sol;
    std::vector<int> vec = {1,2,3,4,5};
    SingleListNode<int>::ListNode* Node = SingleListNode<int>::vectorToListNode(vec);
    std::cout << "反转前：";
    printSingleLinkedList<int>(Node);
    
    SingleListNode<int>::ListNode* result = sol.reverseList_recursive(Node);
    std::cout << "递归反转后：";
    printSingleLinkedList<int>(result);

    SingleListNode<int>::ListNode* result_iteration = sol.reverseList_iteration(result);
    
    std::cout << "迭代反转后：";
    printSingleLinkedList<int>(result_iteration);

    SingleListNode<int>::freeMemoryLinkedList(result_iteration);
    return 0;
}