#include "../util/list_node.hpp"
#include "../util/print_util.hpp"

class Solution{
    private:
        SingleListNode<int>::ListNode* reverseList(SingleListNode<int>::ListNode* head){
            SingleListNode<int>::ListNode* pre = nullptr;
            SingleListNode<int>::ListNode* cur = head;
            while(cur != nullptr){
                SingleListNode<int>::ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            return pre;
        }
        
        SingleListNode<int>::ListNode* endoffHalf(SingleListNode<int>::ListNode* head){
            SingleListNode<int>::ListNode* fast = head;
            SingleListNode<int>::ListNode* slow = head;
            while(fast != nullptr && fast ->next != nullptr){
                fast = fast->next->next;
                slow = slow ->next;
            }
            return slow;
        }

    public:
    /// @brief 复制到数组然后用双指针
    /// @param head 
    /// @return 
    SingleListNode<int>::ListNode* isPalindrome;
    bool reversecheck (SingleListNode<int>::ListNode* head){
         vector<int> vec;
         while(head != nullptr){
            vec.push_back(head->val);
            head = head->next;
        }
        for(int i{}, j = vec.size()-1; i<j ; ++i, --j){
            if(vec[i] != vec[j]) {
                return false;
            }
        }
        return true;
    }

    /// @brief 后半段反过来的方法
    /// @param head 
    /// @return result
    bool reverse_doublepointer(SingleListNode<int>::ListNode* head){
        SingleListNode<int>::ListNode* firsthalf = endoffHalf(head);
        SingleListNode<int>::ListNode* secondhalf = reverseList(firsthalf-> next);

        auto p1 = head,p2 = secondhalf;
        bool result = true;
        while(result && p2){
            if(p1->val != p2-> val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        firsthalf ->next = reverseList(secondhalf);
        return result;
    }

};

int main() {
    Solution sol;
    vector<int> vec = {1,2,3,3,2,1};
    vector<int> vec1 = {1,2};
    SingleListNode<int>::ListNode* Node = SingleListNode<int>::vectorToListNode(vec);
    SingleListNode<int>::ListNode* Node1 = SingleListNode<int>::vectorToListNode(vec1);
    
    bool result = sol.reversecheck(Node);
    bool result2 = sol.reverse_doublepointer(Node1);
    std::cout<< "输出的值："<<result<<endl;
    std::cout<< "不是回文数的判断："<<result2<<endl;
    return 0;
}