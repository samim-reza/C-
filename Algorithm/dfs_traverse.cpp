#include <bits/stdc++.h>
using namespace std;

int t = 0;
vector<int>adj[100];
vector<string>color(100,"white");
vector<int>pre(100, -1);
vector<int>finish(100, -1);
vector<int>discovery(100, -1);
vector<pair<int,int>>topology;

void DFS_visit(int u)
{
    color[u] = "grey";
    t = t + 1;
    discovery[u] = t;
    for(int i=0; i<adj[u].size(); i++)
    {
        if(color[adj[u][i]] == "white")
        {
            pre[adj[u][i]]=u;
            DFS_visit(adj[u][i]);
        }
    }
        color[u] = "black";
        t = t+1;
        finish[u] = t;
}

int main()
{
    int node,edges;
    cin>>node>>edges;



    for(int i=0; i<edges; i++)
    {
        int vertex, nextVertex;
        cin>>vertex>>nextVertex;
        adj[vertex].push_back(nextVertex);
    }

    for(int i=1; i<=node; i++)
    {
        if(color[i]=="white")
        {
            DFS_visit(i);
        }
    }
    for(int i=0; i<node; i++)
    {
        topology.push_back({finish[i+1],i+1});
    }
    sort(topology.begin(),topology.end(),std::greater<>());
    for(int i=0; i<node; i++)
    {
        cout<<topology[i].second<<" ";
    }
}