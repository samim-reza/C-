#include <bits/stdc++.h>
using namespace std;

int main () {
int x=10,y=9;
  vector<int> v;
  v={10,20,30,40,50,60};
  int c= binary_search(v.begin(),v.end(),70);
  //cout<<c;
  auto itr = lower_bound(v.begin(), v.end(), 60) ;
  int index = distance(v.begin(), itr);
  //cout<<index;
  //cout<<v.size();
  swap(x,y);
  cout<<x<<y;
}
