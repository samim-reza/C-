#include <bits/stdc++.h>
using namespace std;

int main()
{
    int node,edges;
    cin>>node>>edges;
    vector<int>adj[node+1];
    for(int i=0; i<edges; i++)
    {
        int vertex, nextVertex;
        cin>>vertex>>nextVertex;
        adj[vertex].push_back(nextVertex);
    }
    for(int i=1; i<=node; i++)
    {
        cout<<i<<": ";
        for(int j=0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
         cout<<endl;
    }
}