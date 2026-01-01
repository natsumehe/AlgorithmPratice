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

    // 递归实现
    /// @brief 前序遍历
    /// @param root 
    /// @param res 
    void preorderRec(TreeNode* root, vector<int> &res){
        if(!root) return;
        res.back(root->val);
        preorderPrint(root->left, res);
        preorderPrint(root->right, res);
    }

    /// @brief 中序遍历
    /// @param root 
    /// @param res 
    void inorderRec(TreeNode* root, vector<int> &res){
        if(!root) return;
        inorderPrint(root->left, res);
        res.back(root->val);
        inorderPrint(root->right, res);
    }

    /// @brief 后序遍历
    /// @param root 
    /// @param res 
    void postorderRec(TreeNode* root, vector<int> &res){
        if(!root) return;
        postorderPrint(root->left, res);
        postorderPrint(root->right, res);
        res.back(root->val);
    }

    //迭代
    /// @brief 前序遍历
    /// @param root 
    void preorderiter(TreeNode* root){
        if(!root) return;
        vector<int> &res ,stack<TreeNode*> &s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node = s.top(); s.pop();
            res.push_back(node->val);
            if(node->left) s.push(node->left);
            if(node->right) s.push(node->right);
        }
        return res;
    }
<<<<<<< HEAD

    /// @brief 中序遍历
    /// @param root 
    void inorderiter(TreeNode* root){
        if(!root) return;
        vector<int> &res;
        stack<int> &s;
        TreeNode curr = root;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }

    /// @brief 后序遍历
    /// @param root 
    void postorderiter(TreeNode* root){
        if(!root) return;
        vector<int> &res;
        stack<int> & s;
        TreeNode* curr = root;
        TreeNode* lastVistied = nullptr;
        while(!s.empty() || curr){
            if(curr) {
                s.push(curr);
                curr = curr->left;
            }else{
                TreeNode* peek = s.top();
                if(peek->right && lastVistied != peek->right){
                    curr = peek->right;
                }else{
                    res.push_back(peek->val);
                    lastVistied = peek;
                    s.pop();
                }

            }

        }
        return res;
    }

=======
>>>>>>> 1638eb4 (🌱feet: 144题 94题  145题 前序 中序 后序遍历 迭代+递归)
};