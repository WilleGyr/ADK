#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Enqueue function
void enqueue(PriorityQueue* queue, Node node) {
    // Check if the queue is full
    if (queue->size >= SIZE) {
        printf("Queue is full\n");
        return;
    }
    // Add the node to the queue and increment the size
    queue->nodes[queue->size++] = node;
}

// Dequeue function
Node dequeue(PriorityQueue* queue) {
    int minIndex = 0; // Initialize the index of the node with the minimum cost to 0.
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i].cost < queue->nodes[minIndex].cost) {
            minIndex = i; // Update the index of the node with the minimum cost if a smaller cost is found.
        }
    }
    Node minNode = queue->nodes[minIndex]; // Store the node with the minimum cost in a variable.
    queue->nodes[minIndex] = queue->nodes[--queue->size]; // Replace the node with the minimum cost with the last node in the queue and decrement the queue size.
    
    return minNode; // Return the dequeued node with the minimum cost.
}

// isEmpty function
int isEmpty(PriorityQueue* queue) {
    // Return 1 if the queue is empty, 0 otherwise
    return queue->size == 0;
}