#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
    Tree* myBST = createTree(); // Create a new binary search tree

    int Array[] = {2, 0, 0, 3, 1, 1, 1, 2, 9, 9, 9, 9}; // Define an array of elements

    // Insert the elements from the array into the binary search tree
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
    int digits[] = {0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};

    for (int i = 0; i < 10; i++) {
        Node* searchNode = search(myBST->root, digits[i]);
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
        printf("\n2.6 The predecessor of the maximum key is: %d\n", predecessor(maximum(myBST->root))->key);
    } else {    
        printf("\n2.6 The maximum key has no predecessor\n");
    }

    // 2.7
    // Checks if the minimum key has a predecessor before printing
    if (predecessor(minimum(myBST->root)) != NULL) {
        printf("\n2.7 The predecessor of the minimum key is: %d\n", predecessor(minimum(myBST->root))->key);
    } else {
        printf("\n2.7 The minimum key has no predecessor\n");
    }

    // 2.8
    deleteNode(myBST, myBST->root);
    printf("\n2.8 The root's key is now: %d\n", myBST->root->key);

    return 0;
}