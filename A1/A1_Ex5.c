#include <stdio.h>
#include <stdlib.h>

// Define the Node and List structures
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
} List;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data; // Set the data of the new node
    newNode->next = NULL; // Set the next of the new node to NULL
    return newNode; // Return the new node
}

// Function to initialize a new stack
List* createStack() {
    List* stack = (List*)malloc(sizeof(List)); // Allocate memory for the new stack
    stack->head = NULL; // Set the head of the stack to NULL
    return stack; // Return the new stack
}

// Function to push an element onto the stack
void push(List* stack, int data) {
    Node* newNode = createNode(data); // Create a new node with the given data
    newNode->next = stack->head; // Set the next of the new node to the head of the stack
    stack->head = newNode; // Set the head of the stack to the new node
}

// Function to pop an element from the stack
int pop(List* stack) {
    Node* temp = stack->head; // Store the head of the stack in a temporary variable
    int data = temp->data; // Store the data of the head of the stack
    stack->head = stack->head->next; // Set the head of the stack to the next of the head
    free(temp); // Frees the temporary variable
    return data; // Return the data of the head of the stack
}

int main() {
    List* stack = createStack(); // Create a new stack

    int Personnr[] = {2, 0, 0, 3, 1, 1, 1, 2, 1, 2, 3, 4};

    // Push the elements onto the stack
    for (int i = 0; i < 12; i++) {
        push(stack, Personnr[i]);
    }

    printf("Popped %d\n", pop(stack)); // prints: 4
    printf("Popped %d\n", pop(stack)); // prints: 3
    printf("Popped %d\n", pop(stack)); // prints: 2
    return 0;
}