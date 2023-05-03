#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        v[i]=a;;
    }
    sort(v.begin(),v.end());
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }

}
