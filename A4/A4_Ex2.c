#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(){
    // Create two graphs
    Graph* G1 = createGraph(9);
    Graph* G2 = createGraph(9);

    // Add edges to the G1
    addUndirectedEdge(G1, 1, 4);
    addUndirectedEdge(G1, 1, 5);
    addUndirectedEdge(G1, 1, 8);
    addUndirectedEdge(G1, 2, 5);
    addUndirectedEdge(G1, 2, 6);
    addUndirectedEdge(G1, 2, 7);
    addUndirectedEdge(G1, 2, 9);
    addUndirectedEdge(G1, 3, 4);
    addUndirectedEdge(G1, 3, 8);
    addUndirectedEdge(G1, 3, 9);
    addUndirectedEdge(G1, 8, 4);
    addUndirectedEdge(G1, 6, 9);
    addUndirectedEdge(G1, 7, 9);

    // Add edges to the G2
    addDirectedEdge(G2, 1, 4);
    addDirectedEdge(G2, 1, 5);
    addDirectedEdge(G2, 1, 8);
    addDirectedEdge(G2, 8, 1);
    addDirectedEdge(G2, 4, 8);
    addDirectedEdge(G2, 2, 5);
    addDirectedEdge(G2, 2, 9);
    addDirectedEdge(G2, 6, 2);
    addDirectedEdge(G2, 9, 6);
    addDirectedEdge(G2, 7, 2);
    addDirectedEdge(G2, 7, 9);
    addDirectedEdge(G2, 9, 3);
    addDirectedEdge(G2, 3, 4);
    addDirectedEdge(G2, 8, 3);

    // 2
    // birthdate = 031112

    
    // 2.1
    // Source: 2
    BFS(G2, 2);
    printf("G2\n");
    for (int i = 1; i <= G2->numVertices; i++) {
        if (G2->vertices[i].distance != -1) {
            printf("Distance from 2 to %d: %d\n", i, G2->vertices[i].distance);
        } else {
            printf("No path from 2 to %d\n", i);
        }
    }
    
    /*
    // 2.2
    // Source: 1
    BFS(G2, 1);
    printf("\nG2\n");
    for (int i = 1; i <= G2->numVertices; i++) {
        if (G2->vertices[i].distance != -1) {
            printf("Distance from 1 to %d: %d\n", i, G2->vertices[i].distance);
        } else {
            printf("No path from 1 to %d\n", i);
        }
    }
    */


    return 0;
}