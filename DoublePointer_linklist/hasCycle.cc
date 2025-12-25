#include "../util/list_node.hpp"

class Solution {
public:
    //双指针法--快慢指针法
    bool hasCycle_fastandslowPointer(SingleListNode<int>::ListNode* head){
        if(!head)return false;
        SingleListNode<int>::ListNode* slow = head;
        SingleListNode<int>::ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)return true;
        }
        return false;
    }

    //哈希表法
    bool hasCycle_hashTable(SingleListNode<int>::ListNode* head) {
        unordered_map<SingleListNode<int>::ListNode*, bool> set;
        SingleListNode<int>::ListNode* cur = head;
        while(cur) {
            if(set.find(cur) != set.end()) return true;
            set[cur] = true;
            cur = cur->next;
        }
        return false;
    }

};

int main() {
    Solution slo;

    vector<int> vec = {3, 2, 0, -4};
    SingleListNode<int>::ListNode* head = SingleListNode<int>::vectorToListNode(vec);
    // 创建环
    SingleListNode<int>::ListNode* tail = head;;
    while(tail->next){
        tail = tail->next;
    }
    // 让尾节点指向第三个节点，形成环
    tail->next = head->next; // 环的入口节点值为2       
    bool result = slo.hasCycle_fastandslowPointer(head);
    bool result_hash = slo.hasCycle_hashTable(head);
    if(result || result_hash) {
        cout << "The linked list has a cycle." << result << result_hash << endl;
    } else {
        cout << "The linked list does not have a cycle." << result << result_hash << endl;
    }
    return 0;
}