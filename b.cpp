#include <bits/stdc++.h>
typedef long long ll;
#define Test int t;cin>>t;while(t--)
#define For for(int i=0; i<n; i++)
#define endl "\n"
#define vector vector<int>
using namespace std;

void solve(){
ll a, b, c;
        cin>>a>>b>>c;
        if(a > b)
            swap(a, b);
        if(a > c)
            swap(a, c);

        ll temp = a*2;
        ll ans = 1;
        bool flag = true;
        if(b!=a)
        while(ans<=3){
            temp *= 2;
            ans += (ans*2);
            if(temp==b) break;
            if(temp>b){
                flag = false;
                break;
            }
        }
        if(flag == false || ans>3){
            cout<<"No\n";
            return;
        }

        temp = a*2;
        if(c!=a)
        while(ans<=3){
            temp *= 2;
            ans += (ans*2);
            if(temp==c) break;
            if(temp>c){
                flag = false;
                break;
            }
        }
        if(flag == false || ans>3){
            cout<<"No\n";
            return;
        }
        cout<<"YES\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Test{
        solve();
    }
}
