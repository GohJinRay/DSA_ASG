#pragma once

#include <iostream>
#include "Order.h"

struct TreeNode {
    Order order;
    int height;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const Order& o) : order(o), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    TreeNode* root;

    int getHeight(TreeNode* node);
    int getBalanceFactor(TreeNode* node);
    TreeNode* rotateRight(TreeNode* y);
    TreeNode* rotateLeft(TreeNode* x);
    TreeNode* balance(TreeNode* node);
    TreeNode* insert(TreeNode* node, Order);
    Order search(TreeNode* node, int orderID);
    void printInorder(TreeNode* node);
    void destroyTree(TreeNode* node);

public:
    AVLTree();
    ~AVLTree();
    void insert(Order);
    Order search(int orderID);
    void printInorder();
};
