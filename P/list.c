#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Function to prepend a node to a linked list
int prepend(List* L, LLNode* x) {
    if (x == NULL) { // If x is NULL, return 0
        return 0;
    }
    x->next = L->head; // Set the next of x to the head
    x->prev = NULL; // Set the prev of x to NULL
    if (L->head != NULL) { // If the head is not NULL
        L->head->prev = x; // Set the prev of the head to x
    }
    L->head = x; // Set the head to x
    if (L->tail == NULL) { // If the tail is NULL
        L->tail = x; // Set the tail to x
    }
    return 1; // Return 1 to indicate success
}

// Function to create a new linked list node
LLNode* createLLNode(int data) {
    LLNode* newLLNode = (LLNode*)malloc(sizeof(LLNode)); // Allocate memory for the new LLNode
    newLLNode->data = data; // Set the data of the new LLNode
    newLLNode->prev = NULL; // Set the prev of the new LLNode to NULL
    newLLNode->next = NULL; // Set the next of the new LLNode to NULL
    return newLLNode; // Return the new LLNode
}

// Function to print the linked list
void printList(List* L) {
    LLNode* currentLLNode = L->head; // Start from the head
    while(currentLLNode != NULL) { // Loop through the list
        printf("%d ", currentLLNode->data); // Print the data of the current LLNode
        currentLLNode = currentLLNode->next; // Move to the next LLNode
    }
    printf("\n");
}

// Function to free the linked list
void freeList(List* L) {
    LLNode* currentLLNode = L->head; // Start from the head
    while(currentLLNode != NULL) { // Loop through the list
        LLNode* nextLLNode = currentLLNode->next; // Store the next LLNode
        free(currentLLNode); // Free the current LLNode
        currentLLNode = nextLLNode; // Move to the next LLNode
    }
    free(L); // Free the list
}