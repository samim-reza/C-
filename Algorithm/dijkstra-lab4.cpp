#include <bits/stdc++.h>
using namespace std;

#define V 6

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

void dijkstra(int graph[V][V], int src, int vertexCost[]) {
    int dist[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    dist[src] = vertexCost[src];

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                (dist[u] + graph[u][v] + vertexCost[v]) < dist[v]) {
                dist[v] = dist[u] + graph[u][v] + vertexCost[v];
            }
        }
    }

    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << "\n";
}

int main() {
    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 5},
        {0, 0, 0, 6, 5, 0}};
    
    int vertexCost[V] = {1, 2, 3, 4, 5, 6};

    int src = 0;

    dijkstra(graph, src, vertexCost);

    return 0;
}
