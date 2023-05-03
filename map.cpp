#include <bits/stdc++.h>
using namespace std;
int main()
{
   int q;
   cin>>q;
   map<string, int>mp;
   while(q--)
   {
        string str;
        int c;
        cin>>c>>str;
        if(c==1)
        {
            int value;
            cin>>value;
            mp[str] += value;
            //mp.insert({str,value});
        }
        else if(c == 2)
        {
            mp[str] = 0;
        }
        else
        {
            cout << mp[str] << endl;
        }
   }
}
