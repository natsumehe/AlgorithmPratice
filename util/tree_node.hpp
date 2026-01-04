#pragma once

#include <vector>
#include <queue>
#include <stack>

class BinaryTree {
public:
    // 二叉树节点定义
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;

        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right)
            : val(x), left(left), right(right) {}
    };

    static TreeNode* createTree() {

        TreeNode* root = new TreeNode(0);
        root -> left = new TreeNode(1);
        root -> right = new TreeNode(2);
        root -> left -> left = new TreeNode(3);
        root -> left -> right = new TreeNode(4);
        root -> right -> left = new TreeNode(5);
        root -> right -> right = new TreeNode(6);

        return root;
    }
    
    // 从层序遍历的 vector 构建二叉树（-1 表示 null）
    static TreeNode* createFromVector(const std::vector<int>& vals) {
        if (vals.empty() || vals[0] == -1) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(vals[0]);
        std::queue<TreeNode*> q;
        q.push(root);

        size_t i = 1;
        while (!q.empty() && i < vals.size()) {
            TreeNode* node = q.front();
            q.pop();

            // 左子节点
            if (i < vals.size() && vals[i] != -1) {
                node->left = new TreeNode(vals[i]);
                q.push(node->left);
            }
            ++i;

            // 右子节点
            if (i < vals.size() && vals[i] != -1) {
                node->right = new TreeNode(vals[i]);
                q.push(node->right);
            }
            ++i;
        }

        return root;
    }

    // 释放整棵树的内存（后序递归删除）
    static void deleteTree(TreeNode* root) {
        if (!root) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }

    // ========== 遍历函数（返回 vector<int>） ==========

    // 前序遍历 - 迭代
    static std::vector<int> preorderIter(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;
        std::stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            res.push_back(node->val);
            // 先压右，再压左（栈 LIFO）
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
        }
        return res;
    }

    // 中序遍历 - 迭代
    static std::vector<int> inorderIter(TreeNode* root) {
        std::vector<int> res;
        std::stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            // 一路向左
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }
            // 弹出栈顶
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            // 转向右子树
            curr = curr->right;
        }
        return res;
    }

    // 后序遍历 - 迭代（使用一个栈 + 记录上一个访问节点）
    static std::vector<int> postorderIter(TreeNode* root) {
        std::vector<int> res;
        if (!root) return res;
        std::stack<TreeNode*> s;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (!s.empty() || curr != nullptr) {
            if (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode* peek = s.top();
                // 如果右子树存在且未被访问过
                if (peek->right != nullptr && lastVisited != peek->right) {
                    curr = peek->right;
                } else {
                    res.push_back(peek->val);
                    lastVisited = peek;
                    s.pop();
                }
            }
        }
        return res;
    }

    //层序遍历--迭代
    static void levelorder(TreeNode* root, std::vector<int>& res) {
        if(root == nullptr) return ;
        
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            res.push_back(current -> val);

            if(current->left){
                q.push(current -> left);
            }
            if(current->right){
                q.push(current -> right);
            }
        }
    }


    // ========== 递归遍历（简洁，用于对比） ==========

    static void preorderRec(TreeNode* root, std::vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        preorderRec(root->left, res);
        preorderRec(root->right, res);
    }

    static void inorderRec(TreeNode* root, std::vector<int>& res) {
        if (!root) return;
        inorderRec(root->left, res);
        res.push_back(root->val);
        inorderRec(root->right, res);
    }

    static void postorderRec(TreeNode* root, std::vector<int>& res) {
        if (!root) return;
        postorderRec(root->left, res);
        postorderRec(root->right, res);
        res.push_back(root->val);
    }
};