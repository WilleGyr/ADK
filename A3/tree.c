#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Function to create a new node with the given key
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));  // Allocate memory for the new node
    newNode->key = key;  // Set the key of the new node
    newNode->parent = NULL;  // Set the parent of the new node to NULL
    newNode->left = NULL;  // Set the left child of the new node to NULL
    newNode->right = NULL;  // Set the right child of the new node to NULL
    return newNode;  // Return the newly created node
}

// Function to create a new BST
Tree* createTree() {
    Tree* tree = (Tree*)malloc(sizeof(Tree));  // Allocate memory for the tree structure
    tree->root = NULL;  // Set the root of the tree to NULL
    return tree;  // Return the newly created tree
}

// Function to insert a node into the BST
void insert(Tree* T, Node* z) {
    Node* y = NULL;  // Initialize a pointer to track the parent node
    Node* x = T->root;  // Start from the root node
    while (x != NULL) {  // Traverse the tree until we reach a leaf node
        y = x;  // Update the parent node pointer
        if (z->key < x->key) {  // If the key of the new node is less than the current node's key
            x = x->left;  // Move to the left child
        } else {  // If the key of the new node is greater than or equal to the current node's key
            x = x->right;  // Move to the right child
        }
    }
    z->parent = y;  // Set the parent of the new node
    if (y == NULL) {  // If the tree is empty
        T->root = z;  // Set the new node as the root
    } else if (z->key < y->key) {  // If the key of the new node is less than the parent's key
        y->left = z;  // Set the new node as the left child of the parent
    } else {  // If the key of the new node is greater than or equal to the parent's key
        y->right = z;  // Set the new node as the right child of the parent
    }
}

// Function to search for a node with a given key in the BST
Node* search(Node* x, int k){
    while (x != NULL && k != x->key) {  // While we haven't reached the end of the tree and the key doesn't match
        if (k < x->key) {  // If the key is less than the current node's key
            x = x->left;  // Move to the left child
        } else {  // If the key is greater than the current node's key
            x = x->right;  // Move to the right child
        }
    }
    return x;  // Return the node with the given key, or NULL if not found
}

// Function to find the maximum key in the BST
Node* maximum(Node* x) {
    while (x->right != NULL) {  // While there's a right child
        x = x->right;  // Move to the right child
    }
    return x;  // When there's no right child, return the current node
}

// Function to find the minimum key in the BST
Node* minimum(Node* x) {
    while (x->left != NULL) {  // While there's a left child
        x = x->left;  // Move to the left child
    }
    return x;  // When there's no left child, return the current node
}

// Function to find the successor of given node. The successor of a node x is the node with the smallest key greater than x.key
Node* successor(Node* x){
    if (x->right != NULL) {
        return minimum(x->right);  // If right child exists, the successor is the minimum node in right subtree
    }
    Node* y = x->parent;  // Start from the parent node
    while (y != NULL && x == y->right) {  // While we're not at the root and x is the right child of y
        x = y;  // Move up the tree
        y = y->parent;  // Move up the tree
    }
    return y;  // Return the successor node
}

// Function to find the predecessor of given node. The predecessor of a node x is the node with the largest key smaller than x.key
Node* predecessor(Node* x){
    if (x->left != NULL) {
        return maximum(x->left);  // If left child exists, the predecessor is the maximum node in left subtree
    }
    Node* y = x->parent;  // Start from the parent node
    while (y != NULL && x == y->left) {  // While we're not at the root and x is the left child of y
        x = y;  // Move up the tree
        y = y->parent;  // Move up the tree
    }
    return y;  // Return the predecessor node
}

// Function to print the key of a given node
void printNode(Node* x) {
    printf("%d\n", x->key); // Prints the key value of the given node
}

// Function to print the keys of the nodes in the BST in ascending order
void inorderTreeWalk(Node* x) {
    // If the node is not null, continue the traversal
    if (x != NULL) {
        inorderTreeWalk(x->left); // First, recursively traverse the left subtree
        printf("%d ", x->key); // Then, print the key of the current node
        inorderTreeWalk(x->right); // Finally, recursively traverse the right subtree
    }
    // If the node is null, this branch of the tree has been fully traversed
}

// Function to delete a node from the BST
void deleteNode(Tree* T, Node* z) {
    if (z->left == NULL) {  // If the node has no left child
        transplant(T, z, z->right);  // Replace the node with its right child
    }
    else if (z->right == NULL) {  // If the node has no right child
        transplant(T, z, z->left);  // Replace the node with its left child
    }
    else 
    {  // If the node has both left and right children
        Node* y = predecessor(z);  // Find the predecessor of the node
        if (y->parent != z) {  // If the predecessor is not the left child of the node to be deleted
            transplant(T, y, y->left);  // Replace the predecessor with its left child
            y->left = z->left;  // Set the left child of the predecessor to be the left child of the node to be deleted
            y->left->parent = y;  // Update the parent pointer of the left child
        }
        transplant(T, z, y);  // Replace the node to be deleted with the predecessor
        y->right = z->right;  // Set the right child of the predecessor to be the right child of the node to be deleted
        y->right->parent = y;  // Update the parent pointer of the right child
    }
}

// Function to replace one subtree with another subtree
void transplant(Tree* T, Node* u, Node* v) {
    if (u->parent == NULL) {  // If the node to be replaced is the root
        T->root = v;  // Set the new subtree as the root of the tree
    }
    else if (u == u->parent->left) {  // If the node to be replaced is the left child of its parent
        u->parent->left = v;  // Set the new subtree as the left child of the parent
    }
    else
    {  // If the node to be replaced is the right child of its parent
        u->parent->right = v;  // Set the new subtree as the right child of the parent
    }
    if (v != NULL) {  // If the new subtree is not empty
        v->parent = u->parent;  // Set the parent of the new subtree to be the parent of the node to be replaced
    }
}

// Function to calculate the height of a BST
int treeHeight(Node* x) {
    if (x == NULL) {
        return -1; // If the tree is empty, the height is -1
    } else {
        int leftHeight = treeHeight(x->left);
        int rightHeight = treeHeight(x->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// Function to calculate the balance factor of a BST
int treeBalanceFactor(Node* x) {
    int leftHeight = treeHeight(x->left);
    int rightHeight = treeHeight(x->right);
    return abs(leftHeight - rightHeight);
}