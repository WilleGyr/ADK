#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

PQNode* createNode(int data, int priority) {
    PQNode* newNode = (PQNode*)malloc(sizeof(PQNode));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue* createPriorityQueue() {
    PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    queue->head = NULL;
    return queue;
}

void PQenqueue(PriorityQueue* queue, int data, int priority) {
    PQNode* newNode = createNode(data, priority);
    PQNode** current = &(queue->head);
    while (*current != NULL && (*current)->priority <= priority)
        current = &((*current)->next);
    newNode->next = *current;
    *current = newNode;
}

int PQdequeue(PriorityQueue* queue) {
    if (queue->head == NULL)
        return -1; // queue is empty
    PQNode* temp = queue->head;
    int data = temp->data;
    queue->head = queue->head->next;
    free(temp);
    return data;
}