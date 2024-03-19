#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int is_no_edge_vertex(int vertex, int* no_edge_vertices, int no_edge_vertices_count) {
    for (int i = 0; i < no_edge_vertices_count; i++) {
        if (vertex == no_edge_vertices[i]) {
            return 1;
        }
    }
    return 0;
}

int main(){

    // Create graph
    Graph* G2 = createGraph(100);
    
    int no_edge_vertices[] = {18, 28, 38, 41, 42, 43, 44, 45, 46, 47, 48, 54, 64, 74, 84, 0, 10, 20, 30, 40, 50, 60, 70};
    int no_edge_vertices_count = sizeof(no_edge_vertices) / sizeof(no_edge_vertices[0]);

    for (int i = 0; i < 100; i++) {
        // Skip vertices that should not have any edges
        if (is_no_edge_vertex(i, no_edge_vertices, no_edge_vertices_count)) continue;

        // Add edges to the vertices above, below, to the left and to the right
        if (i >= 10 && !is_no_edge_vertex(i - 10, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G2, i, i - 10); // Above
        if (i < 90 && !is_no_edge_vertex(i + 10, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G2, i, i + 10); // Below
        if (i % 10 != 0 && !is_no_edge_vertex(i - 1, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G2, i, i - 1); // Left
        if (i % 10 != 9 && !is_no_edge_vertex(i + 1, no_edge_vertices, no_edge_vertices_count)) 
            addUndirectedEdge(G2, i, i + 1); // Right
    }

    BFS(G2, 16);
    // Print the distance variable of vertex 61
    printf("Distance from 16 to 61: %d\n", G2->vertices[61].distance);

    // Print the path from 16 to 61
    printPath(G2, 16, 61);
    printf("\n");

    return 0;
}