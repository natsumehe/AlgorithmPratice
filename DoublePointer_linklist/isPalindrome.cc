#include "../util/list_node.hpp"
#include "../util/print_util.hpp"

class Solution{
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
};

int main() {
    Solution sol;
    vector<int> vec = {1,2,3,3,2,1};
    vector<int> vec1 = {1,2};
    SingleListNode<int>::ListNode* Node = SingleListNode<int>::vectorToListNode(vec);
    SingleListNode<int>::ListNode* Node1 = SingleListNode<int>::vectorToListNode(vec1);
    
    bool result = sol.reversecheck(Node);
    bool result2 = sol.reversecheck(Node1);
    std::cout<< "输出的值："<<result<<endl;
    std::cout<< "不是回文数的判断："<<result2<<endl;
    return 0;
}