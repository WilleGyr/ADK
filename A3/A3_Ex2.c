#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tree.h"
#include "load_file.h"
#include "generate_array.c"

void balanceFactor(int arraySize, int numArrays){
    // Seed the random number generator
    srandom(time(NULL));

    // Todo: create array to store balance factors
    int bf_array[numArrays];

    for (int i = 0; i < numArrays; ++i) {
        // Generate a randomized array
        int* resultArray = generateRandomArray(arraySize);

        // Print the randomized array
        printf("Random Order Array: ");
        for (int j = 0; j < arraySize; ++j) {
            printf("%d ", resultArray[j]);
        }
        printf("\n");

        // Create a new BST and insert the elements from the randomized array into the BST
        Tree* myBST = createTree();
        for (int i = 0; i < arraySize; i++) {
            Node* newNode = createNode(resultArray[i]);
            insert(myBST, newNode);
        }

        // Calculate balance factor using the function treeBalanceFactor from tree_func.c
        int bf = treeBalanceFactor(myBST->root);

        // Store balance factor in the array
        bf_array[i] = bf;

        // Free the memory allocated for the array
        free(resultArray);
    }
    // Print balance factors of all arrays
    printf("Balance Factors: ");
    for (int i = 0; i < numArrays; i++) {
        printf("%d ", bf_array[i]);
    }
    printf("\n");
}

int main(){
    // 3
    // Compute the balance factor of 50 arrays of size 7
    // BF Range: [0, 5]
    balanceFactor(7, 50);

    // 4
    // Compute the balance factor of 50 arrays of size 15
    // BF Range: [0, 9]
    balanceFactor(15, 50);

    return 0;
}