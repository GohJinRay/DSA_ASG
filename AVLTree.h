#pragma once

#include <iostream>

struct TreeNode {
    int OrderID;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int id) : OrderID(id), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    TreeNode* root;

    int getHeight(TreeNode* node);
    int getBalanceFactor(TreeNode* node);
    TreeNode* rotateRight(TreeNode* y);
    TreeNode* rotateLeft(TreeNode* x);
    TreeNode* balance(TreeNode* node);
    TreeNode* insert(TreeNode* node, int orderID);
    TreeNode* search(TreeNode* node, int orderID);
    void printInorder(TreeNode* node);
    void destroyTree(TreeNode* node);

public:
    AVLTree();
    ~AVLTree();
    void insert(int orderID);
    bool search(int orderID);
    void printInorder();
};
