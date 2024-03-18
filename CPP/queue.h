#define SIZE 150

typedef struct {
    int vertex;
    int cost;
    int direction;
} Node;

typedef struct {
    Node nodes[SIZE];
    int size;
} PriorityQueue;

/**
 * @brief Adds a node to the priority queue.
 *
 * This function adds a node to the priority queue. The node is inserted
 * according to its priority value, with higher priority nodes being placed
 * closer to the front of the queue.
 *
 * @param queue A pointer to the priority queue.
 * @param node The node to be added to the queue.
 */
void enqueue(PriorityQueue* queue, Node node);

/**
 * Represents a node in a priority queue.
 */
Node dequeue(PriorityQueue* queue);

/**
 * Checks if the priority queue is empty.
 *
 * @param queue The priority queue to check.
 * @return True if the priority queue is empty, false otherwise.
 */
int isEmpty(PriorityQueue* queue);