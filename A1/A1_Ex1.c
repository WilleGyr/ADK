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

// Define the isEmpty function
int isEmpty(List* L) {
    return L->head == NULL; // If the head is NULL, the list is empty
}

// Define the search function
Node* search(List* L, int k) {
    Node* currentNode = L->head; // Start from the head
    while(currentNode != NULL) { // Loop through the list
        if(currentNode->data == k) { // If the data is found, return the node
            return currentNode;
        }
        currentNode = currentNode->next; // Move to the next node
    }
    return NULL; // If the data is not found, return NULL
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

// Define the delete function
Node* delete(List* L, Node* x) {
    if (x == NULL) { // If x is NULL, return NULL
        return NULL;
    }
    if (x->prev != NULL) { // If the prev of x is not NULL
        x->prev->next = x->next; // Set the next of the prev of x to the next of x
    } else {
        L->head = x->next; // Set the head to the next of x
    }
    if (x->next != NULL) { // If the next of x is not NULL
        x->next->prev = x->prev; // Set the prev of the next of x to the prev of x
    } else {
        L->tail = x->prev; // Set the tail to the prev of x
    }
    return x; // Return the deleted node x
}

// Define the maximum function
Node* maximum(List* L) {
    if (L->head == NULL) { // If the head is NULL, return NULL
        return NULL;
    }
    Node* maxNode = L->head; // Define the maximum node as the head
    Node* currentNode = L->head->next; // Start from the next of the head
    while(currentNode != NULL) { // Loop through the list
        if(currentNode->data > maxNode->data) { // If the data of the current node is greater than the maximum node
            maxNode = currentNode; // Set the maximum node to the current node
        }
        currentNode = currentNode->next; // Move to the next node
    }
    return maxNode; // Return the maximum node
}

// Define the minimum function
Node* minimum(List* L) {
    if (L->head == NULL) { // If the head is NULL, return NULL
        return NULL;
    }
    Node* minNode = L->head; // Define the minimum node as the head
    Node* currentNode = L->head->next; // Start from the next of the head
    while(currentNode != NULL) { // Loop through the list
        if(currentNode->data < minNode->data) { // If the data of the current node is less than the minimum node
            minNode = currentNode; // Set the minimum node to the current node
        }
        currentNode = currentNode->next; // Move to the next node
    }
    return minNode; // Return the minimum node
}

// Define the successor function
Node* successor(List* L, Node* x) {
    if (x == NULL) { // If x is NULL, return NULL
        return NULL;
    }
    Node* sucNode = NULL; // Define the successor node as NULL
    Node* currentNode = L->head; // Start from the head
    while(currentNode != NULL) { // Loop through the list
        // If the data of the current node is greater than the data of x and
        // the successor node is NULL or the data of the current node is less than the data of the successor node
        if(currentNode->data > x->data && (sucNode == NULL || currentNode->data < sucNode->data)) {
            sucNode = currentNode; // Set the successor node to the current node
        }
        currentNode = currentNode->next; // Move to the next node
    }
    return sucNode; // x is the successor
}

// Define the predecessor function
Node* predecessor(List* L, Node* x) {
    if (x == NULL) { // If x is NULL,
        return NULL;
    }
    Node* predNode = NULL; // Define the predecessor node as NULL
    Node* currentNode = L->head; // Start from the head
    while(currentNode != NULL) { // Loop through the list
        // If the data of the current node is less than the data of x and
        // the predecessor node is NULL or the data of the current node is greater than the data of the predecessor node
        if(currentNode->data < x->data && (predNode == NULL || currentNode->data > predNode->data)) {
            predNode = currentNode; // Set the predecessor node to the current node
        }
        currentNode = currentNode->next; // Move to the next node
    }
    return predNode; // x is the predecessor
}

// Define the createNode function
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data; // Set the data of the new node
    newNode->prev = NULL; // Set the prev of the new node to NULL
    newNode->next = NULL; // Set the next of the new node to NULL
    return newNode; // Return the new node
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

// Define the free list function
void freeList(List* L) {
    Node* currentNode = L->head; // Start from the head
    while(currentNode != NULL) { // Loop through the list
        Node* nextNode = currentNode->next; // Store the next node
        free(currentNode); // Free the current node
        currentNode = nextNode; // Move to the next node
    }
    free(L); // Free the list
}

int main() {
    // Create two new lists
    List* L1 = (List*)malloc(sizeof(List));
    L1->head = NULL;
    L1->tail = NULL;

    List* L2 = (List*)malloc(sizeof(List));
    L2->head = NULL;
    L2->tail = NULL;

    int Array1[] = {3, 1, 5, 10, 8, 7};
    int Array2[] = {5, 2, 9, 6, 1, 2};

    // Add the elements to the lists
    for (int i = 0; i < 6; i++) {
        Node* newNode1 = createNode(Array1[i]);
        prepend(L1, newNode1);
    }
    for (int i = 0; i < 6; i++) {
        Node* newNode2 = createNode(Array2[i]);
        prepend(L2, newNode2);
    }

    insert(L1, createNode(99),L1->head->next);
    
    printf("Is the list empty? %d\n", isEmpty(L1));
    printf("List 1 has maximum: %d\n", maximum(L1)->data);
    printf("List 1 has minimum: %d\n", minimum(L1)->data);
    printf("List 2 has maximum: %d\n", maximum(L2)->data);
    printf("List 2 has minimum: %d\n", minimum(L2)->data);

    printf("Predecessor of %d in list 1: %d\n", search(L1, 5)->data, predecessor(L1, search(L1, 5))->data);
    printf("Successor of %d in list 1: %d\n", search(L1, 5)->data, successor(L1, search(L1, 5))->data);
    printf("Predecessor of %d in list 2: %d\n", search(L2, 9)->data, predecessor(L2, search(L2, 9))->data);
    //printf("Successor of %d in list 2: %d\n", search(L2, 9)->data, successor(L2, search(L2, 9))->data);

    printf("Predecessor in L2 of the maximum in L1: %d\n", predecessor(L2, maximum(L1))->data);
    printf("Predecessor in L1 of the maximum in L2: %d\n", predecessor(L1, maximum(L2))->data);

    printList(L1);
    printList(L2);
    delete(L2, L1->head->next->next);
    printList(L2);
    // Free up the memory used by the lists when done
    freeList(L1);
    freeList(L2);
    return 0;
}