#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
   int data;
   struct Node *prev;
   struct Node *next;
} Node;

// Define the List structure
typedef struct List {
   Node *head;
   Node *tail;
} List;

int isEmpty(List* L) {
    return L->head == NULL;
}

Node* search(List* L, int k) {
    Node* currentNode = L->head;
    while(currentNode != NULL) {
        if(currentNode->data == k) {
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return NULL;
}

int insert(List* L, Node* x, Node* y) {
    if (x == NULL || y == NULL) {
        return 0;
    }
    x->next = y->next;
    x->prev = y;
    if (y->next != NULL) {
        y->next->prev = x;
    }
    y->next = x;
    if (L->tail == y) {
        L->tail = x; // if y was the tail, x is the new tail now
    }
    return 1;
}

int prepend(List* L, Node* x) {
    if (x == NULL) {
        return 0;
    }
    x->next = L->head;
    x->prev = NULL;
    if (L->head != NULL) {
        L->head->prev = x;
    }
    L->head = x;
    if (L->tail == NULL) {
        L->tail = x; // if the list was empty, x is also the tail now
    }
    return 1;
}

Node* delete(List* L, Node* x) {
    if (x == NULL) {
        return NULL;
    }
    if (x->prev != NULL) {
        x->prev->next = x->next;
    } else {
        L->head = x->next; // if x was the head, the next node is the new head now
    }
    if (x->next != NULL) {
        x->next->prev = x->prev;
    } else {
        L->tail = x->prev; // if x was the tail, the previous node is the new tail now
    }
    return x;
}

Node* maximum(List* L) {
    if (L->head == NULL) {
        return NULL;
    }
    Node* maxNode = L->head;
    Node* currentNode = L->head->next;
    while(currentNode != NULL) {
        if(currentNode->data > maxNode->data) {
            maxNode = currentNode;
        }
        currentNode = currentNode->next;
    }
    return maxNode;
}

Node* minimum(List* L) {
    if (L->head == NULL) {
        return NULL;
    }
    Node* minNode = L->head;
    Node* currentNode = L->head->next;
    while(currentNode != NULL) {
        if(currentNode->data < minNode->data) {
            minNode = currentNode;
        }
        currentNode = currentNode->next;
    }
    return minNode;
}

Node* successor(List* L, Node* x) {
    if (x == NULL || x == L->tail) {
        return NULL;
    }
    return x->next;
}

Node* predecessor(List* L, Node* x) {
    if (x == NULL || x == L->head) {
        return NULL;
    }
    return x->prev;
}

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void printList(List* L) {
    Node* currentNode = L->head;
    while(currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    // Create two new lists
    List* L1 = (List*)malloc(sizeof(List));
    L1->head = NULL;
    L1->tail = NULL;
    /*
    List* L2 = (List*)malloc(sizeof(List));
    L2->head = NULL;
    L2->tail = NULL;
    */
   // Create a new node
   Node* x1 = createNode(3);
   prepend(L1, x1);
   Node* x2 = createNode(1);
   insert(L1, x2, x1);
   Node* x3 = createNode(5);
   insert(L1, x3, x2);
   Node* x4 = createNode(10);
   insert(L1, x4, x3);
   Node* x5 = createNode(8);
   insert(L1, x5, x4);
   Node* x6 = createNode(7);
   insert(L1, x6, x5);
   
   printf("Node has key: %d\n", search(L1, 5)->data);

   printList(L1);
   return 0;
}
