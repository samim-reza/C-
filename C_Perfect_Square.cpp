#include <bits/stdc++.h>
typedef long long ll;
#define Test int t;cin>>t;while(t--)
#define For for(int i=0; i<n; i++)
#define endl "\n"
#define vector vector<int>
using namespace std;

ll ans, n;

string s[100000];
string s2[100000];
bool visited[10000][10000];

void rec(int i, int j){
    if(s[i][j]<s2[i][j]){
        ans += (s2[i][j]-s[i][j]);

        s2[j][n-i-1]= s2[i][j];
        s[i][j] = s2[i][j];

        if(visited[j][n-i-1]==true){
            rec(j, n-i-1);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Test{
        cin>>n;
        for(int i=0;i<n;i++){
                cin>>s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s2[i][j]= s[n-j-1][i];
                visited[i][j] = false;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<s2[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        //start from here
        ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = true;
                rec(i,j);
                // if(s[i][j]<s2[i][j]){
                    // ans += (s2[i][j]-s[i][j]);

                    // s2[j][n-i-1]= s2[i][j];
                    // s[i][j] = s2[i][j];

                    // if(s[j][n-i-1]<s2[j][n-i-1]){
                    //     ans += (s2[j][n-i-1]-s[j][n-i-1]);

                    //     s2[n-i-1][n-j-1] = s2[j][n-i-1];
                    //     s[j][n-i-1] = s2[j][n-i-1];
                    // }

                    // if(s2[j][n-i-1]<s2[j][n-i-1])
                    // swap(s2[j][n-i-1], s2[i][j]);
                    // for(int i=0;i<n;i++){
                    //     for(int j=0;j<n;j++){
                    //         cout<<s2[i][j]<<" ";
                    //     }
                    //     cout<<endl;
                    // }
                    // cout<<endl<<endl;
                // } 
            }
        }
        cout<<ans<<endl;
        // cout<<endl;
    }
}
