#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<int> adj[], int node, int parent, int vis[]) {
    queue<pair<int, int>> q;
    q.push({node, parent});
    vis[node] = 1;

    while (!q.empty()) {
        int currNode = q.front().first;
        int parentNode = q.front().second;
        q.pop();
        
        for (int neighbor : adj[currNode]) {
            
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                
                q.push({neighbor, currNode});
            } else if (neighbor != parentNode) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int node, edges;
    cin >> node >> edges;

    vector<int> adj[node + 1];

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[node + 1] = {0};
    bool hasCycle = false;

    for (int i = 1; i <= node; i++) {
        if (!vis[i]) {
            if (isCycle(adj, i, -1, vis)) {
                hasCycle = true;
                break;
            }
        }
    }

    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }
}
