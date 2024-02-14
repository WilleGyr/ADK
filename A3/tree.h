#ifndef TREE_H
#define TREE_H

// Node structure
typedef struct Node {
    int key;                // The key value of the node
    struct Node *parent;    // Pointer to the parent node
    struct Node *left;      // Pointer to the left child node
    struct Node *right;     // Pointer to the right child node
} Node;

// Tree structure
typedef struct Tree {
    Node *root;             // Pointer to the root node of the tree
} Tree;

/**
 * Creates a new node with the given key.
 * 
 * @param key The key value for the new node.
 * @return Node* A pointer to the newly created node.
 */
Node* createNode(int key);

/**
 * Creates a Tree.
 *
 * @return A pointer to the newly created Tree object.
 */
Tree* createTree();

/**
 * Inserts the given node z into the BST.
 * 
 * @param T A pointer to the tree.
 * @param z A pointer to the node to be inserted.
*/
void insert(Tree* T, Node* z);

/**
 * Searches for a node with the given key in the tree.
 *
 * @param T The tree to search in.
 * @param k The key to search for.
 * @return A pointer to the node with the given key, or NULL if the key is not found.
 */
Node* search(Node* x, int k);

/**
 * Finds the maximum node in a binary tree.
 *
 * @param x The root node of the tree.
 * @return The maximum node in the tree.
 */
Node* maximum(Node* x);

/**
 * Finds the minimum node in a binary tree.
 *
 * @param x The root node of the tree.
 * @return The minimum node in the tree.
 */
Node* minimum(Node* x);

/**
 * Finds the successor of a given node in a tree.
 *
 * @param T The tree in which to search for the successor.
 * @param x The node for which to find the successor.
 * @return The successor node of x, or NULL if x has no successor.
 */
Node* successor(Node* x);

/**
 * Finds the predecessor of a given node in a tree.
 *
 * @param T The tree in which to search for the predecessor.
 * @param x The node for which to find the predecessor.
 * @return The predecessor node of x, or NULL if x has no predecessor.
 */
Node* predecessor(Node* x);

/**
 * Prints the contents of a node.
 *
 * @param x The node to be printed.
 */
void printNode(Node* x);

/**
 * Performs an inorder tree walk starting from the given node.
 *
 * @param x The starting node of the tree.
 */
void inorderTreeWalk(Node* x);

/**
 * Transplants the subtree rooted at node v into the position of the subtree rooted at node u.
 * This operation effectively replaces the subtree rooted at node u with the subtree rooted at node v.
 *
 * @param T The tree containing the nodes.
 * @param u The node whose subtree will be replaced.
 * @param v The node whose subtree will replace the subtree rooted at node u.
 */
void transplant(Tree* T, Node* u, Node* v);

/**
 * Deletes a node from the tree.
 *
 * @param T The tree from which to delete the node.
 * @param z The node to be deleted.
 */
void deleteNode(Tree* T, Node* z);

/**
 * Calculates the height of a tree rooted at the given node.
 *
 * @param x The root node of the tree.
 * @return The height of the tree.
 */
int treeHeight(Node* x);

/**
 * Calculates the balance factor of a BST with the given node x as its root.
 *
 * @param x The node for which to calculate the balance factor.
 * @return The balance factor of the node.
 */
int treeBalanceFactor(Node* x);

#endif