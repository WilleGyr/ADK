#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"

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

void printPath(Graph* graph, int start, int end);

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

/**
 * Returns the number of edges in the given graph.
 *
 * @param graph The graph to get the number of edges from.
 * @return The number of edges in the graph.
 */
int getNumEdges(Graph* graph);

/**
 * Checks if the graph is directed.
 *
 * @param graph A pointer to the graph.
 * @return 1 if the graph is directed, 0 otherwise.
 */
int isDirected(Graph* graph);

/**
 * @struct List
 * @brief A data structure representing a linked list.
 */
List* getInAdjs(Graph* graph, int vertex);

/**
 * @struct List
 * @brief A data structure representing a linked list.
 */
List* getOutAdjs(Graph* graph, int vertex);

/**
 * @struct List
 * @brief A data structure representing a linked list.
 */
List* getLinked(Graph* graph, int vertex);

/**
 * Checks if there is an edge between two vertices in the graph.
 *
 * @param graph The graph to check.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @return 1 if there is an edge between the source and destination vertices, 0 otherwise.
 */
int hasEdge(Graph* graph, int src, int dest);

/**
 * Performs a breadth-first search (BFS) traversal on the given graph starting from the specified vertex.
 *
 * @param graph The graph to perform the BFS on.
 * @param start The starting vertex for the BFS traversal.
 */
void BFS(Graph* graph, int start);

/**
 * Performs a Depth-First Search (DFS) on the given graph starting from the specified vertex.
 * 
 * @param graph The graph to perform the DFS on.
 * @param vertex The starting vertex for the DFS.
 * @param visited An array to keep track of visited vertices.
 * @param finishTimes An array to store the finish times of vertices.
 * @param time A pointer to a variable representing the current time.
 */
void DFS(Graph* graph, int vertex, int* visited, int* finishTimes, int* time);

/**
 * Transposes a graph.
 *
 * This function takes a graph as input and returns a new graph that is the transpose of the input graph.
 * The transpose of a graph is obtained by reversing the direction of all edges in the graph.
 *
 * @param graph The graph to be transposed.
 * @return The transposed graph.
 */
Graph* transposeGraph(Graph* graph);

/**
 * Finds the strongly connected components in a graph starting from a given vertex.
 *
 * @param graph The graph to find the strongly connected components in.
 * @param start The starting vertex for the search.
 */
void stronglyConnectedComponents(Graph* graph, int start);

