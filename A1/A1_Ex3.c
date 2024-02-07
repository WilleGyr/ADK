#include <stdio.h>
#include <stdlib.h>

// Define the Node and List structures
typedef struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
} Node;

typedef struct List {
   Node *head;
   Node *tail;
} List;

// Define the createNode function
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data; // Set the data of the new node
    newNode->prev = NULL; // Set the prev of the new node to NULL
    newNode->next = NULL; // Set the next of the new node to NULL
    return newNode; // Return the new node
}

// Define the insert function
int insert(List* L, Node* x, Node* y) {
    if (x == NULL || y == NULL) { // If either node is NULL, return 0
        return 0;
    }
    x->next = y->next; // Set the next of x to the next of y
    x->prev = y; // Set the prev of x to y
    if (y->next != NULL) { // If the next of y is not NULL
        y->next->prev = x; // Set the prev of the next of y to x
    }
    y->next = x; // Set the next of y to x
    if (L->tail == y) { // If y is the tail
        L->tail = x; // Set the tail to x
    }
    return 1; // Return 1 to indicate success
}

// Define the prepend function
int prepend(List* L, Node* x) {
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

// Define the countKey function
int countKey(List* L, int k){
    int count = 0; // Initialize the count to 0
    Node* currentNode = L->head; // Start from the head
    while(currentNode != NULL) { // Loop through the list
        if(currentNode->data == k) { // If the data is found, increment the count
            count++; // Increment the count
        }
        currentNode = currentNode->next; // Move to the next node
    }
    return count; // Return the count
}

// Define the free list function
void freeList(List* L) {
    Node* currentNode = L->head; // Start from the head
    while(currentNode != NULL) { // Loop through the list
        Node* nextNode = currentNode->next; // Store the next node
        free(currentNode); // Free the current node
        currentNode = nextNode; // Move to the next node
    }
}

// Define the printList function
void printList(List* L) {
    Node* currentNode = L->head; // Start from the head
    while(currentNode != NULL) { // Loop through the list
        printf("%d ", currentNode->data); // Print the data of the current node
        currentNode = currentNode->next; // Move to the next node
    }
    printf("\n");
}

int main(){
    // Create the new list
    List* L = (List*)malloc(sizeof(List));
    L->head = NULL;
    L->tail = NULL;

    int Personnr[] = {2, 0, 0, 3, 1, 1, 1, 2, 1, 2, 3, 4};

    // Create and prepend nodes to the list
    for (int i = 11; i >= 0; i--) {
        Node* newNode1 = createNode(Personnr[i]);
        prepend(L, newNode1);
    }

    printf("Count of 0 in presonnummer: %d\n", countKey(L, 99));

    freeList(L);
}