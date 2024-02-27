#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main(){

    // Create graph
    Graph* G2 = createGraph(100);

    // The graph is a 10x10 grid. I want each vertice to have an edge to the vertice above, below, to the left and to the right.
    for (int i = 1; i <= 100; i++) {
        if (i % 10 != 0) {
            addDirectedEdge(G2, i, i + 1);
        }
        if (i % 10 != 1) {
            addDirectedEdge(G2, i, i - 1);
        }
        if (i <= 90) {
            addDirectedEdge(G2, i, i + 10);
        }
        if (i >= 11) {
            addDirectedEdge(G2, i, i - 10);
        }
    }

    BFS(G2, 16);
    // Print the distance variable of vertex 6
    printf("Distance from 16 to 6: %d\n", G2->vertices[6].distance);

    return 0;
}