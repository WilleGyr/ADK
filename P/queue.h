// Define the Node and Queue structures
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

/**
 * @struct Node
 * @brief Represents a node in a graph.
 * 
 * A node contains data and pointers to its adjacent nodes.
 */
Node* createNode(int data);

/**
 * @brief Creates a new Queue object.
 * 
 * @return Pointer to the newly created Queue object.
 */
Queue* createQueue();

/**
 * @brief Enqueues an element into the queue.
 * 
 * @param queue The queue to enqueue the element into.
 * @param data The data to be enqueued.
 */
void enqueue(Queue* queue, int data);

/**
 * @brief Removes and returns the element at the front of the queue.
 *
 * This function dequeues an element from the specified queue and returns its value.
 *
 * @param queue The queue from which to dequeue an element.
 * @return The value of the dequeued element.
 */
int dequeue(Queue* queue);