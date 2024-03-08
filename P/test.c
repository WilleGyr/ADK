#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include <limits.h>

#define SIZE 150

int is_no_edge_vertex(int vertex, int* no_edge_vertices, int no_edge_vertices_count) {
    for (int i = 0; i < no_edge_vertices_count; i++) {
        if (vertex == no_edge_vertices[i]) {
            return 1;
        }
    }
    return 0;
}

Graph* create_graph_from_file(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }

    char line[256];
    fgets(line, sizeof(line), file);

    int size = 0;
    char* token = strtok(line, " ");
    while (token != NULL) {
        size++;
        token = strtok(NULL, " ");
    }

    Graph* G = createGraph(size * size);

    int no_edge_vertices[size * size];
    int no_edge_vertices_count = 0;
    int index = 0;

    rewind(file);
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, " ");
        while (token != NULL) {
            int cost = atoi(token);
            G->vertices[index].cost = cost; // Store the cost
            if (cost == 0) {
                no_edge_vertices[no_edge_vertices_count++] = index;
            }
            index++;
            token = strtok(NULL, " ");
        }
    }

    fclose(file);

    for (int i = 0; i < size * size; i++) {
        if (is_no_edge_vertex(i, no_edge_vertices, no_edge_vertices_count)) continue;

        if (i >= size && !is_no_edge_vertex(i - size, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i - size);
        if (i < size * (size - 1) && !is_no_edge_vertex(i + size, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i + size);
        if (i % size != 0 && !is_no_edge_vertex(i - 1, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i - 1);
        if (i % size != size - 1 && !is_no_edge_vertex(i + 1, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G, i, i + 1);
    }

    return G;
}

typedef struct {
    int vertex;
    int cost;
    int direction;
} PQNode;

typedef struct {
    PQNode nodes[SIZE];
    int size;
} PriorityQueue;

// Enqueue function
void PQenqueue(PriorityQueue* queue, PQNode node) {
    if (queue->size >= SIZE) {
        printf("Queue is full\n");
        return;
    }
    queue->nodes[queue->size++] = node;
}

// Dequeue function
PQNode PQdequeue(PriorityQueue* queue) {
    int minIndex = 0;
    for (int i = 1; i < queue->size; i++) {
        if (queue->nodes[i].cost < queue->nodes[minIndex].cost) {
            minIndex = i;
        }
    }
    PQNode minNode = queue->nodes[minIndex];
    queue->nodes[minIndex] = queue->nodes[--queue->size];
    return minNode;
}

// isEmpty function
int PQisEmpty(PriorityQueue* queue) {
    return queue->size == 0;
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

#define DIRECTIONS 4

void PprintPath(int prev[][DIRECTIONS], int direction[][DIRECTIONS], int vertex, int dir) {
    if (prev[vertex][dir] == -1) {
        printf("%d ", vertex);
        return;
    }
    PprintPath(prev, direction, prev[vertex][dir], direction[vertex][dir]);
    printf("-> %d ", vertex);
}

void dijkstra(Graph* G, int source, int destination) {
    int dist[SIZE][DIRECTIONS];
    int prev[SIZE][DIRECTIONS];
    int direction[SIZE][DIRECTIONS];
    PriorityQueue queue = {0};

    // Initialize distances to infinity and previous vertices to -1
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < DIRECTIONS; j++) {
            dist[i][j] = INT_MAX;
            prev[i][j] = -1;
            direction[i][j] = -1;
        }
    }

    // The distance to the source vertex is the cost of the source vertex for all directions
    for (int i = 0; i < DIRECTIONS; i++) {
        dist[source][i] = G->vertices[source].cost;
        PQenqueue(&queue, (PQNode){source, G->vertices[source].cost, i});
    }


    while (!PQisEmpty(&queue)) {

        // Dequeue the vertex with the smallest distance
        PQNode node = PQdequeue(&queue);

        // For each neighbor of the current vertex
        for (int i = 0; i < getNumVertices(G); i++) {
            if (G->adjMatrix[node.vertex][i] != 0) {
                // Calculate the cost to reach the neighbor
                int dir = getDirection(node.vertex, i);
                int turnCost = abs(node.direction - dir) % 2 == 0 ? 0 : G->vertices[node.vertex].cost;
                int cost = dist[node.vertex][node.direction] + turnCost + G->vertices[i].cost;

                // If the calculated cost is less than the current distance to the neighbor
                if (cost < dist[i][dir]) {
                    // Update the distance to the neighbor
                    dist[i][dir] = cost;

                    // Update the previous vertex and direction
                    prev[i][dir] = node.vertex;
                    direction[i][dir] = node.direction;

                    // Enqueue the neighbor
                    PQenqueue(&queue, (PQNode){i, cost, dir});
                }
            }
        }
    }

    // Find the direction with the smallest distance at the destination vertex
    int minDirection = 0;
    for (int i = 1; i < DIRECTIONS; i++) {
        if (dist[destination][i] < dist[destination][minDirection]) {
            minDirection = i;
        }
    }

    // The distance to the destination vertex is the cost of the cheapest path
    printf("The cost of the cheapest path is %d\n", dist[destination][minDirection]);

    // Print the cheapest path
    printf("The cheapest path is: ");
    PprintPath(prev, direction, destination, minDirection);
    printf("\n");
}

int main( int argc, char *argv[]){

    char *filename = argv[1];

    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    Graph* G = create_graph_from_file(filename);

    // Print the adjacency matrix using a for loop
    for (int i = 0; i < G->numVertices; i++) {
        for (int j = 0; j < G->numVertices; j++) {
            printf("%d ", G->adjMatrix[i][j]);
        }
        printf("\n");
    }

    // Print the path with the lowest cost from vertex 0 to 14
    dijkstra(G, start, end);


    return 0;
}