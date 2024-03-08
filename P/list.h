// Define the Node and List structures
typedef struct LLNode {
   int data;
   struct LLNode *prev;
   struct LLNode *next;
} LLNode;

typedef struct List {
   LLNode *head;
   LLNode *tail;
} List;

/**
 * Adds a new node at the beginning of the list.
 *
 * @param L The list to prepend the node to.
 * @param x The node to prepend.
 * @return 0 if successful, -1 if an error occurred.
 */
int prepend(List* L, LLNode* x);

/**
 * @brief Creates a new LLNode with the given data.
 * 
 * @param data The data to be stored in the node.
 * @return Pointer to the newly created LLNode.
 */
LLNode* createLLNode(int data);

/**
 * Prints the elements of a given list.
 *
 * @param L The list to be printed.
 */
void printList(List* L);

/**
 * @brief Frees the memory allocated for a List.
 * 
 * @param L The List to be freed.
 */
void freeList(List* L);
