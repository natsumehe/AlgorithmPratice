#include <iostream>
#include "../util/list_node.hpp"
#include "../util/print_util.hpp"
#include <unordered_set>

using namespace std;

class Solution {
    public:
    //双指针法
    SingleListNode<int>::ListNode* getIntersctionNode_double_pointer
    (SingleListNode<int>::ListNode* Node1, SingleListNode<int>::ListNode* Node2) {
        if (!Node1 || !Node2) return nullptr;

        SingleListNode<int>::ListNode* p1 = Node1;
        SingleListNode<int>::ListNode* p2 = Node2;
        while(p1 != p2) {
            //这里多嘴一句，是相交的节点，不是相交的值，所以不能用p1->val == p2->val来判断
            //如果p1或p2为nullptr，那么就让p1或p2指向另一个链表的头结点，这样可以保证两个指针最终在相交节点或nullptr处相等
            //如果p1和p2不相等，那么就让p1或p2指向自己的next节点，这样可以保证两个指针最终在相交节点或nullptr处相等 

            p1 = p1==nullptr ? Node2 : p1->next;
            p2 = p2==nullptr ? Node1 : p2->next;
        }
        return p1;
    }
    //哈希表法
    SingleListNode<int>::ListNode* getIntersctionNode_hash_map
    (SingleListNode<int>::ListNode* Node1, SingleListNode<int>::ListNode* Node2){
        if(!Node1 || !Node2) return nullptr;
        unordered_set<SingleListNode<int>::ListNode*> set;
        SingleListNode<int>::ListNode* curr = Node1;
        while(curr){
            set.insert(curr);
            curr = curr->next;
        }
        curr = Node2;
        while(curr){
            if(set.find(curr) != set.end()){
                return curr;
            }
            curr = curr->next;
        }
        return nullptr;
    }
};

int main() {
    Solution slo;   
    // 创建两个相交的链表
    vector<int> vec1 = {0, 1, 2, 3, 4, 5};
    vector<int> vec2 = {2, 3, 4, 5, 6, 7};
    SingleListNode<int>::ListNode* list1 = SingleListNode<int>::vectorToListNode(vec1);
    SingleListNode<int>::ListNode* list2 = SingleListNode<int>::vectorToListNode(vec2);

    //创建交点
    SingleListNode<int>::ListNode* intersection = new SingleListNode<int>::ListNode(3);

    //将交点连接到两个链表上
    list1->next->next = intersection;
    list2->next->next = intersection;
    intersection->next = new SingleListNode<int>::ListNode(4);
    intersection->next->next = new SingleListNode<int>::ListNode(5);
    
    //查找交点
    SingleListNode<int>::ListNode* result = slo.getIntersctionNode_double_pointer(list1, list2);

    SingleListNode<int>::ListNode* result_hash = slo.getIntersctionNode_hash_map(list1, list2);
    if (result || result_hash) {
        cout << "Intersection at node with double_pointer value: " << result->val <<"\n"
        << "Intersection at node with hash_map value: " << result_hash->val << endl;
    } else {
        cout << "No intersection." << endl;
    } 
    
    //打印intersection链表  
    cout << " List: " <<endl;
    printSingleLinkedList<int>(intersection) ; 


    // 释放内存（这里释放两次公共节点部分--会报错0
    // SingleListNode<int>::freeMemoryLinkedList(list1);
    // SingleListNode<int>::freeMemoryLinkedList(list2);

    return 0;
}