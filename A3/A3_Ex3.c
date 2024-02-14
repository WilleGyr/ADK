#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "load_file.h"

int main(){

    // 3.1
    // Load the problem files
    int* p1000 = load_file("Problem_files/test-1000-1-problem");
    int* p100000 =  load_file("Problem_files/test-100000-1-problem");

    // 3.2
    // Create the BSTs
    Tree* BSTp1000 = createTree();
    Tree* BSTp100000 = createTree();

    // Insert the elements from the arrays into the BSTs
    for (int i = 0; i < 1000; i++) {
        Node* newNode = createNode(p1000[i]);
        insert(BSTp1000, newNode);
    }
    for (int i = 0; i < 100000; i++) {
        Node* newNode = createNode(p100000[i]);
        insert(BSTp100000, newNode);
    }

    // 3.3
    // Print the BSTs in ascening order using inorderTreeWalk
    inorderTreeWalk(BSTp1000->root);
    inorderTreeWalk(BSTp100000->root);

    // 3.4
    // Calculatethe balance factor of the two trees
    int bf1000 = treeBalanceFactor(BSTp1000->root);
    int bf100000 = treeBalanceFactor(BSTp100000->root);

    // Print the balance factors
    printf("\nBalance Factor of 1000: %d\n", bf1000);
    printf("Balance Factor of 100000: %d\n", bf100000);

    return 0;
}