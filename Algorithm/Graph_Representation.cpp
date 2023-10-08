#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node,edges;
    cin>>node>>edges;

    vector<int>adj[node+1];
    //vector<pair<int,int>>adj[node+1]; //for weighted graph
    
    for(int i=0; i<edges; i++)
    {
        //connected node u and v
        int u, v; //weight w
        cin>>u>>v;
        adj[u].push_back(v); // for weighted ({v,w})
        adj[v].push_back(u);//for undirected graph
    }
    for(int i=1; i<=node; i++)
    {
        cout<<i<<"->";
        for(auto it: adj[i])
            cout<<it<<" ";
        cout<<endl;
    }
    for(int i=1; i<node+1; i++){
        cout<<adj[i][0]<<" ";
    }
}