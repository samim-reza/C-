#include <vector>
#include <iostream>
using namespace std;

int first = 0;
int last = 0;
vector<int>que(20,0);
vector<int>adj[0];


void enq(int n)
{
    que[last++]=n;
}

int dq()
{
    return que[first++];
}

int main()
{
    int node,edges;
    cin>>node>>edges;

    vector<string>color(node+1,"white");
    vector<int>pre(node+1, -1);
    vector<int>d(node+1, -1);
    vector<int>bfs;

    for(int i=1; i<=edges; i++)
    {
        adj->push_back(i);
    }
    for(int i=1; i<=edges; i++)
    {
        int vertex, nextVertex;
        cin>>vertex>>nextVertex;
        adj[vertex].push_back(nextVertex);
    }
    int src=1;
    enq(src);
    d[src]=0;
    while(first<last)
    {
        int n=dq();
        bfs.push_back(n);
        for(int i=0; i<adj[n].size(); i++)
        {
            if(color[adj[n][i]]=="white")
            {
                color[adj[n][i]]="grey";
                d[adj[n][i]]=d[n]+1;
                pre[adj[n][i]]=n;
                enq(adj[n][i]);
            }
        }
        color[n]="black";
        
    }
    for(int i=1; i<color.size(); i++)
        cout<<color[i]<<" ";
        cout<<endl;
    for(int i=1; i<pre.size(); i++)
        cout<<pre[i]<<" ";
        cout<<endl;
    for(int i=1; i<d.size(); i++)
        cout<<d[i]<<" ";
        cout<<endl;
    for(int i=0; i<bfs.size(); i++)
        cout<<bfs[i]<<" ";
    
}