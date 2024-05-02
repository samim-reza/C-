#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 100;
int matrix[MAX_NODES][MAX_NODES];
int que[100], front = 0, back = 0;

int bfs(int source, int destination, int node) {
    vector<bool> visited(node, false);
    vector<int> distance(node, 0);
    
    que[back] = source;
    back++;
    visited[source] = true;

    while (front!=back) {
        int current = que[front];
        front++;

        if (current == destination) {
            return distance[current];
        }

        for (int next = 0; next < node; next++) {
            if (matrix[current][next] == 1 && !visited[next]) {
                visited[next] = true;
                distance[next] = distance[current] + 1;
                que[back] = next;
                back++;
            }
        }
    }
    return -1;
}

int main() {
    int node, edges;
    cin >> node >> edges;

    for (int i = 0; i < edges; i++) {
        int vertex, nextVertex;
        cin >> vertex >> nextVertex;
        matrix[vertex][nextVertex] = matrix[nextVertex][vertex] = 1;
    }
    cout<<"The matrix:\n";
    for(int i=0; i<node; i++)
    {
        for(int j=0; j<node; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Input source and destination:\n";
    int source, destination;
    cin >> source >> destination;

    int distance = bfs(source, destination, node);
    
    if (distance == -1) {
        cout << "Destination is not reachable from the source." << endl;
    } else {
        cout << "The distance from source to destination is: " << distance << endl;
    }

    return 0;
}
