#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q;
    cin>>q;
    set<int>st;

    while(q--){
        int p, x;
        cin>>p>>x;
        if(p == 1)
        {
            st.insert(x);
        }
        else if(p == 2)
        {

            auto it = st.find(x);
            if(it != st.end())
            {
                st.erase(it);
            }
        }
        else
        {
            if(st.find(x) == st.end())
            {
                cout << "No\n";
            }
            else
            {
                cout << "Yes\n";
            }
        }

    }
     for (auto it : st )
    {
        cout << it <<", ";
    }cout<<endl;

    cout << *st.begin() << endl;
}
