#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct Edge {
    int src, dest, weight;
};


struct Graph {
    int V, E;
    struct Edge* edges;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*) malloc(E * sizeof(struct Edge));
    return graph;
}

void printDistance(int dist[], int n) {
int i;
    printf("Vertex   Distance from Source\n");
    for ( i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}


void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int i,j;
   
    for ( i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
 
    for ( i = 1; i < V; i++) {
        for ( j = 0; j < E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for ( i = 0; i < E; i++) {
        int u = graph->edges[i].src;
        int v = graph->edges[i].dest;
        int weight = graph->edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative-weight cycle\n");
            return;
        }
    }

    printDistance(dist, V);
}


int main() {
    int V, E, src,i;
    
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &V);
    printf("Enter the number of edges in the graph: ");
    scanf("%d", &E);
    struct Graph* graph = createGraph(V, E);
    for ( i = 0; i < E; i++) {
        printf("Enter details of edge %d (source, destination, weight): ", i+1);
        scanf("%d %d %d", &graph->edges[i].src, &graph->edges[i].dest, &graph->edges[i].weight);
    }
    printf("Enter the source vertex: ");
    scanf("%d", &src);


    BellmanFord(graph, src);


    return 0;
}
