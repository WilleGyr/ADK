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

    // isDirected
    printf("Is G1 directed? %s\n", isDirected(G1) ? "Yes" : "No");
    printf("Is G2 directed? %s\n", isDirected(G2) ? "Yes" : "No");
    printf("\n");

    // getNumVertices and getNumEdges
    printf("G1 has %d vertices and %d edges\n", getNumVertices(G1), getNumEdges(G1));
    printf("G2 has %d vertices and %d edges\n", getNumVertices(G2), getNumEdges(G2));
    printf("\n");

    // getInAdjs
    List* inAdjsG1 = getInAdjs(G1, 9);
    printf("G1 InAdjs for 9: ");
    printList(inAdjsG1);
    List* inAdjsG2 = getInAdjs(G2, 9);
    printf("G2 InAdjs for 9: ");
    printList(inAdjsG2);
    printf("\n");

    // getOutAdjs
    List* outAdjsG1 = getOutAdjs(G1, 9);
    printf("G1 OutAdjs for 9: ");
    printList(outAdjsG1);
    List* outAdjsG2 = getOutAdjs(G2, 9);
    printf("G2 OutAdjs for 9: ");
    printList(outAdjsG2);
    printf("\n");

    // getLinked
    List* linkedG1 = getLinked(G1, 9);
    printf("(G1) Linked to 9: ");
    printList(linkedG1);
    List* linkedG2 = getLinked(G2, 9);
    printf("(G2) Linked to 9: ");
    printList(linkedG2);
    printf("\n");

    // hasEdge
    printf("G1 has edge from 3 to 9? %s\n", hasEdge(G1, 3, 9) ? "Yes" : "No");
    printf("G2 has edge from 3 to 9? %s\n", hasEdge(G2, 3, 9) ? "Yes" : "No");

    return 0;
}