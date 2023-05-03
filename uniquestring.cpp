#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<char>v;
    map<char,int>mp;
    for(int i=0; i<n; i++)
    {
        char t;
        cin>>t;
        if(mp[t]<1)
            v.push_back(t);
        mp[t]++;
    }
        for(int i=0; i<mp.size(); i++)
    {
        cout<<v[i]<<" "<<mp[v[i]]<<"\n";
    }
}
