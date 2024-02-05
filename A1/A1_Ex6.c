#include <stdio.h>
#include <stdlib.h>

// Define the Node and List structures
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
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
    List* queue = (List*)malloc(sizeof(List)); // Allocate memory for the new stack
    queue->head = NULL; // Set the head of the stack to NULL
    queue->tail = NULL; // Set the tail of the stack to NULL
    return queue; // Return the new stack
}

// Function to enqueue an element onto the queue
void enqueue(List* queue, int data) {
    Node* newNode = createNode(data);
    if(queue->tail != NULL) {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;
    if(queue->head == NULL) {
        queue->head = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(List* queue) {
    Node* temp = queue->head;
    int data = temp->data;
    queue->head = queue->head->next;
    if(queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    return data;
}

int main() {
    List* queue = createQueue();

    int Personnr[] = {2, 0, 0, 3, 1, 1, 1, 2, 1, 2, 3, 4};

    // Enqueue the elements onto the queue
    for (int i = 0; i < 12; i++) {
        enqueue(queue, Personnr[i]);
    }

    printf("Dequeued %d\n", dequeue(queue)); // prints: 2
    printf("Dequeued %d\n", dequeue(queue)); // prints: 0
    printf("Dequeued %d\n", dequeue(queue)); // prints: 0
    return 0;
}