#include "../util/list_node.hpp"

class Solution {
    public:
    /// @brief 返回单链表的中间节点--快慢指针法
    /// @param head slow和fast指针同时从head出发，slow每次走一步，fast每次走两步
    /// @return  slow指针所指向的节点即为中间节点
    SingleListNode<int>::ListNode* midleNode(SingleListNode<int>::ListNode* head) {
        SingleListNode<int>::ListNode* fast = head;
        SingleListNode<int>::ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    /// @brief 返回单链表的中间节点--计数法
    /// @param head 先遍历链表计算节点总数n，再遍历链表n/2步
    /// @return 指向中间节点的指针
    SingleListNode<int>::ListNode* midleNode_count(SingleListNode<int>::ListNode* head) {
        int count = 0;
        SingleListNode<int>::ListNode* cur = head;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        int midIndex = count / 2;
        cur = head;
        for (int i = 0; i < midIndex; ++i) {
            cur = cur->next;
        }
        return cur;
    }

    /// @brief 返回单链表的中间节点--数组法
    /// @param head 将链表节点存入数组，再返回数组中间位置的节点
    /// @return 指向中间节点的指针
    SingleListNode<int>::ListNode* midleNode_array(SingleListNode<int>::ListNode* head) {
        std::vector<SingleListNode<int>::ListNode*> nodes;
        SingleListNode<int>::ListNode* cur = head;
        while (cur != nullptr) {
            nodes.push_back(cur);
            cur = cur->next;
        }
        return nodes[(nodes.size() / 2)];
        
    }   
    /// @brief 返回单链表的中间节点--递归法
    /// @param head 递归遍历链表，同时维护一个计数器count
    /// @return 指向中间节点的指针
    SingleListNode<int>::ListNode* midleNode_recursive(SingleListNode<int>::ListNode* head) {
        int count = 0;
        return midleNode_helper(head, count);
    }

    /// @brief 辅助函数，用于递归计算中间节点
    /// @param head 当前节点
    /// @param count 当前节点的索引
    /// @return 指向中间节点的指针
    SingleListNode<int>::ListNode* midleNode_helper(SingleListNode<int>::ListNode* head, int count) {
        if (head == nullptr) {
            return nullptr;
        }
        count++;
        SingleListNode<int>::ListNode* next = midleNode_helper(head->next, count);
        if (count == (count + 1) / 2) {
            return head;
        }
        return next;
    }
};

int main() {
    Solution sol;
    std::vector<int> vec = {1,2,3,4,5};
    std::vector<int> vec2 = {1,2,3,4,5,6};
    SingleListNode<int>::ListNode* head = SingleListNode<int>::vectorToListNode(vec);
    SingleListNode<int>::ListNode* head2 = SingleListNode<int>::vectorToListNode(vec2);
    
    SingleListNode<int>::ListNode* midNode = sol.midleNode(head);
    SingleListNode<int>::ListNode* midNode2 = sol.midleNode(head2);
    SingleListNode<int>::ListNode* midNode3 = sol.midleNode_array(head);
    SingleListNode<int>::ListNode* midNode4 = sol.midleNode_array(head2);

    std::cout << "Middle Node Value: " << midNode->val << std::endl;
    std::cout << "Middle Node Value: " << midNode2->val << std::endl;
    std::cout << "Middle Node Value: " << midNode3->val << std::endl;
    std::cout << "Middle Node Value: " << midNode4->val << std::endl;

    SingleListNode<int>::freeMemoryLinkedList(head);
    SingleListNode<int>::freeMemoryLinkedList(head2);
    return 0;
}