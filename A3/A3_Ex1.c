#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    // Create a new BST
    Tree* myBST = createTree();

    // Array of integers to insert into the BST
    int Array[] = {2, 0, 0, 3, 1, 1, 1, 2, 9, 9, 9, 9};

    // Insert the elements from the array into the BST
    for (int i = 0; i < 12; i++) {
        Node* newNode = createNode(Array[i]);
        insert(myBST, newNode);
    }

    // 2.1
    printf("2.1\n");
    inorderTreeWalk(myBST->root);
    printf("\n");

    // 2.2
    printf("\n2.2 The root's key is: %d\n", myBST->root->key);

    // 2.3
    // Array of integers to insert into the BST
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};

    // Insert the elements from the array into the BST if they don't already exist
    for (int i = 0; i < 10; i++){
        // Search for the current digit in the BST
        Node* searchNode = search(myBST->root, digits[i]);

        // If the digit is not found, insert it into the BST
        if (searchNode == NULL) {
            Node* newNode = createNode(digits[i]);
            insert(myBST, newNode);
        }
    }
    printf("\n2.3\n");
    inorderTreeWalk(myBST->root);
    printf("\n");

    // 2.4
    printf("\n2.4 The root's key is still: %d\n", myBST->root->key);

    // 2.5
    printf("\n2.5 The predecessor of the root is: %d\n", predecessor(myBST->root)->key);

    // 2.6
    // Checks if the maximum key has a predecessor before printing
    if (predecessor(maximum(myBST->root)) != NULL) {
        // Print the predecessor of the maximum key
        printf("\n2.6 The predecessor of the maximum key is: %d\n", predecessor(maximum(myBST->root))->key);
    } else {
        // Print a message indicating that the maximum key has no predecessor
        printf("\n2.6 The maximum key has no predecessor\n");
    }

    // 2.7
    // Checks if the minimum key has a predecessor before printing
    if (predecessor(minimum(myBST->root)) != NULL) {
        // Print the predecessor of the minimum key
        printf("\n2.7 The predecessor of the minimum key is: %d\n", predecessor(minimum(myBST->root))->key);
    } else {
        // Print a message indicating that the minimum key has no predecessor
        printf("\n2.7 The minimum key has no predecessor\n");
    }

    // 2.8
    // Delete the root node and then print the new root's key
    deleteNode(myBST, myBST->root);
    printf("\n2.8 The root's key is now: %d\n", myBST->root->key);

    return 0;
}