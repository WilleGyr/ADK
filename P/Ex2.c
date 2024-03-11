#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "graph.h"
#include "dijkstra.h"

int main( int argc, char *argv[]){
    // First argument is the filename
    char *filename = argv[1];

    // Create a graph from the given file
    Graph* G = create_graph_from_file(filename);

    // Print the path with the lowest cost from vertex start to vertex end
    // Source coordinates are (argv[2], argv[3]) and destination coordinates are (argv[4], argv[5])
    dijkstra(G, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));

    return 0;
}