#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "graph.h"
#include "dijkstra.h"

int main( int argc, char *argv[]){

    // I want to make sure that the user has provided the correct number of arguments, also make sure that the first argument is the filename and the rest are integers
    if (argc != 6) {
        printf("Incorrect argument am\nUsage: %s <filename> <start_x> <start_y> <end_x> <end_y>\n", argv[0]);
        return 1;
    }
    // I want to make sure that the arguments are in the correct format
    for (int i = 2; i < 6; i++) {
        for (int j = 0; j < strlen(argv[i]); j++) {
            if (argv[i][j] < '0' || argv[i][j] > '9') {
                printf("Arguments must be integers\nUsage: %s <filename> <start_x> <start_y> <end_x> <end_y>\n", argv[0]);
                return 1;
            }
        }
    }

    // First argument is the filename
    char *filename = argv[1];

    // Create a graph from the given file
    Graph* G = create_graph_from_file(filename);

    // Print the path with the lowest cost from vertex start to vertex end
    // Source coordinates are (argv[2], argv[3]) and destination coordinates are (argv[4], argv[5])
    dijkstra(G, atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));

    return 0;
}