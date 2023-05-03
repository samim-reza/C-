#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    /*for(int i=0; i<n; i++)
    {
        cin>>v[i];
    }*/

    for(int& i : v) cin>>i;
    //sort(v.begin(), v.end());
    int q;
    cin>>q;
    while(q--)
    {
        int y;
        cin>>y;

        auto lb = lower_bound(v.begin(),v.end(),y);

        if(*lb == y)
        {
            cout << "Yes ";
            cout << lb - v.begin() + 1 << endl;
        }
        else
        {
            cout << "No ";
            cout << lb - v.begin() + 1 << endl;
        }

    }
}
