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

// Function to get the number of edges in the graph
int getNumEdges(Graph* graph) {
    int numEdges = 0;
    for (int i = 1; i <= graph->numVertices; i++) {
        for (int j = 1; j <= graph->numVertices; j++) {
            if (graph->adjMatrix[i][j]) {
                numEdges++; // Increment the number of edges
            }
        }
    }
    return numEdges; // Return the number of edges
}

// Function to check if the graph is directed
int isDirected(Graph* graph) {
    for (int i = 1; i <= graph->numVertices; i++) {
        for (int j = 1; j <= graph->numVertices; j++) {
            if (graph->adjMatrix[i][j] != graph->adjMatrix[j][i]) {
                return 1; // Return 1 if the adjacency matrix is not symmetric
            }
        }
    }
    return 0; // Return 0 if the adjacency matrix is symmetric
}

// Function to get the incoming adjacent vertices of a vertex
List* getInAdjs(Graph* graph, int vertex) {
    List* inAdjs = (List*)malloc(sizeof(List)); // Allocate memory for the list
    inAdjs->head = NULL; // Set the head of the list to NULL
    inAdjs->tail = NULL; // Set the tail of the list to NULL
    for (int i = 1; i <= graph->numVertices; i++) {
        if (graph->adjMatrix[i][vertex]) {
            LLNode* newNode = createLLNode(i); // Create a new linked list node
            prepend(inAdjs, newNode); // Prepend the node to the list
        }
    }
    return inAdjs; // Return the list of incoming adjacent vertices
}

// Function to get the outgoing adjacent vertices of a vertex
List* getOutAdjs(Graph* graph, int vertex) {
    List* outAdjs = (List*)malloc(sizeof(List)); // Allocate memory for the list
    outAdjs->head = NULL; // Set the head of the list to NULL
    outAdjs->tail = NULL; // Set the tail of the list to NULL
    for (int i = 1; i <= graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i]) {
            LLNode* newNode = createLLNode(i); // Create a new linked list node
            prepend(outAdjs, newNode); // Prepend the node to the list
        }
    }
    return outAdjs; // Return the list of outgoing adjacent vertices
}

// Function to get the linked vertices of a vertex
List* getLinked(Graph* graph, int vertex) {
    List* linked = (List*)malloc(sizeof(List)); // Allocate memory for the list
    linked->head = NULL; // Set the head of the list to NULL
    linked->tail = NULL; // Set the tail of the list to NULL
    for (int i = 1; i <= graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] || graph->adjMatrix[i][vertex]) {
            LLNode* newNode = createLLNode(i); // Create a new linked list node
            prepend(linked, newNode); // Prepend the node to the list
        }
    }
    return linked; // Return the list of linked vertices
}

// Function to check if there is an edge between two vertices
int hasEdge(Graph* graph, int src, int dest) {
    return graph->adjMatrix[src][dest]; // Return the value in the adjacency matrix
}

// Breadth-First Search algorithm
void BFS(Graph* graph, int start) {
    // Create a queue
    Queue* queue = createQueue();

    // Initialize the start vertex
    graph->vertices[start].distance = 0;
    graph->vertices[start].visited = 1;
    graph->vertices[start].predecessor = -1;  // Start vertex has no predecessor

    // Enqueue the start vertex
    enqueue(queue, start);

    while (queue->head != NULL) {
        // Dequeue a vertex
        int current = dequeue(queue);

        // Visit all the adjacent vertices of the dequeued vertex
        for (int i = 1; i <= graph->numVertices; i++) {
            if (graph->adjMatrix[current][i] && !graph->vertices[i].visited) {
                graph->vertices[i].visited = 1;
                graph->vertices[i].distance = graph->vertices[current].distance + 1;
                graph->vertices[i].predecessor = current;  // Set the predecessor
                enqueue(queue, i);
            }
        }
    }

    // Free the queue
    free(queue);
}

void printPath(Graph* graph, int start, int end) {
    if (start == end) {
        printf("%d ", start);
    } else if (graph->vertices[end].predecessor == -1) {
        printf("No path from %d to %d exists", start, end);
    } else {
        printPath(graph, start, graph->vertices[end].predecessor);
        printf("%d ", end);
    }
}

// Function to perform DFS and set finish times
void DFS(Graph* graph, int vertex, int* visited, int* finishTimes, int* time) {
    visited[vertex] = 1;
    if (finishTimes == NULL && time == NULL) {
        printf("%d ", vertex); // Print the vertex
    }
    for (int i = 1; i <= graph->numVertices; i++) {
        if (graph->adjMatrix[vertex][i] && !visited[i]) {
            DFS(graph, i, visited, finishTimes, time);
        }
    }
    if (finishTimes != NULL && time != NULL) {
        finishTimes[*time] = vertex;
        (*time)++;
    }
}

// Function to transpose the graph
Graph* transposeGraph(Graph* graph) {
    Graph* transposedGraph = createGraph(graph->numVertices);
    for (int i = 1; i <= graph->numVertices; i++) {
        for (int j = 1; j <= graph->numVertices; j++) {
            if (graph->adjMatrix[i][j]) {
                addDirectedEdge(transposedGraph, j, i);
            }
        }
    }
    return transposedGraph;
}

// Function to find strongly connected components
void stronglyConnectedComponents(Graph* graph, int start) {
    int* visited = (int*)calloc((graph->numVertices + 1), sizeof(int));
    int* finishTimes = (int*)malloc((graph->numVertices + 1) * sizeof(int));
    int time = 1;

    // 2.1
    DFS(graph, start, visited, finishTimes, &time);

    // Step 1: Perform DFS to compute finish times
    for (int i = 1; i <= graph->numVertices; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, finishTimes, &time);
        }
    }

    // Step 2: Create the transpose of the graph
    Graph* transposedGraph = transposeGraph(graph);

    // Step 3: Perform DFS on the transposed graph in order of decreasing finish times
    memset(visited, 0, (graph->numVertices + 1) * sizeof(int));
    for (int i = graph->numVertices; i >= 1; i--) {
        int vertex = finishTimes[i];
        if (!visited[vertex]) {
            printf("Strongly connected component: ");
            DFS(transposedGraph, vertex, visited, NULL, NULL);
            printf("\n");
        }
    }

    // Free allocated memory
    free(visited);
    free(finishTimes);
    free(transposedGraph);
}