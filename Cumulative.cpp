#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    for(int i=1; i<n; i++)
    {
        v[i]+=v[i-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        if(a==0)
            cout<<v[b]<<endl;
        else
            cout<<v[b]-v[a-1]<<endl;
    }
}
