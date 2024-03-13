#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph)); // Allocate memory for the new graph
    graph->numVertices = numVertices; // Set the number of vertices

    // Initialize the adjacency matrix
    graph->adjMatrix = (int**)malloc((numVertices + 1) * sizeof(int*));
    for (int i = 0; i <= numVertices; i++) {
        graph->adjMatrix[i] = (int*)calloc((numVertices + 1), sizeof(int));
    }

    // Initialize the vertices
    graph->vertices = (Vertex*)malloc((numVertices + 1) * sizeof(Vertex));
    for (int i = 1; i <= numVertices; i++) {
        graph->vertices[i].id = i;
        graph->vertices[i].distance = -1; // Initialize with -1
        graph->vertices[i].visited = 0;
    }

    return graph; // Return the new graph
}

// Function to add a directed edge from src to dest
void addDirectedEdge(Graph* graph, int src, int dest) {
    graph->adjMatrix[src][dest] = 1; // Set the adjacency matrix value to 1
}

// Function to add an undirected edge between src and dest
void addUndirectedEdge(Graph* graph, int src, int dest) {
    addDirectedEdge(graph, src, dest); // Add the directed edge from src to dest
    addDirectedEdge(graph, dest, src); // Add the directed edge from dest to src
}

// Function to get the number of vertices in the graph
int getNumVertices(Graph* graph) {
    return graph->numVertices; // Return the number of vertices
}