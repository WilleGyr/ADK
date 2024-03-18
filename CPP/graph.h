typedef struct Vertex {
    int id;
    int distance;
    int cost;
    int visited;
    int predecessor;
} Vertex;

// Define the graph structure
typedef struct Graph {
    int numVertices;
    Vertex* vertices;
    int** adjMatrix;
    int size;
} Graph;

/**
 * @brief Creates a new graph with the specified number of vertices.
 * 
 * @param numVertices The number of vertices in the graph.
 * @return A pointer to the newly created graph.
 */
Graph* createGraph(int numVertices);

/**
 * Adds a directed edge from the source vertex to the destination vertex in the graph.
 *
 * @param graph The graph to add the edge to.
 * @param src The source vertex of the edge.
 * @param dest The destination vertex of the edge.
 */
void addDirectedEdge(Graph* graph, int src, int dest);

/**
 * Adds an undirected edge between two vertices in the graph.
 *
 * @param graph The graph to add the edge to.
 * @param src The source vertex of the edge.
 * @param dest The destination vertex of the edge.
 */
void addUndirectedEdge(Graph* graph, int src, int dest);

/**
 * Returns the number of vertices in the graph.
 *
 * @param graph The graph for which to get the number of vertices.
 * @return The number of vertices in the graph.
 */
int getNumVertices(Graph* graph);