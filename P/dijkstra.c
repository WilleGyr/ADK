#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "graph.h"
#include "dijkstra.h"

// Function to check if a vertex is in the list of no-edge vertices
int is_no_edge_vertex(int vertex, int* no_edge_vertices, int no_edge_vertices_count) {
    // Goes through the array of no-edge vertices and checks if the given vertex is in the array
    for (int i = 0; i < no_edge_vertices_count; i++) {
        if (vertex == no_edge_vertices[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to create a graph from a file
Graph* create_graph_from_file(char* filename) {
    // Define the path to the file
    char path[100] = "P_material_VT24/";
    // Append the filename to the path
    strcat(path, filename);

    // Open the file for reading
    FILE* file = fopen(path, "r");
    // If the file could not be opened, print an error message and return NULL
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    char line[256];
    // Read the first line of the file
    fgets(line, sizeof(line), file);

    // Initialize the size of the graph to 0
    int size = 0;
    // Tokenize the line on spaces
    char* token = strtok(line, " ");
    // Count the number of tokens in the line to get the size of the graph
    while (token != NULL) {
        size++;
        token = strtok(NULL, " ");
    }

    // Create a new graph with size * size vertices
    Graph* G = createGraph(size * size);

    // Initialize an array to store the vertices with no edges
    int no_edge_vertices[size * size];
    // Initialize a counter for the number of vertices with no edges
    int no_edge_vertices_count = 0;
    // Initialize an index to keep track of the current vertex
    int index = 0;

    // Rewind the file to the beginning
    rewind(file);
    // Read the file line by line
    while (fgets(line, sizeof(line), file)) {
        // Tokenize the line on spaces
        token = strtok(line, " ");
        // For each token in the line
        while (token != NULL) {
            // Convert the token to an integer to get the cost of the vertex
            int cost = atoi(token);
            // Store the cost in the graph
            G->vertices[index].cost = cost;
            // If the cost is 0, add the vertex to the array of vertices with no edges
            if (cost == 0) {
                no_edge_vertices[no_edge_vertices_count++] = index;
            }
            // Increment the index
            index++;
            // Get the next token
            token = strtok(NULL, " ");
        }
    }

    // Close the file
    fclose(file);

    // For each vertex in the graph
    for (int i = 0; i < size * size; i++) {
        // If the vertex has no edges, skip it
        if (is_no_edge_vertex(i, no_edge_vertices, no_edge_vertices_count)) continue;

        // If the vertex is not on the top edge of the graph and the vertex above it has edges, add an edge between them
        if (i >= size && !is_no_edge_vertex(i - size, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i - size);
        // If the vertex is not on the bottom edge of the graph and the vertex below it has edges, add an edge between them
        if (i < size * (size - 1) && !is_no_edge_vertex(i + size, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i + size);
        // If the vertex is not on the left edge of the graph and the vertex to the left of it has edges, add an edge between them
        if (i % size != 0 && !is_no_edge_vertex(i - 1, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i - 1);
        // If the vertex is not on the right edge of the graph and the vertex to the right of it has edges, add an edge between them
        if (i % size != size - 1 && !is_no_edge_vertex(i + 1, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i + 1);
    }
    // Set the size of the graph
    G->size = size;
    // Return the graph
    return G;
}

// getDirection function
int getDirection(int current, int next) {
    if (next == current - 1) {
        return 0; // Up
    } else if (next == current + 1) {
        return 2; // Down
    } else if (next < current) {
        return 3; // Left
    } else {
        return 1; // Right
    }
}

// Function to print the shortest path from the source to a given vertex
void PrintPath(int prev[][DIRECTIONS], int direction[][DIRECTIONS], int vertex, int dir, int size) {
    // If the previous vertex in the path from the source to this vertex exists
    if (prev[vertex][dir] != -1) {
        // Recursively call PrintPath for the previous vertex
        PrintPath(prev, direction, prev[vertex][dir], direction[vertex][dir], size);
        // Print an arrow indicating the direction from the previous vertex to this vertex
        printf(" -> ");
    }
    // Print the coordinates of this vertex
    // The row number (x-coordinate) is the vertex number divided by the size of the graph
    // The column number (y-coordinate) is the vertex number modulo the size of the graph
    printf("\n(%d, %d)", vertex / size, vertex % size);
}

// Function to print the graph with the shortest path from the source to the destination
void printGraphWithPath(Graph* G, int prev[][DIRECTIONS], int direction[][DIRECTIONS], int destination, int minDirection) {
    int size = G->size;
    int isOnPath[size * size];
    memset(isOnPath, 0, sizeof(isOnPath));

    int current = destination;
    int dir = minDirection;

    // Trace the path from the destination back to the source
    while (current != -1) {
        isOnPath[current] = 1;
        int next = prev[current][dir];
        dir = direction[current][dir];
        current = next;
    }

    // Iterate over all vertices in the graph
    for (int i = 0; i < size * size; i++) {
        // Start a new line for each row of vertices
        if (i % size == 0) {
            printf("\n");
        }

        // Check if the current vertex is on the path
        if (isOnPath[i]) {
            printf("\x1b[32m%d \x1b[0m", G->vertices[i].cost);
        } else {
            // Check the cost of the current vertex
            if (G->vertices[i].cost == 0) {
                printf("\x1b[31m%d \x1b[0m", G->vertices[i].cost);
            } else {
                printf("%d ", G->vertices[i].cost);
            }
        }
    }
    printf("\n");
}

// Function to perform Dijkstra's algorithm on a graph
void dijkstra(Graph* G, int sourcex, int sourcey, int destinationx, int destinationy) {
    // Convert the source and destination coordinates to vertices
    int source = sourcex * G->size + sourcey;
    int destination = destinationx * G->size + destinationy;

    // Arrays to store distances, previous vertices, directions, and turns
    int dist[SIZE][DIRECTIONS];
    int prev[SIZE][DIRECTIONS];
    int direction[SIZE][DIRECTIONS];
    int turns[SIZE][DIRECTIONS];

    // Priority queue to store vertices
    PriorityQueue queue = {0};

    // Initialize distances to infinity, previous vertices to -1, and turns to 0
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < DIRECTIONS; j++) {
            dist[i][j] = INT_MAX;
            prev[i][j] = -1;
            direction[i][j] = -1;
            turns[i][j] = 0;
        }
    }

    // The distance to the source vertex is the cost of the source vertex for all directions
    for (int i = 0; i < DIRECTIONS; i++) {
        dist[source][i] = G->vertices[source].cost;
        Node node;
        node.vertex = source;
        node.cost = G->vertices[source].cost;
        node.direction = i;
        enqueue(&queue, node);
    }

    // Dijkstra's algorithm
    while (!isEmpty(&queue)) {
        // Dequeue the vertex with the smallest distance
        Node node = dequeue(&queue);

        // For each neighbor of the current vertex
        for (int i = 0; i < getNumVertices(G); i++) {
            if (G->adjMatrix[node.vertex][i] != 0) {
                // Calculate the cost to reach the neighbor
                int dir = getDirection(node.vertex, i);
                int turnCost;
                if (abs(node.direction - dir) % 2 == 0) {
                    turnCost = 0;
                } else {
                    turnCost = G->vertices[node.vertex].cost;
                }
                int cost = dist[node.vertex][node.direction] + turnCost + G->vertices[i].cost;
                int newTurns = turns[node.vertex][node.direction];
                if (node.direction != dir) {
                    newTurns += 1;
                }
                // If the calculated cost is less than the current distance to the neighbor
                // or the cost is equal but the number of turns is less
                if (cost < dist[i][dir] || (cost == dist[i][dir] && newTurns < turns[i][dir])) {
                    // Update the distance to the neighbor
                    dist[i][dir] = cost;

                    // Update the number of turns
                    turns[i][dir] = newTurns;

                    // Update the previous vertex and direction
                    prev[i][dir] = node.vertex;
                    direction[i][dir] = node.direction;

                    // Enqueue the neighbor
                    enqueue(&queue, (Node){i, cost, dir});
                }
            }
        }
    }

    // Find the direction with the smallest distance and the fewest turns at the destination vertex
    int minDirection = 0;
    for (int i = 1; i < DIRECTIONS; i++) {
        if (dist[destination][i] < dist[destination][minDirection] || 
            (dist[destination][i] == dist[destination][minDirection] && turns[destination][i] < turns[destination][minDirection])) {
            minDirection = i;
        }
    }

    // Print the energy consumption of the most efficient path from source to destination
    printf("\nThe energy consumption of the most efficient path(s) from (%d, %d) to (%d, %d) is \x1b[32m%d \x1b[0m\n", sourcex, sourcey, destinationx, destinationy, dist[destination][minDirection]);

    // Print the most efficient path with the fewest turns
    printf("\nThe most efficient path with the fewest turns is: ");
    int size = sqrt(getNumVertices(G));
    PrintPath(prev, direction, destination, minDirection, size);
    printf("\n");

    // Print the graph with the cheapest path highlighted
    printGraphWithPath(G, prev, direction, destination, minDirection);
}