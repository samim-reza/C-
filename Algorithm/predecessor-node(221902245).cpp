#include <iostream>
#include <climits>
using namespace std;

#define V 6

int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(int dist[], int p[], int n)
{
    cout << "Vertex   Distance from Source (5)   Predecessor\n";
    for (int i = 0; i < V; i++)
    {
        cout << i << "        " << dist[i] << "                 " << p[i] << "\n";
    }
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];  // The output array dist[i] holds the shortest distance from source to destination vertex i
    int p[V];     // The output array p[i] holds the predecessor node along the shortest path from source to destination vertex i
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in the shortest path tree or the shortest distance from the source src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        p[i] = -1; // Initialize predecessor to -1
    }

    // Distance from the source node to itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
        {
            // Update dist[v] only if it is not in the sptSet, there is an edge from u to v,
            // and the total weight of path from source to v through u is less than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                p[v] = u; // Set the predecessor to u
            }
        }
    }

    // Print the constructed distance and predecessor arrays
    printSolution(dist, p, V);
}

int main()
{
    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 5},
        {0, 0, 0, 6, 5, 0}};

    int src = 5; // Source node is 5

    dijkstra(graph, src);

    return 0;
}
