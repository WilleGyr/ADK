#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    newNode->data = data; // Set the data of the new node
    newNode->next = NULL; // Set the next of the new node to NULL
    return newNode; // Return the new node
}

// Function to initialize a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); // Allocate memory for the new queue
    queue->head = NULL; // Set the head of the queue to NULL
    queue->tail = NULL; // Set the tail of the queue to NULL
    return queue; // Return the new queue
}

// Function to enqueue an element onto the queue
void enqueue(Queue* queue, int data) {
    Node* newNode = createNode(data); // Create a new node with the given data
    if(queue->tail != NULL) { // If the tail of the queue is not NULL
        queue->tail->next = newNode; // Set the next of the tail of the queue to the new node
    }
    queue->tail = newNode; // Set the tail of the queue to the new node
    if(queue->head == NULL) { // If the head of the queue is NULL
        queue->head = newNode; // Set the head of the queue to the new node
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    Node* temp = queue->head; // Store the head of the queue in a temporary variable
    int data = temp->data; // Store the data of the head of the queue
    queue->head = queue->head->next; // Set the head of the queue to the next of the head
    if(queue->head == NULL) { // If the head of the queue is NULL
        queue->tail = NULL; // Set the tail of the queue to NULL
    }
    free(temp); // Free the temporary variable
    return data; // Return the data of the head of the queue
}