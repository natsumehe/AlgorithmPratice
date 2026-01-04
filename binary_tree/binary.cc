#include "../util/tree_node.hpp"
#include <iostream>

int main() {
    std::vector<int> vals = {1, 2, 3, -1, 6, 4, 5}; // -1 表示 null
    auto root = BinaryTree::createFromVector(vals);
    std::cout << "createFromVector. ";
   

    auto create_root = BinaryTree::createTree();
    std::cout <<"root: "<<create_root -> val;
    std::cout << "\n";

    auto pre = BinaryTree::preorderIter(root);
    std::cout << "Preorder: ";
    for (int x : pre) std::cout << x << " ";
    std::cout << "\n";

    auto inor = BinaryTree::inorderIter(root);
    std::cout << "inorderIter: ";
    for (int x : inor) std::cout << x << " ";
    std::cout << "\n";

    auto post = BinaryTree::postorderIter(root);
    std::cout << "Postorder: ";
    for (int x : post) std::cout << x << " ";
    std::cout << "\n";

    BinaryTree::preorderRec(root, vals);
    std::cout << "递归前序遍历结果为: ";
    for (int i = 0; i < vals.size(); ++i) {
    std::cout << vals[i] << (i == vals.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    BinaryTree::inorderRec(root, vals);
    std::cout << "递归中序遍历结果为: ";
    for (int i = 0; i < vals.size(); ++i) {
    std::cout << vals[i] << (i == vals.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;

    BinaryTree::postorderRec(root, vals);
    std::cout << "递归后遍历结果为: ";
    for (int i = 0; i < vals.size(); ++i) {
    std::cout << vals[i] << (i == vals.size() - 1 ? "" : " -> ");
    }
    std::cout << std::endl;
    
    BinaryTree::levelorder(create_root, vals);
    std::cout << "层序遍历：";
    for (int i{}; i< vals.size(); ++i){
        std::cout << vals[i] << (i == vals.size() - 1 ? "" : " -> ");
    }

    BinaryTree::deleteTree(root);
    return 0;
}