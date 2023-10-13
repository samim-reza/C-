#include <vector>
#include <iostream>
using namespace std;
int adj[5][5];


int main() {
    int n , m;
    cin>>n>>m;
    

    for(int i=1; i<=m; i++)
    {
        int u, v;
        cin>>u>>v;
        for(int j=1; j<=n; j++)
        {
            adj[u][v] = 1;
        }
    }
            for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
}