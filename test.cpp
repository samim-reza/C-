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
    int n,m,result=0;
    cin>>n>>m;
    string x,s;
    cin>>x>>s;
    bool flag;
    for(int i=0;i<n;i++){
        flag = true;
        ll m = i;
        for(int j=0;j<m;j++){
            if(x[m%n]!=s[j]){
                flag = false;
                break;
            }
            m++;
        }
        if(flag == true) break;
    }
    if(flag==false){
        cout<<-1<<endl;
        continue;
    }


    while(true){
        if(x.find(s) != string::npos){
            cout<<result<<endl;
            break;
        }
        else{
            x=x+x;
            result++;
        }
    }
    }
}
