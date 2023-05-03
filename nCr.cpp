#include <bits/stdc++.h>
using namespace std;
int factorial(int n)
{
    int c;
    int result = 1;
    for (c = 1; c <= n; c++)
        result = result*c;
    return result;
}

int find_npr(int n, int r)
{
    int result;
    result = factorial(n)/factorial(n-r);
    return result;
}

int find_ncr(int n, int r)
{
    int result;
    result = factorial(n)/(factorial(r)*factorial(n-r));
    return result;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int& i:v)
        {
            cin>>i;
        }
        if(n==9)
            cout<<0<<endl;
        else
        {
            int result=6*find_ncr(10-n,2);
            cout<<result<<endl;
        }
    }
}
