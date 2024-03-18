#include "queue.h"

#define SIZE 150
#define DIRECTIONS 4

/**
 * Checks if a vertex is in the list of no-edge vertices.
 *
 * @param vertex The vertex to check.
 * @param no_edge_vertices An array of no-edge vertices.
 * @param no_edge_vertices_count The number of no-edge vertices in the array.
 * @return 1 if the vertex is in the list of no-edge vertices, 0 otherwise.
 */
int is_no_edge_vertex(int vertex, int* no_edge_vertices, int no_edge_vertices_count);

/**
 * Creates a graph object by reading data from a file.
 *
 * @param filename The name of the file to read the graph data from.
 * @return A pointer to the created Graph object, or NULL if an error occurred.
 */
Graph* create_graph_from_file(char* filename);

/**
 * Calculates the direction from the current node to the next node.
 *
 * @param current The current node.
 * @param next The next node.
 * @return The direction from the current node to the next node.
 */
int getDirection(int current, int next);

/**
 * Prints the path from a given vertex to the destination vertex.
 *
 * @param prev The 2D array representing the previous vertex for each vertex in the path.
 * @param direction The 2D array representing the direction of each vertex in the path.
 * @param vertex The starting vertex.
 * @param dir The direction of the starting vertex.
 * @param size The size of the arrays.
 */
void PrintPath(int prev[][DIRECTIONS], int direction[][DIRECTIONS], int vertex, int dir, int size);

/**
 * Prints the graph with the shortest path from a source node to a destination node.
 *
 * @param G The graph to print.
 * @param prev The array containing the previous node for each node in the shortest path.
 * @param direction The array containing the direction for each node in the shortest path.
 * @param destination The destination node.
 * @param minDirection The minimum direction to reach the destination node.
 */
void printGraphWithPath(Graph* G, int prev[][DIRECTIONS], int direction[][DIRECTIONS], int destination, int minDirection);

/**
 * Performs Dijkstra's algorithm on a graph to find the shortest path between two nodes.
 *
 * @param G The graph on which to perform Dijkstra's algorithm.
 * @param sourcex The x-coordinate of the source node.
 * @param sourcey The y-coordinate of the source node.
 * @param destinationx The x-coordinate of the destination node.
 * @param destinationy The y-coordinate of the destination node.
 */
void dijkstra(Graph* G, int sourcex, int sourcey, int destinationx, int destinationy);