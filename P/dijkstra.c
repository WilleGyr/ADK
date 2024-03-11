#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "graph.h"
#include "dijkstra.h"

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
    G->size = size;
    return G;
}

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

void PprintPath(int prev[][DIRECTIONS], int direction[][DIRECTIONS], int vertex, int dir, int size) {
    if (prev[vertex][dir] != -1) {
        PprintPath(prev, direction, prev[vertex][dir], direction[vertex][dir], size);
        printf("-> ");
    }
    printf("(%d, %d)", vertex / size, vertex % size);
}

void dijkstra(Graph* G, int sourcex, int sourcey, int destinationx, int destinationy) {
    int source = sourcex * G->size + sourcey;
    int destination = destinationx * G->size + destinationy;

    int dist[SIZE][DIRECTIONS];
    int prev[SIZE][DIRECTIONS];
    int direction[SIZE][DIRECTIONS];
    int turns[SIZE][DIRECTIONS];
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
                int newTurns = turns[node.vertex][node.direction] + (node.direction != dir ? 1 : 0);

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
                    PQenqueue(&queue, (PQNode){i, cost, dir});
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

    // The distance to the destination vertex is the cost of the cheapest path
    printf("The cost of the cheapest path is %d\n", dist[destination][minDirection]);

    // Print the cheapest path
    printf("The cheapest path is: ");
    int size = sqrt(getNumVertices(G));
    PprintPath(prev, direction, destination, minDirection, size);
    printf("\n");
}