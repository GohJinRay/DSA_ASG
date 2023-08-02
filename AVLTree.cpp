#include "AVLTree.h"

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroyTree(root);
}

int AVLTree::getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int AVLTree::getBalanceFactor(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* AVLTree::rotateRight(TreeNode* y) {
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode* AVLTree::rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

TreeNode* AVLTree::balance(TreeNode* node) {
    if (node == nullptr) {
        return node;
    }

    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) >= 0) {
            return rotateRight(node);
        }
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) <= 0) {
            return rotateLeft(node);
        }
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

TreeNode* AVLTree::insert(TreeNode* node, int orderID) {
    if (node == nullptr) {
        return new TreeNode(orderID); 
    }

    if (orderID < node->OrderID) { 
        node->left = insert(node->left, orderID); 
    }
    else if (orderID > node->OrderID) { 
        node->right = insert(node->right, orderID); 
    }
    else {
        // Duplicate keys not allowed
        return node;
    }

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    return balance(node);
}

void AVLTree::insert(int orderID) {
    root = insert(root, orderID);
}

TreeNode* AVLTree::search(TreeNode* node, int orderID) {
    if (node == nullptr || node->OrderID == orderID) { 
        return node;
    }

    if (orderID < node->OrderID) { 
        return search(node->left, orderID); 
    }
    else {
        return search(node->right, orderID);
    }
}

bool AVLTree::search(int key) {
    return search(root, key) != nullptr;
}

void AVLTree::printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    printInorder(node->left);
    std::cout << node->OrderID << " ";
    printInorder(node->right);
}


void AVLTree::printInorder() {
    printInorder(root);
    std::cout << std::endl;
}

void AVLTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}