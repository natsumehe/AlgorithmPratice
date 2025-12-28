#include <iostream>
#include "../util/list_node.hpp"

using namespace std;

//创建二叉树结构
template<typename T>
class Tree{
    public:
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(): val(0),left(nullptr),right(nullptr) {}
    };
    
    // 创建一个二叉树
    TreeNode* createTree(){
        /*
        构建如下二叉树：
              1
            /   \
           2     3
            \   / \
             6 4  5
        */
        TreeNode* root = new TreeNode(1)
        root->left = new TreeNode(2)
        root->right = new TreeNode(3)
        root->right->right = new TreeNode(4)
        root->right->left = new TreeNode(5)
        root->left->rigth = new TreeNode(6)
        return root;
    }

    /// @brief 按照层序遍历从vector数组中创建数组
    /// @param vals 数组vector
    /// @return treenode
    TreeNode* createTreeformvector(const vector<int> &vals){
        if (vals.empty() || vals[0] == -1) return nullptr;

        TreeNode* root = new TreeNode(vals[0]);
        queue<TreeNode*> q;  //使用队列的先进先出
        q.push(root)

        size_t i = 1
        while(!q.empty() && i< vals.size()){
            TreeNode* node = q.front();
            q.pop();
    
            if( i < vals.size() && vals[i] != -1){
                node->left = TreeNode(vlas[i]);
                q.push();
            }
            i++

            if( i < vals.size() && vals[i] != -1){
                node->right = TreeNode(vlas[i]);
                q.push();
            }
            i++
    }
    return root;
}
    void deletNode(TreeNode* root){
        if(!root) return ;
        deletNode (root->left);
        deletNode (root->right);
        delete root;
    }
};