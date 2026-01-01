#include "../util/list_node.hpp"
#include "../util/print_util.hpp"

/*
反转某区间内的链表，重点是虚拟头节点、左节点和右节点边界的问题，左-1，右+1.
*/
class Solution{
    private:
    void reverse(SingleListNode<int>::ListNode* head){
        SingleListNode<int>::ListNode* pre = nullptr;
        SingleListNode<int>::ListNode* cur = head;
        
        while(cur){
            SingleListNode<int>::ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
    
    public:
    /// @brief 反转区间内链表
    /// @param head 
    /// @param left 
    /// @param right 
    /// @return 
    SingleListNode<int>::ListNode* reverseBetween(SingleListNode<int>::ListNode* head, int left, int right){
        SingleListNode<int>::ListNode* dummy = new SingleListNode<int>::ListNode(-1);
        dummy->next = head;

        SingleListNode<int>::ListNode* pre = dummy;

        for(int i{}; i < left - 1; i++ ){
            pre = pre->next;
        }

        SingleListNode<int>::ListNode* rightNode = pre;
        for(int i{}; i < right - left + 1; ++i){
            rightNode = rightNode->next;
        }

        SingleListNode<int>::ListNode *leftNode = pre->next;
        SingleListNode<int>::ListNode *curr = rightNode->next;

        pre->next = nullptr;
        rightNode->next = nullptr;

        reverse(leftNode);

        pre->next = rightNode;
        leftNode->next = curr;

        return dummy->next;
    }
};

int main() {
    Solution sol;
    std::vector<int> vec = {1,2,3,4,5,6};
    SingleListNode<int>::ListNode* node = SingleListNode<int>::vectorToListNode(vec);
    
    SingleListNode<int>::ListNode* result = sol.reverseBetween(node, 2, 5);

    printSingleLinkedList<int>(result);

    std::cout<<"区间内链表反转："<< result << std::endl;
    SingleListNode<int>::freeMemoryLinkedList(result);
    return 0;
}