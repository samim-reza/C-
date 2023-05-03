#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        int t;
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
/*int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        mp[t]++;
    }
    for(auto x : mp)
        cout<<x.first<< " " <<x.second<<"\n";
}*/
