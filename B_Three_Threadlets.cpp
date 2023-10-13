#include <bits/stdc++.h>
typedef long long ll;
#define Test int t;cin>>t;while(t--)
#define For for(int i=0; i<n; i++)
#define endl "\n"
#define vector vector<int>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Test{
    ll a, b, c;
        cin>>a>>b>>c;
        if(a > b)
            swap(a, b);
        if(a > c)
            swap(a, c);
// cout<<a<<" "<<b<<" "<<c<<endl;
        ll temp = a;
        ll ans = 0;
        bool flag = true;
        while(ans<=3){
            if(temp == b)break;
            if(temp>b){
                flag=false;
                break;
            }
            ans++;
            temp += a;
        }
        temp = a;
        while(ans<=3){
            if(temp == c)break;
             if(temp>c){
                flag=false;
                break;
            }
            ans++;
            temp += a;
        }
        if(ans<=3 && flag){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
