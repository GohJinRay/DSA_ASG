#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() : root(nullptr) { }

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

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

TreeNode* AVLTree::rotateLeft(TreeNode* x) {
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

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

TreeNode* AVLTree::insert(TreeNode* node, Order order) {
    if (node == nullptr) {
        return new TreeNode(order); 
    }

    if (order.getOrderID() < node->order.getOrderID()) { 
        node->left = insert(node->left, order); 
    }
    else if (order.getOrderID() > node->order.getOrderID()) { 
        node->right = insert(node->right, order); 
    }
    else {
        // Duplicate keys not allowed
        return node;
    }

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    return balance(node);
}

void AVLTree::insert(Order order) {
    root = insert(root, order);
}

Order AVLTree::search(TreeNode* node, int orderID) {
    if (node == nullptr) {
        return Order();
    }

    if (node->order.getOrderID() == orderID) {
        return node->order;
    }

    if (orderID < node->order.getOrderID()) { 
        return search(node->left, orderID); 
    }
    else {
        return search(node->right, orderID);
    }
}

Order AVLTree::search(int orderID) {
    return search(root, orderID);
}

void AVLTree::printInorder(TreeNode* node) {
    if (node == nullptr) {
        return;
    }

    printInorder(node->left);
    cout << node->order.getOrderID() << " ";
    printInorder(node->right);
}


void AVLTree::printInorder() {
    printInorder(root);
    cout << endl;
}

void AVLTree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}