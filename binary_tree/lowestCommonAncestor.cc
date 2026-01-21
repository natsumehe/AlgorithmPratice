#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "../util/tree_node.hpp"

class Solution {
public:
    /// 
    /// @brief Find the lowest common ancestor of two nodes in a binary tree.
    /// @param root The root of the binary tree.
    /// @param p The first node.
    /// @param q The second node.
    /// @return The lowest common ancestor of nodes p and q.
    ///
    BinaryTree::TreeNode* lowestCommonAncestor(BinaryTree::TreeNode* root, BinaryTree::TreeNode* p, BinaryTree::TreeNode* q) {
        if(!root ) return root;
        if(root == p || root == q) return root;
        BinaryTree::TreeNode* left = lowestCommonAncestor(root->left, p, q);
        BinaryTree::TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return left ? left : right;
    }

    BinaryTree::TreeNode* lowestCommonAncestor_iter(BinaryTree::TreeNode* root, BinaryTree::TreeNode* p, BinaryTree::TreeNode* q){

        if(!root) return nullptr;

        //存储父节点
        std::unordered_map<BinaryTree::TreeNode*, BinaryTree::TreeNode*> parent;
        //中间存储
        std::stack<BinaryTree::TreeNode*> st;

        parent[root] = nullptr;
        st.push(root);

        while(parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            BinaryTree::TreeNode* node = st.top();
            st.pop();

            if(node->left){
                parent[node->left] = node;
                st.push(node->left);
            }
            if(node->right){
                parent[node->right] = node;
                st.push(node->right);
            }
        }

        std::unordered_set<BinaryTree::TreeNode*>  ancestors;
        while (p) {
            ancestors.insert(p);
            p = parent[p]; // 向上移动
        }
        while (ancestors.find(q) == ancestors.end()) {
        q = parent[q];
        }

    return q;
} 
};

int main() {
    Solution sol;
    BinaryTree::TreeNode* root = BinaryTree::createFromVector({3,5,1,6,2,0,8,-1,-1,7,4});
    BinaryTree::TreeNode* p = root->left->right; // 5
    BinaryTree::TreeNode* q = root->left->left; // 1
    BinaryTree::TreeNode* lca = sol.lowestCommonAncestor(root, p, q);
    std::cout << "递归法: "<< lca->val << std::endl;

    BinaryTree::TreeNode* iter = sol.lowestCommonAncestor_iter(root, p, q);
    std::cout << "迭代法： "<< iter->val << std::endl;    
        // Expected output: 3
    return 0;

    }