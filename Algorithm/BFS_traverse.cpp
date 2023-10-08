#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node,edges;
    cin>>node>>edges;

    vector<int>adj[node+1];

    for(int i=0; i<edges; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int vis[node+1] = {0};
    vector<int>bfs(node);
    queue<int>q;

    for(int i=1; i<=node; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            q.push(i);
        }
        for(int j=0; j<adj[i].size(); j++)
        {
            if(!vis[adj[i][j]])
            {
                vis[adj[i][j]] = 1;
                q.push(adj[i][j]);
            }
        }
    }

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}