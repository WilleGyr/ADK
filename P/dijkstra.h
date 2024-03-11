#define SIZE 150
#define DIRECTIONS 4

typedef struct {
    int vertex;
    int cost;
    int direction;
} PQNode;

typedef struct {
    PQNode nodes[SIZE];
    int size;
} PriorityQueue;

int is_no_edge_vertex(int vertex, int* no_edge_vertices, int no_edge_vertices_count);

Graph* create_graph_from_file(char* filename);

void PQenqueue(PriorityQueue* queue, PQNode node);

PQNode PQdequeue(PriorityQueue* queue);

int PQisEmpty(PriorityQueue* queue);

int getDirection(int current, int next);

void PprintPath(int prev[][DIRECTIONS], int direction[][DIRECTIONS], int vertex, int dir, int size);

void dijkstra(Graph* G, int sourcex, int sourcey, int destinationx, int destinationy);