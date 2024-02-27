#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int main(){

    // Create graph
    Graph* G2 = createGraph(9);

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

    // Find strongly connected components
    printf("Strongly connected components of G2 starting at 2:\n");
    stronglyConnectedComponents(G2, 2);

    printf("\nStrongly connected components of G2 starting at 1:\n");
    stronglyConnectedComponents(G2, 1);

    return 0;
}