#include <stdio.h>
#include <stdlib.h>

typedef struct PQNode {
    int data;
    int priority;
    struct Node* next;
} PQNode;

typedef struct PriorityQueue {
    PQNode* head;
} PriorityQueue;

PQNode* createPQNode(int data, int priority);

PriorityQueue* createPriorityQueue();

void PQenqueue(PriorityQueue* queue, int data, int priority);

int PQdequeue(PriorityQueue* queue);
